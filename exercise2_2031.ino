#include <LiquidCrystal.h>
#include <Keypad.h>


const int rs = 13, en = 12, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char cKey1 = 0;  
char cKey2 = 0; 
bool firstChar = false;

const byte ROWS = 4;
const byte COLS = 3;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {7, 6, 5, 4}; 
byte colPins[COLS] = {3, 2, 1}; 
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS );

void displayRegistrationInfo() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("2031 ");

  lcd.print("CHARISTES");
}

void setup() {
  lcd.begin(16, 2);
  
  displayRegistrationInfo();
}

void loop() {

  lcd.setCursor(0, 1);
  lcd.print("Digits:");

  if (!firstChar) {               // Check if the first character has been entered if(false)
    cKey1 = customKeypad.getKey();

    if (cKey1 >= '0' && cKey1 <= '9') {
      firstChar = true;  // Set the flag to indicate the first character is entered
      lcd.setCursor(9, 1);
      lcd.print(cKey1);
    }
  } 
  else {
    cKey2 = customKeypad.getKey(); 

    if (cKey2 >= '0' && cKey2 <= '9') { 
      lcd.setCursor(10, 1);                                         
      lcd.print(cKey2);

      int num1 = cKey1 - '0';  // Convert char which corresponds to a hex value of + 0x30 of what was entered, by subtracting '0'= 0x30. ascii table.
      int num2 = cKey2 - '0';  

      lcd.setCursor(12, 1);
      int num = num1 * 10 + num2;
      lcd.print(num * num);
      lcd.print("  "); //delete output numbers
      cKey1 = 0;  
      cKey2 = 0;  
      
      firstChar = false;
    }
  }
}
