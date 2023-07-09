#include "DHT.h"
#include <Wire.h>
#include <RTClib.h>
#define DHTTYPE DHT22
#define DHTPIN  22
#include <LiquidCrystal.h>
#include <DS1307RTC.h>
#include <Time.h>
#include <SoftwareSerial.h>


SoftwareSerial espSerial(30,31);
String str;
DHT dht(DHTPIN,DHTTYPE);
const int rs1 = 12, en1 = 11, d41 = 5, d51 = 4, d61 = 3, d71 = 2;
const int rs2 = 13, en2 = 10, d42 = 9, d52 = 8, d62 = 7, d72 = 6;
LiquidCrystal lcd1(rs1, en1, d41, d51, d61, d71);
LiquidCrystal lcd2(rs2, en2, d42, d52, d62, d72);



void setup(){

  Serial.begin(115200);
  espSerial.begin(115200);
  
  dht.begin();
  lcd1.begin(16,2);
  lcd2.begin(16,2);
  lcd2.print("This is a Clock");
  delay(1000);
  lcd2.clear();
}
void loop(){

int temp = dht.readTemperature();
int hum = dht.readHumidity();

  lcd1.clear();
  lcd1.setCursor(0,0);
  lcd1.print("Temp: ");
  lcd1.print(temp);
  lcd1.print("*C");
  lcd1.setCursor(0,1);
  lcd1.print("Humidity: ");
  lcd1.print(hum);
  lcd1.print("%");

  tmElements_t tm;
   // 读出DS1307中的时间数据，并存入tm中
   if (RTC.read(tm))
   {
     // 清除屏幕显示内容
     lcd2.clear();
     //在LCD第一行输出日期信息
     lcd2.setCursor(0, 0);
     lcd2.print(tmYearToCalendar(tm.Year));
     lcd2.print("-");
     lcd2.print(tm.Month);
     lcd2.print("-");
     lcd2.print(tm.Day);
     //在LCD第二行输出时间信息
     lcd2.setCursor(8, 1);
     lcd2.print(tm.Hour);
     lcd2.print(":");
     lcd2.print(tm.Minute);
     lcd2.print(":");
     lcd2.print(tm.Second);
     delay(500);
   }
// 如果读取数据失败，则输出错误提示
else
   {
     lcd2.setCursor(0, 1);
     lcd2.print("error");
   }
   //每秒钟更新一次显示内容
   delay(500);
 

  
  
  lcd1.clear();
  lcd1.setCursor(0,0);
  lcd1.print("Hello World!");

  //tmElements_t tm;
   // 读出DS1307中的时间数据，并存入tm中
   if (RTC.read(tm))
   {
     // 清除屏幕显示内容
     lcd2.clear();
     //在LCD第一行输出日期信息
     lcd2.setCursor(0, 0);
     lcd2.print(tmYearToCalendar(tm.Year));
     lcd2.print("-");
     lcd2.print(tm.Month);
     lcd2.print("-");
     lcd2.print(tm.Day);
     //在LCD第二行输出时间信息
     lcd2.setCursor(8, 1);
     lcd2.print(tm.Hour);
     lcd2.print(":");
     lcd2.print(tm.Minute);
     lcd2.print(":");
     lcd2.print(tm.Second);
     delay(500);
   }
// 如果读取数据失败，则输出错误提示
else
   {
     lcd2.setCursor(0, 1);
     lcd2.print("error");
   }
   //每秒钟更新一次显示内容
   delay(500);
  //delay(2000);

  lcd1.clear();
  lcd1.setCursor(0,1);
  lcd1.print("Erzhuang Gao");

  //tmElements_t tm;
   // 读出DS1307中的时间数据，并存入tm中
   if (RTC.read(tm))
   {
     // 清除屏幕显示内容
     lcd2.clear();
     //在LCD第一行输出日期信息
     lcd2.setCursor(0, 0);
     lcd2.print(tmYearToCalendar(tm.Year));
     lcd2.print("-");
     lcd2.print(tm.Month);
     lcd2.print("-");
     lcd2.print(tm.Day);
     //在LCD第二行输出时间信息
     lcd2.setCursor(8, 1);
     lcd2.print(tm.Hour);
     lcd2.print(":");
     lcd2.print(tm.Minute);
     lcd2.print(":");
     lcd2.print(tm.Second);
     delay(500);
   }
// 如果读取数据失败，则输出错误提示
else
   {
     lcd2.setCursor(0, 1);
     lcd2.print("error");
   }
   //每秒钟更新一次显示内容
   delay(500);
  //delay(2000);

  //tmElements_t tm;
   // 读出DS1307中的时间数据，并存入tm中
   if (RTC.read(tm))
   {
     // 清除屏幕显示内容
     lcd2.clear();
     //在LCD第一行输出日期信息
     lcd2.setCursor(0, 0);
     lcd2.print(tmYearToCalendar(tm.Year));
     lcd2.print("-");
     lcd2.print(tm.Month);
     lcd2.print("-");
     lcd2.print(tm.Day);
     //在LCD第二行输出时间信息
     lcd2.setCursor(8, 1);
     lcd2.print(tm.Hour);
     lcd2.print(":");
     lcd2.print(tm.Minute);
     lcd2.print(":");
     lcd2.print(tm.Second);
     delay(500);
   }
// 如果读取数据失败，则输出错误提示
else
   {
     lcd2.setCursor(0, 1);
     lcd2.print("error");
   }
   //每秒钟更新一次显示内容
   delay(500);

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println("*C");
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println("%");

  str = String("Coming from Arduino: ") + String("Temp: ") + String(temp) + String("*C") + String(" ") + String("Humidity: ") + String(hum) + String("%")+ String("  ") 
       + tmYearToCalendar(tm.Year) + String("-") + tm.Month + String("-") + tm.Day + String(" ") + tm.Hour + String("-") + tm.Minute + String("-") + tm.Second;
  espSerial.println(str);
  delay(1);
     
}
