// OLEDディスプレイに文字を表示するサンプル
// 文字を1秒ごとにカウントアップさせるプログラム
// Adafruit GFX Library, Adafruit BusIO, Adafruit SSD1306 をインストールする必要があります。
//
// ref. https://kenchi-blog.com/oled-lcd-display-ssd1306-arduino/
// ref. https://garchiving.com/how-to-use-oled-with-arduino/

#include <Arduino.h>
#include <SoftwareSerial.h>
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED 幅
#define SCREEN_HEIGHT 64  // OLED 高さ
#define OLED_RESET -1     // リセット端子（未使用-1）

// インスタンス作成
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int n = 0;

void setup() {
    // ディスプレイの初期化
    // 0x3C は OLED デバイスアドレス
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    display.clearDisplay();
    display.display();

    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(25, 28);
    display.print("Hello, world!");
    display.display();
}

void loop() {
    delay(1000);
    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(15, 28);
    display.printf("count: %d", n);
    display.display();

    n++;
}
