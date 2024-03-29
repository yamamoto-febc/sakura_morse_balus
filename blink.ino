#include "constants.h"

void blinkLED(int mode){
  if (mode == BLINK_INIT) {
      digitalWrite(LED1,HIGH);
      delay(125);
      digitalWrite(LED1,LOW);

      digitalWrite(LED2,HIGH);
      delay(125);
      digitalWrite(LED2,LOW);

      digitalWrite(LED3,HIGH);
      delay(125);
      digitalWrite(LED3,LOW);

      digitalWrite(LED4,HIGH);
      delay(125);
      digitalWrite(LED4,LOW);

      digitalWrite(LED5,HIGH);
      delay(125);
      digitalWrite(LED5,LOW);
      
      delay(500);

      for( int i = 0;i < 3;i++){
        digitalWrite(LED_STATUS,HIGH);
        delay(300);
        digitalWrite(LED_STATUS,LOW);
        delay(300);
      }
      
  } else if (mode == BLINK_WAIT_SAKURAIO) {
      digitalWrite(LED_STATUS, HIGH);
      delay(500);
      digitalWrite(LED_STATUS, LOW);
      delay(500);
  } else if (mode == BLINK_TIMER_RESET) {
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,LOW);
      digitalWrite(LED5,LOW);

      digitalWrite(LED1,HIGH);
      delay(75);
      digitalWrite(LED1,LOW);

      digitalWrite(LED2,HIGH);
      delay(75);
      digitalWrite(LED2,LOW);

      digitalWrite(LED3,HIGH);
      delay(75);
      digitalWrite(LED3,LOW);

      digitalWrite(LED4,HIGH);
      delay(75);
      digitalWrite(LED4,LOW);

      digitalWrite(LED5,HIGH);
      delay(75);
      digitalWrite(LED5,LOW);


  } else if (mode == BLINK_NOT_CASTED) {

      for(int i = 0;i < 3;i++){
        digitalWrite(LED1,HIGH);
        digitalWrite(LED2,HIGH);
        digitalWrite(LED3,HIGH);
        digitalWrite(LED4,HIGH);
        digitalWrite(LED5,HIGH);
        delay(200);
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        digitalWrite(LED3,LOW);
        digitalWrite(LED4,LOW);
        digitalWrite(LED5,LOW);
        delay(200);
      }

  } else if (mode == BLINK_CASTED) {
      
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
      digitalWrite(LED4,LOW);
      digitalWrite(LED5,LOW);
      
      int pinBlinkStory[] = {LED1,LED2,LED3,LED4,LED5,LED4,LED3,LED2};
      int len = sizeof(pinBlinkStory) / sizeof(pinBlinkStory[0]);

      for(int i = 0;i < 3;i++){
        for (int j = 0;j < len;j++){
          digitalWrite(pinBlinkStory[j],HIGH);
          delay(75);
          digitalWrite(pinBlinkStory[j],LOW);      
        }
      }
  } else if (mode == BLINK_WAITING_RESPONSE) {
      for(int i = 0;i < 4;i++){
        digitalWrite(LED1,HIGH);
        digitalWrite(LED_STATUS,HIGH);
        delay(500);
        digitalWrite(LED1,LOW);
        digitalWrite(LED_STATUS,LOW);
        delay(500);
      }
  } else if (mode == BLINK_NORMAL_END) {
      for(int i = 0;i < 10;i++){
        digitalWrite(LED1,HIGH);
        delay(100);
        digitalWrite(LED1,LOW);
        digitalWrite(LED_STATUS,HIGH);
        delay(100);
        digitalWrite(LED_STATUS,LOW);
      }      
      int pinBlinkStory[] = {LED1,LED2,LED3,LED4,LED5,LED4,LED3,LED2};
      int len = sizeof(pinBlinkStory) / sizeof(pinBlinkStory[0]);
      for(int i = 0;i < 5;i++){
        for (int j = 0;j < len;j++){
          digitalWrite(pinBlinkStory[j],HIGH);
          delay(50);
          digitalWrite(pinBlinkStory[j],LOW);      
        }
      }
  } else if (mode == BLINK_ERROR_END) {
      for(int i = 0;i < 5;i++){
        digitalWrite(LED5,HIGH);
        delay(3000);
        digitalWrite(LED5,LOW);
        delay(1000);
      }
  }
}
