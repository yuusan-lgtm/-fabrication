#include <Wire.h>
#include <ST7032.h> //①ライブラリを利用できるようにするための操作である
#define ST7032_ADR 0x7C //②ST7032 の I2C アドレスを指定する
#define TRIG_PIN 8//TRIG_PINを8番に割り当てるために定義している。
#define EHO_PIN 9//EHO_PINを9番に割り当てるために定義している。
#define CTM 10//HIGHの時間（μsec） 
#define led_PIN 6
#define yel_PIN 10
#define green_PIN 11
const int SW_PIN1 = 4;
const int SW_PIN2 = 2;
ST7032 LCD; //ST7032 //制御用のインスタンスを作成し、宣言しておく

//int val = 0;
//int num = 0;
//int input = -1;
int num1;
int num2;
int sum;
int count ;
int select;

void setup() {
  pinMode(TRIG_PIN, HIGH);//送信側のデジタル出力設定
  pinMode(EHO_PIN, INPUT);//受信側のデジタル入力設定
  pinMode( SW_PIN1, INPUT ); //SW_PINを入力設定
  pinMode( SW_PIN2, INPUT ); //SW_PINを入力設定
  Serial.begin(9600);
}
void loop() {
  int dur;
  int dis;
  int dR = digitalRead( SW_PIN1 );
  int dR2 = digitalRead( SW_PIN2 );//dRにSW_PINから読み取った値を代入
  if(dR == HIGH){ //タクトスイッチが押されているとき
     count += 1;//countにタクトスイッチを押すごとにプラス１
      if(count >= 11){//押した回数が６回以上になったらcountを０にする
        count = 0;
      }
 
      if(dR2 == HIGH){ //タクトスイッチが押されているとき
        select += 1;//countにタクトスイッチを押すごとにプラス１
        if(select > 6){
          select = 0;
        }
      }
    }
    switch(count){
      case 1://タクトスイッチが１回押されたとき
        //LCD.setCursor(1, 0); //LCD 表示(1 行目)
        num1 = 10;
        LCD.print(num1);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
      case 2: //タクトスイッチが2回押されたとき
        LCD.setCursor(1, 0); //LCD 表示(1 行目)
        num1 = 20;
        LCD.print(num1);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
      case 3: //タクトスイッチが3回押されたとき
        LCD.setCursor(1, 0); //LCD 表示(1 行目)
        num1 = 30;
        LCD.print(num1);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
      case 4: //タクトスイッチが4回押されたとき
        LCD.setCursor(1, 0); //LCD 表示(1 行目)
        num1 = 40;
        LCD.print(num1);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
      case 5: //タクトスイッチが4回押されたとき
        LCD.setCursor(1, 0); //LCD 表示(1 行目)
        num1 = 50;
        LCD.print(num1);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
      case 6: //タクトスイッチが4回押されたとき
        LCD.setCursor(1, 0); //LCD 表示(1 行目)
        num1 = 60;
        LCD.print(num1);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
      case 7: //タクトスイッチが4回押されたとき
        LCD.setCursor(1, 0); //LCD 表示(1 行目)
        num1 = 70;
        LCD.print(num1);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
      case 8: //タクトスイッチが4回押されたとき
        LCD.setCursor(1, 0); //LCD 表示(1 行目)
        num1 = 80;
        LCD.print(num1);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
      case 9: //タクトスイッチが4回押されたとき
        LCD.setCursor(1, 0); //LCD 表示(1 行目)
        num1 = 90;
        LCD.print(num1);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
      case 10: //タクトスイッチが4回押されたとき
        LCD.setCursor(0, 0); //LCD 表示(1 行目)
        num1 = 100;
        LCD.print(num1);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
    }

    switch(select){
      case 1://タクトスイッチが１回押されたとき
        LCD.setCursor(0, 0); //LCD 表示(1 行目)
        num2 = 0;
        sum = num1 + num2;
        LCD.print(sum);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
      case 2://タクトスイッチが１回押されたとき
        LCD.setCursor(0, 0); //LCD 表示(1 行目)
        num2 = 100;
        sum = num1 + num2;
        LCD.print(sum);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
      case 3: //タクトスイッチが2回押されたとき
        LCD.setCursor(0, 0); //LCD 表示(1 行目)
        num2 = 200;
        sum = num1 + num2;
        LCD.print(sum);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
      case 4: //タクトスイッチが3回押されたとき
        LCD.setCursor(0, 0); //LCD 表示(1 行目)
        num2 = 300;
        sum = num1 + num2;
        LCD.print(sum);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
      case 5: //タクトスイッチが4回押されたとき
        LCD.setCursor(0, 0); //LCD 表示(1 行目)
        num2 = 400;
        sum = num1 + num2;
        LCD.print(sum);
        LCD.setCursor(3, 0); //LCD 表示(1 行目)
        LCD.print("cm");
        delay(10);
        break;
    }

  



  LCD.begin(8, 2); //(桁, 行)を表し、LCD の表示領域設定を行う
  LCD.setContrast(10); //③(0〜63)の範囲で LCD のコントラスト設定を行う
  //LCD.setCursor(0, 0); //LCD 表示(1 行目)
  //LCD.print(Serial.available()); //()内に表示させる文字を設定する
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(CTM);
  digitalWrite(TRIG_PIN, LOW);
  dur = pulseIn(EHO_PIN, HIGH);//超音波が物体にあたり戻ってくる時間の計測
  dis = dur * 0.017;//物体までの距離計算
  if(sum == dis){
    analogWrite(green_PIN , 255);
    analogWrite(yel_PIN , 0);
    analogWrite(led_PIN , 0);
  }else if(sum < dis){
    analogWrite(yel_PIN , 255);
    analogWrite(green_PIN , 0);
    analogWrite(led_PIN , 0);
  }else{
    analogWrite(led_PIN , 255);
    analogWrite(green_PIN , 0);
    analogWrite(yel_PIN , 0);
  }
  LCD.setContrast(10);//超音波距離センサから物体までの距離を表示
  LCD.setCursor(3, 1); //LCD 表示(1 行目)
  LCD.print(dis);
  LCD.setCursor(6, 1); //LCD 表示(1 行目)
  LCD.print("cm");
  delay(200);
}
