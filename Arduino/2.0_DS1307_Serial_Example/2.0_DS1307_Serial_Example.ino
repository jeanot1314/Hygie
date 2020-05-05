#include "RTCDS1307.h"

RTCDS1307 rtc(0x68);

uint8_t year, month, weekday, day, hour, minute, second;
bool period = 0;

String m[12] = {"January", "February", "March", "April", "Mai", "June", "July", "August", "September", "October", "November", "December"};
String w[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

void setup()
{
  Serial.begin(9600);
  rtc.begin();
  rtc.setDate(20, 4, 20);
  rtc.setTime(22, 41, 22);
}

void loop()
{
  rtc.getDate(year, month, day, weekday);
  rtc.getTime(hour, minute, second, period);
  //if (!(second % 3)) rtc.setMode(1 - rtc.getMode());
  rtc.getTime(hour, minute, second, period);

  Serial.print(w[weekday - 1]);
  Serial.print("  ");
  Serial.print(day, DEC);
  Serial.print("/");
  Serial.print(m[month - 1]);
  Serial.print("/");
  Serial.print(year + 2000, DEC);
  Serial.print("  ");
  Serial.print(hour, DEC);
  Serial.print(":");
  Serial.print(minute, DEC);
  Serial.print(":");
  Serial.print(second, DEC);
  Serial.print(rtc.getMode() ? (period ? " PM" : " AM") : "");
  Serial.println();
  delay(1000);
}
