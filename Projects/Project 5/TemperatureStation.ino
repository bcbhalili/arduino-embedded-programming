class Temperature {
  private:
  const float MAX_VOLTAGE = 5;
  const float MAX_ADC_VALUE = 1023;
  int pin;
  
  public:
  // Constructor definition
  Temperature(int pin) {
  	this->pin = pin;
  }
  // Getter/s
  int getPin() {
    return this->pin;
  }
  // Setter/s
  void setPin(int pin) {
    this->pin = pin;
  }
  // Member Functions
  float getVoltage() {
    // NOTE: Range is 0V to 5V.
    int adcValue = analogRead(this->pin);
    
    return adcValue * MAX_VOLTAGE / MAX_ADC_VALUE;	// Return in V.
  }
  float getCelsius(float voltage) {
    // NOTE: TMP36 Scale Factor: 10 mV/C
    //		 1 V = 1000 mV
    return ((voltage - 0.5) * 1000) / 10;
  }
  float getFahrenheit(float celsius) {
    // NOTE: (celsius × 9/5) + 32
    return (celsius * 9 / 5) + 32;
  }
  float getKelvin(float celsius) {
    // NOTE: celsius + 273.15 K
    return celsius + 273.15;
  }
};

#include <LiquidCrystal.h>
#define TMP_PIN A0
#define RS_PIN 12
#define EN_PIN 11
#define D4_PIN 5
#define D5_PIN 4
#define D6_PIN 3
#define D7_PIN 2
#define LB_PIN 13
#define MB_PIN 10
#define RB_PIN 9
#define RR_PIN 6
#define MR_PIN 7
#define LR_PIN 8

Temperature temperature(A0);
LiquidCrystal lcd(RS_PIN,
                  EN_PIN,
                  D4_PIN,
                  D5_PIN,
                  D6_PIN,
                  D7_PIN);

void setup()
{
  pinMode(LB_PIN, OUTPUT);
  pinMode(MB_PIN, OUTPUT);
  pinMode(RB_PIN, OUTPUT);
  pinMode(LR_PIN, OUTPUT);
  pinMode(MR_PIN, OUTPUT);
  pinMode(RR_PIN, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  delay(1000);
  lcd.clear();
}

void loop()
{
  float voltageValue = temperature.getVoltage();
  float celsiusValue = temperature.getCelsius(voltageValue);
  float fahrenheitValue = temperature.getFahrenheit(celsiusValue);
  float kelvinValue = temperature.getKelvin(celsiusValue);
  
  if (celsiusValue <= 12) {
    digitalWrite(LB_PIN, HIGH);
  	digitalWrite(MB_PIN, HIGH);
  	digitalWrite(RB_PIN, HIGH);
  	digitalWrite(LR_PIN, LOW);
  	digitalWrite(MR_PIN, LOW);
  	digitalWrite(RR_PIN, LOW);
  }
  else if (celsiusValue > 12 && celsiusValue <= 18) {
    digitalWrite(LB_PIN, LOW);
  	digitalWrite(MB_PIN, HIGH);
  	digitalWrite(RB_PIN, HIGH);
  	digitalWrite(LR_PIN, LOW);
  	digitalWrite(MR_PIN, LOW);
  	digitalWrite(RR_PIN, LOW);
  }
  else if (celsiusValue > 18 && celsiusValue <= 24) {
    digitalWrite(LB_PIN, LOW);
  	digitalWrite(MB_PIN, LOW);
  	digitalWrite(RB_PIN, HIGH);
  	digitalWrite(LR_PIN, LOW);
  	digitalWrite(MR_PIN, LOW);
  	digitalWrite(RR_PIN, LOW);
  }
  else if (celsiusValue > 24 && celsiusValue <= 30) {
    digitalWrite(LB_PIN, LOW);
  	digitalWrite(MB_PIN, LOW);
  	digitalWrite(RB_PIN, LOW);
  	digitalWrite(LR_PIN, HIGH);
  	digitalWrite(MR_PIN, LOW);
  	digitalWrite(RR_PIN, LOW);
  }
  else if (celsiusValue > 30 && celsiusValue <= 36) {
    digitalWrite(LB_PIN, LOW);
  	digitalWrite(MB_PIN, LOW);
  	digitalWrite(RB_PIN, LOW);
  	digitalWrite(LR_PIN, HIGH);
  	digitalWrite(MR_PIN, HIGH);
  	digitalWrite(RR_PIN, LOW);
  }
  else if (celsiusValue > 36) {
    digitalWrite(LB_PIN, LOW);
  	digitalWrite(MB_PIN, LOW);
  	digitalWrite(RB_PIN, LOW);
  	digitalWrite(LR_PIN, HIGH);
  	digitalWrite(MR_PIN, HIGH);
  	digitalWrite(RR_PIN, HIGH);
  }
  
  displayTemperaturesSerial(voltageValue, 
                      		celsiusValue, 
                      		fahrenheitValue,
                      		kelvinValue);
  displayTemperaturesLCD("Voltage (V): ",
                         "Celsius (C): ",
                         "Fahrenheit (F): ",
                         "Kelvin (K): ",
                         voltageValue,
                         celsiusValue,
                         fahrenheitValue,
                         kelvinValue);
}

void displayTemperaturesSerial(
  	float voltage, 
  	float celsius, 
  	float fahrenheit,
	float kelvin) {
  Serial.print("Voltage: "); Serial.print(voltage);
  Serial.print("V\tCelsius: "); Serial.print(celsius);
  Serial.print("C\tFahrenheit: "); Serial.print(fahrenheit);
  Serial.print("F\tKelvin: "); Serial.print(kelvin);
  Serial.println("K");
}
void displayTemperaturesLCD(
    char voltageText[16],
    char celsiusText[16],
  	char fahrenheitText[16],
  	char kelvinText[16],
  	float voltage, 
  	float celsius, 
  	float fahrenheit,
	float kelvin) {
  lcd.setCursor(0, 0);	
  lcd.print(voltageText);
  lcd.setCursor(0, 1);
  lcd.print(voltage);
  
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0, 0);	
  lcd.print(celsiusText);
  lcd.setCursor(0, 1);
  lcd.print(celsius);
  
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0, 0);	
  lcd.print(fahrenheitText);
  lcd.setCursor(0, 1);
  lcd.print(fahrenheit);
  
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0, 0);	
  lcd.print(kelvinText);
  lcd.setCursor(0, 1);
  lcd.print(kelvin);
  
  delay(2000);
  lcd.clear();
}
  