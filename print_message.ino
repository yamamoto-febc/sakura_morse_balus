
void printInitMessage(String keyword){
  Serial.print("Ready. Please input a magical spell `");
  Serial.print(keyword);
  Serial.println("` by morse code.");
}

void printInputedMorseCode(int bufIndex , String inputedMorseCode){
  Serial.print("Inputed morse code at [");
  Serial.print(bufIndex+1);
  Serial.print("]:");
  Serial.println(inputedMorseCode);
  Serial.println("");  
}

void printWrongInputMessage(){
  Serial.println("A magical spell is wrong. Please retry.");
  Serial.println("");
}

void printOKInputMessage(String keyword){
  Serial.println("");
  Serial.println("============================");
  Serial.print("     [ Casted `");
  Serial.print(keyword);
  Serial.println("` ]     ");
  Serial.println("============================");
  Serial.println("");
}

