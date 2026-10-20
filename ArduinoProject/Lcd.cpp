#include "Lcd.h"
#include "Macro.h"

Lcd::Lcd()
  : lcd(0x27, 20, 4)
{

}

void Lcd::begin()
{
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void Lcd::showHeader(uint8_t bank)
{
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("BANK ");
  lcd.print(bank);

  lcd.setCursor(0, 1);
  lcd.print("--------------------");
}

void Lcd::showBank(uint8_t bank)
{
  showHeader(bank);
}

void Lcd::showEncoder(uint8_t bank, uint8_t encoder, uint8_t value)
{
  uint8_t percentage = map(value, 0, 127, 0, 100);

  showHeader(bank);

  lcd.setCursor(0, 2);
  lcd.print("ENC ");
  lcd.print(encoder);

  lcd.setCursor(0, 3);
  lcd.print("VALUE: ");

  //if(value < 100)
    //lcd.print("0");

  //if(value < 10)
    //lcd.print("0");

  lcd.print(percentage);
  lcd.print("%");

}

void Lcd::showButton(uint8_t bank, uint8_t encoder)
{
  showHeader(bank);

  lcd.setCursor(0, 2);
  lcd.print("ENC");
  lcd.print(encoder);

  lcd.setCursor(0, 3);
  lcd.print("PRESSED");
}

void Lcd::showMasterReset(uint8_t bank)
{
  showHeader(bank);

  lcd.setCursor(0, 2);
  lcd.print("MASTER");

  lcd.setCursor(0, 3);
  lcd.print("RESET");
}

void Lcd::clearEvent()
{
  lcd.setCursor(0, 2);
  lcd.print("                    ");

  lcd.setCursor(0, 3);
  lcd.print("                    ");
}

void Lcd::showWelcome()
{
  lcd.clear();

  lcd.setCursor(4, 1);
  lcd.print("WELKOM SUNA");
}