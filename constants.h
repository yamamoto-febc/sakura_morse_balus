// PINs 
#define LED1 2
#define LED2 4
#define LED3 6
#define LED4 8
#define LED5 10
#define LED_STATUS 11
#define SW 13

// Switch ON/OFF
#define SW_ON 0
#define SW_OFF 1

// Blink LED mode
#define BLINK_INIT 1
#define BLINK_WAIT_SAKURAIO 2
#define BLINK_NOT_CASTED 3
#define BLINK_CASTED 4
#define BLINK_TIMER_RESET 5
#define BLINK_WAITING_RESPONSE 6
#define BLINK_NORMAL_END 7
#define BLINK_ERROR_END 8

// morse code rate 
#define MORSE_SHORT_DUR 150
#define MORSE_LONG_DUR MORSE_SHORT_DUR*3
#define MORSE_ADJUSTMENT_DUR 100

#define MORSE_SHORT_MIN MORSE_SHORT_DUR - MORSE_ADJUSTMENT_DUR
#define MORSE_SHORT_MAX MORSE_SHORT_DUR + MORSE_ADJUSTMENT_DUR
#define MORSE_LONG_MIN MORSE_LONG_DUR - MORSE_ADJUSTMENT_DUR
#define MORSE_LONG_MAX MORSE_LONG_DUR + MORSE_ADJUSTMENT_DUR

#define RESET_DUR 3000

// さくらのIoT Platformとのやりとりに使うチャンネル
#define SAKURA_IOT_CHANNEL 0

// さくらのIoT Platformにてやりとりする値
#define SAKURA_IOT_START_CODE 0   // 処理開始
#define SAKURA_IOT_END_CODE 1     // 正常終了
#define SAKURA_IOT_ERROR_CODE 2   // 異常終了
