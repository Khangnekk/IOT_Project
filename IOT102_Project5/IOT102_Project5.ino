

#include <LiquidCrystal.h>

// LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
LiquidCrystal lcd_1(9, 8, 7, 6, 11, 4);

int realHours = 07, setHours = 0;
int realMinute = 00, setMinute = 0;
int realSecond = 0, setSecond = 0;

int giaodien = 0, st, time;


void setup()
{
    pinMode(10, OUTPUT);
    pinMode(3, INPUT_PULLUP);
    pinMode(2, INPUT_PULLUP);

    lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
}
void clearScreen()
{
    lcd_1.setCursor(0, 0);
    lcd_1.print("                ");
    lcd_1.setCursor(0, 1);
    lcd_1.print("                ");
}

void loop()
{
    Mode();
    alarm();
    switch (giaodien)
    {
    case 0:
        giaodien0();
        break;
    case 1:
        giaodien1();
        break;
    case 2:
        giaodien2();
        break;
    case 3:
        giaodien3();
        break;
    case 4:
        giaodien4();
        break;
    }
}

void Mode()
{
    int x = digitalRead(3);
    if (x == 0)
    {
        st = 1;
    }
    if (st == 1 && x == 1)
    {
        giaodien++;
        clearScreen();
        st = 0;
        if (giaodien > 4)
            giaodien = 0;
    }
}

void alarm()
{
    if (realHours == setHours && realMinute == setMinute && realSecond == setSecond)
    {
        tittit();
    }
}

void tittit()
{
    digitalWrite(10, 1);
    delay(100);
    digitalWrite(10, 0);
    delay(100);
    digitalWrite(10, 1);
    delay(100);
    digitalWrite(10, 0);
}
// Hien thi thoi gian thuc va thoi gian cai dat
void giaodien0()
{
    processTime();
    // row 1
    lcd_1.setCursor(0, 0);
    lcd_1.print("Time: ");
    lcd_1.setCursor(6, 0);
    if (realHours < 10)
    {
        lcd_1.print("0");
        lcd_1.print(realHours);
    }
    else
    {
        lcd_1.print(realHours);
    }

    lcd_1.setCursor(8, 0);
    lcd_1.print(":");
    lcd_1.setCursor(9, 0);
    if (realMinute < 10)
    {
        lcd_1.print("0");
        lcd_1.print(realMinute);
    }
    else
    {
        lcd_1.print(realMinute);
    }

    lcd_1.print(":");
    lcd_1.setCursor(12, 0);
    if (realSecond < 10)
    {
        lcd_1.print("0");
        lcd_1.print(realSecond);
    }
    else
    {
        lcd_1.print(realSecond);
    }

    // row 2
    lcd_1.setCursor(0, 1);
    lcd_1.print("Set: ");
    lcd_1.setCursor(6, 1);
    if (setHours < 10)
    {
        lcd_1.print(0);
        lcd_1.print(setHours);
    }
    else
    {
        lcd_1.print(setHours);
    }
    lcd_1.setCursor(8, 1);
    lcd_1.print(":");
    lcd_1.setCursor(9, 1);
    if (setMinute < 10)
    {
        lcd_1.print("0");
        lcd_1.print(setMinute);
    }
    else
    {
        lcd_1.print(setMinute);
    }

    lcd_1.print(":");
    lcd_1.setCursor(12, 1);
    if (setSecond < 10)
    {
        lcd_1.print("0");
        lcd_1.print(setSecond);
    }
    else
    {
        lcd_1.print(setSecond);
    }
}

void processTime()
{
    if ((int)(millis() - time) > 1000)
    {
        realSecond++;
        // cập nhật lại biến time
        time = millis();
    }

    if (realSecond == 60)
    {
        realSecond = 0;
        realMinute++;
    }
    if (realMinute == 60)
    {
        realMinute = 0;
        realHours++;
    }
    if (realHours == 24)
    {
        realHours = 0;
    }
}

// Cai dat gio
void giaodien1()
{
    int y = digitalRead(2);
    if (y == 0)
    {
        delay(200);
        setHours++;
        if (setHours > 23)
            setHours = 0;
            
    }

    lcd_1.setCursor(0, 0);
    lcd_1.print("Set Hours: ");

    lcd_1.setCursor(4, 1);
    if (setHours < 10)
    {
        lcd_1.print("0");
        lcd_1.print(setHours);
    }
    else
    {
        lcd_1.print(setHours);
    }
    lcd_1.setCursor(7, 1);
    lcd_1.print("hours");
}

// Cai dat phut
void giaodien2()
{
    int y = digitalRead(2);
    if (y == 0)
    {
        delay(200);
        setMinute++;
        if (setMinute > 59)
            setMinute = 0;
        
    }

    lcd_1.setCursor(0, 0);
    lcd_1.print("Set Minute: ");
    lcd_1.setCursor(4, 1);
    if (setMinute < 10)
    {
        lcd_1.print("0");
        lcd_1.print(setMinute);
    }
    else
    {
        lcd_1.print(setMinute);
    }
    lcd_1.setCursor(7, 1);
    lcd_1.print("minutes");
}
// Cai dat giay
void giaodien3()
{
    int y = digitalRead(2);
    if (y == 0)
    {
        delay(200);
        setSecond++;
        if (setSecond > 59)
            setSecond = 0;
        
    }

    lcd_1.setCursor(0, 0);
    lcd_1.print("Set Second: ");
    lcd_1.setCursor(4, 1);
    if (setSecond < 10)
    {
        lcd_1.print("0");
        lcd_1.print(setSecond);
    }
    else
    {
        lcd_1.print(setSecond);
    }
    lcd_1.setCursor(7, 1);
    lcd_1.print("seconds");
}
// Hien ten va mssv
void giaodien4()
{
    lcd_1.setCursor(0, 0);
    lcd_1.print("Name: Khang <3");
    lcd_1.setCursor(0, 1);
    lcd_1.print("MSSV: HE161660");
}
