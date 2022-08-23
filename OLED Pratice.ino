/*
 * 本範程式為Arduino結合1.3吋OLED的範例程式，由傑森創工提供
 * 本程式由wonho-maker改寫的Adafruit函式庫範例進行簡化，若需要進一步學習，建議參考sh1306_128x64_i2c範例
 * 
 * 1，請先安裝Adafruit GFX Library函式庫，可由Arduino IDE裡的「程式管理員」進行安裝
 * 2，請先安裝wonho-maker SH1306函式庫，下載網址：
 *    https://github.com/wonho-maker/Adafruit_SH1106
 * 
 * 粉絲團：https://www.facebook.com/jasonshow
 * 傑森創工購物網：https://www.jmaker.com.tw/
 * 傑森創工部落格：https://blog.jmaker.com.tw/
 */

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

// 設定OLED
#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);

//自訂圖形，從Image2LCD轉過來的，尺寸是128x48
//本範例為了在上方區塊顯示文字，所以圖形就沒有涵蓋整個高度
static const unsigned char PROGMEM logo_bmp[] =
{  };

#if (SH1106_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SH1106.h!");
#endif

void setup()   {                
  Serial.begin(9600);

  
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // 一般1306 OLED的位址都是0x3C

  // 顯示Adafruit的LOGO，算是開機畫面
  display.display();
  delay(1000); // 停1秒

  // 清除畫面
  display.clearDisplay();

  // 測試文字
  display.clearDisplay();
  display.setTextSize(2);             // 設定文字大小
  display.setTextColor(1);        // 1:OLED預設的顏色(這個會依該OLED的顏色來決定)
  display.setCursor(0,0);             // 設定起始座標
  display.print("Hello OLED");        // 要顯示的字串
  display.display();                  // 要有這行才會把文字顯示出來
  delay(1000);
  
  //display.clearDisplay();
  //顯示圖形，x,y,圖形文字,寬,高,1:OLED預設的顏色(這個會依該OLED的顏色來決定)
  display.drawBitmap(0,16,logo_bmp, 128, 48, 1);
  display.display();  // 要有這行才會把文字顯示出來
  delay(1000);
}


void loop() {
  
}
