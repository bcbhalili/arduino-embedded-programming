/*
	File Name:			BlinkOOP.ino
	Date Created:   	January 18, 2025
    Embedded Engineer:  Bien Carlo Halili
    Project Description:
    	This project blinks an LED.
*/

class LED
{
  private:
  int pin;
  public:
  // Constructor Definition
  LED(int pin)
  {
    this->pin = pin;
    initialize();
    off();
  }
  
  // Getters
  int getPin()
  {
    return this->pin;
  }
  // Setters
  void setPin(int pin)
  {
    this->pin = pin;
  }
  
  // Member Functions
  void initialize() { pinMode(this->pin, OUTPUT); }
  void on() { digitalWrite(this->pin, HIGH); }
  void off() { digitalWrite(this->pin, LOW); }
};

// Global Variable/Object Declarations
#define LED_PIN 13
#define TIME 500
LED led(LED_PIN);

void setup()
{
  // Put your code here that will only run once.
  
}

void loop()
{
  // Put your code here that will run forever unless project stopped.
  led.on();
  delay(TIME);
  led.off();
  delay(TIME);
}