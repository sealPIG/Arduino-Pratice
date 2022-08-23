// 修改自7-13頁「動手做7-2」的序列連接七段顯示器程式

const byte dataPin = 2;    // 74HC595 序列腳接「數位 2」
const byte latchPin = 3;   // 74HC595 暫存器時脈腳接「數位 3」
const byte clockPin = 4;   // 74HC595 序列時脈腳接「數位 4」
byte index = 0;            // 七段顯示器的數字索引

const byte LED_A[10] = {  // 記錄0~9的七段數字
  B01111110,
  B00110000,
  B01101101,
  B01111001,
  B00110011,
  B01011011,
  B01011111,
  B01110000,
  B01111111,
  B01110011
};

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void ShowUp(short int key){
  digitalWrite(latchPin, LOW);   // 關上閘門
  // 再推入「陣列A」
  shiftOut(dataPin, clockPin, LSBFIRST, LED_A[key]);
  digitalWrite(latchPin, HIGH);  // 開啟閘門
}

void loop() {
  ShowUp(2);
}
