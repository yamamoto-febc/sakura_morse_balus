#include "constants.h"
#include "morse_code.h"

// モールス信号で入力するキーワード
String magicalSpell = "balus"; // [ lsss , sl , slss , ssl , sss]
const byte spellLen = 5;

// モールス信号入力用バッファ
String inputBuf[spellLen];
// バッファの現在位置
byte bufIndex = 0;

// タイマー(スイッチON開始時刻、スイッチOFF開始時刻、最終操作時刻)
unsigned long startTime , endTime , silentTime;

// モールス信号での文字入力ごとに点灯させるLEDの配列
int LEDs[] = {LED1,LED2,LED3,LED4,LED5};

// 文字区切り連続入力防止用
bool isSpacePushed = false;

// -------------------------------------------------------------------

void setup(){

  Serial.begin(9600);

  // Arduino各ピンの入出力モード設定
  setupPinMode();

  // 初期化完了をシリアル出力でお知らせ
  printInitMessage(magicalSpell);

  // 初期化完了をLEDでお知らせ
  blinkLED(BLINK_INIT);

}

void loop(){

  // 無操作になって一定時間経過したら文字の区切りとする
  if (isMorseSilent()){
    Serial.println("space");
    pushMorse(CODE_SILENT);
    isSpacePushed = true;
  }

  if (digitalRead(SW) == SW_ON){     // タクトスイッチが押されている
    digitalWrite(LED_STATUS , HIGH); 
    if (startTime == 0) {
      startTime = millis(); // スイッチONにした時刻
      silentTime = 0;
      isSpacePushed = false;
    }
  }else{                            // タクトスイッチを離した
    digitalWrite(LED_STATUS , LOW);
    if (startTime > 0 && endTime == 0) {
      endTime = millis(); // スイッチをOFFにした時刻
      isSpacePushed = false;
    }
  }

  // タクトスイッチのON/OFF両方の時刻から信号の長短(ツー/トン)を判定
  if (startTime > 0 && endTime > 0){
    if ( isMorseShort() ){      // short(トン)か？

      // 入力バッファへプッシュ
      Serial.println("short");
      pushMorse(CODE_SHORT);
      
    }else if ( isMorseLong() ){ // long(ツー)か？

      // 入力バッファへプッシュ
      Serial.println("long");
      pushMorse(CODE_LONG);
    }

    //判定したら時刻をクリア & 
    resetStartTime(); 

    // 無操作時間の開始時刻を保持しておく
    silentTime = millis();
  }

  // 無操作時間が閾値(RESET_DUR)を超えたら、それまでの入力をリセット
  if (silentTime > 0){
    if ( millis() - silentTime > RESET_DUR) {
      resetAll();
      blinkLED(BLINK_TIMER_RESET);
    }
  }


}

void setupPinMode(){
  pinMode(LED1 , OUTPUT);
  pinMode(LED2 , OUTPUT);
  pinMode(LED3 , OUTPUT);
  pinMode(LED4 , OUTPUT);
  pinMode(LED5 , OUTPUT);
  pinMode(LED_STATUS , OUTPUT);
  pinMode(SW , INPUT_PULLUP);  
}

void initVariables(){
  startTime = 0;
  endTime = 0;
  silentTime = 0;
  resetInputBuf();
}

void resetStartTime(){
  startTime = 0;
  endTime = 0;
}

void resetInputBuf(){
  for(int i = 0;i < spellLen;i++){
    inputBuf[i] = "";
  }
  bufIndex = 0;
}

void resetAll(){
  resetStartTime();
  silentTime = 0;
  resetInputBuf();
  isSpacePushed = false;
}

bool isMorseShort(){
  return (MORSE_SHORT_MIN <= (endTime - startTime)) && ((endTime - startTime) <= MORSE_SHORT_MAX);
}

bool isMorseLong(){
  return (MORSE_LONG_MIN <= (endTime - startTime)) && ((endTime - startTime) <= MORSE_LONG_MAX);
}

bool isMorseSilent(){
  return !isSpacePushed && startTime == 0 && silentTime > 0 && MORSE_LONG_DUR <= (millis() - silentTime);
}

void pushMorse(String code){
  
  if (code.equals(CODE_SHORT)){
    inputBuf[bufIndex].concat(CODE_SHORT);
  }else if (code.equals(CODE_LONG)){
    inputBuf[bufIndex].concat(CODE_LONG);    
  }else if (code.equals(CODE_SILENT)){

    // 単語区切りを受信した。キーワードの文字数までは１文字づつ正答確認を行う。    
    if (bufIndex < magicalSpell.length()-1){
      // 入力されたモールス信号(1文字分)をシリアル出力
      printInputedMorseCode(bufIndex, inputBuf[bufIndex]);
      
      if (isInputMorseOK(bufIndex)) {   // 正しい(キーワードと合致した)モールス信号が入力されたか？
        digitalWrite(LEDs[bufIndex] , HIGH);
        bufIndex++;
      }else{
        // 間違ったコードが入力されたため、メッセージを表示して入力リセット
        printWrongInputMessage();
        
        resetAll();
        blinkLED(BLINK_NOT_CASTED);
        return;
      }
      
    }else{

      // === 入力信号が「バルス」だった場合の処理 ===

      // 入力OKメッセージをシリアル出力
      printOKInputMessage(magicalSpell);
      
      blinkLED(BLINK_CASTED);
    
      // TODO [ここにさくらの通信モジュールでのリクエスト処理を書く]
    }
  }
}

// 指定の入力バッファ位置にあるモールス信号がキーワードと合致しているか
bool isInputMorseOK(int bufIndex){
  String strChar = decodeMorse(inputBuf[bufIndex]);// 入力されたモールス信号を復号
  return (magicalSpell.indexOf(strChar) == bufIndex);
}

// 入力されたモールス信号(1文字分)を受け取り、対応する文字を返す
String decodeMorse(String strMorseCode){
  
  int len = sizeof(charCodeList) / sizeof(charCodeList[0]);
  for (int i = 0;i < len;i++){
    if (strMorseCode.equals(charCodeList[i])){
      return charList[i];
    }
  }
  return "missing";
}

