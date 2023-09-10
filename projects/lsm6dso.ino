// 加速度センサ LSM6DSO の結果をシリアルコンソールに出力するサンプル
//
// https://github.com/stm32duino/LSM6DSO をAruino IDE のライブラリマネージャからインストールする必要があります。
// https://github.com/stm32duino/LSM6DSO/releases から最新版のzipをダウンロードした後、
// `スケッチ > ライブラリをインクルード > .ZIP形式のライブラリをインストール` からインストールします。
//
// ref. https://github.com/stm32duino/LSM6DSO/issues/8
// ref. https://github.com/stm32duino/X-NUCLEO-IKS01A3/blob/main/examples/X_NUCLEO_IKS01A3_HelloWorld/X_NUCLEO_IKS01A3_HelloWorld.ino

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <LSM6DSOSensor.h>

#define CS_PIN  D3

// インスタンス作成
LSM6DSOSensor AccGyr(&SPI, CS_PIN);

void setup() {
    Serial.begin(9600);
    SPI.begin();

    AccGyr.begin();
    AccGyr.Enable_X();
    AccGyr.Enable_G();
}

void loop() {
    int32_t accelerometer[3];
    int32_t gyroscope[3];
    AccGyr.Get_X_Axes(accelerometer);
    AccGyr.Get_G_Axes(gyroscope);

    Serial.printf("accelerometer: (%d, %d, %d)\tgyroscope: (%d, %d, %d)\n", accelerometer[0], accelerometer[1], accelerometer[2], gyroscope[0], gyroscope[1], gyroscope[2]);

    delay(10);
}
