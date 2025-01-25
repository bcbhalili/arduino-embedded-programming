class LED
{
  private: int pin;
  public:
  	// Default constructor
  	LED()
    {
      this->pin = 13;
    }
  
  	// Modified Constructor
  	LED(int pin)
    {
      // If pin is in between 0 and 13 (start and end included)
      if (pin >= 0 && pin <= 13)
      {
        // This constructor declares a pin number.
      	this->pin = pin;
      }
      else
      {	
       	// This constructor declares a pin number with 13 as default.
        this->pin = 13;
      }
    }
  
  	// Getter
  	int getPin()
    {
      return this->pin;
    }
  
  	// Setter
  	void setPin(int pin)
    {
      this->pin = pin;
      Serial.println("LED Pin now is connected to D" + String(this->pin));
    }
  	
  	// Member Functions
  	void initialize()
    {
      pinMode(this->pin, OUTPUT);
      digitalWrite(this->pin, LOW);
      Serial.println("LED Pin connected to D" + String(this->pin));
      Serial.println("D" + String(this->pin) + " is declared as Digital Output.");
    }
};
class Button 
{
  private: int pin;
  public:
  	// Default constructor
  	Button()
    {
      this->pin = 13;
    }
  
  	// Modified Constructor
  	Button(int pin)
    {
      // If pin is in between 0 and 13 (start and end included)
      if (pin >= 0 && pin <= 13)
      {
        // This constructor declares a pin number.
      	this->pin = pin;
      }
      else
      {	
       	// This constructor declares a pin number with 13 as default.
        this->pin = 13;
      }
    }
  
  	// Getter
  	int getPin()
    {
      return this->pin;
    }
  
  	// Setter
  	void setPin(int pin)
    {
      this->pin = pin;
      Serial.println("Button Pin now is connected to D" + String(this->pin));
    }
  	
  	// Member Functions
  	void initialize()
    {
      Serial.println("Button Pin connected to D" + String(this->pin));
      Serial.println("D" + String(this->pin) + " is declared as Digital Input.");
      pinMode(this->pin, INPUT);
    }
};

// Constant Declarations
#define LED_PIN 13
#define BUTTON_PIN 12

// Variable Declarations
int buttonState = 0;

// Object Declarations
LED led(LED_PIN);
Button button(BUTTON_PIN);

void setup()
{
  // Code defined here will be executed first.
  Serial.begin(9600);
  led.initialize();
  button.initialize();
}

void loop()
{
  buttonState = digitalRead(button.getPin());
  Serial.println(buttonState);
  
  // If button is pressed (buttonState == 0), then turn off LED.
  if (buttonState == 0)
  {
    digitalWrite(led.getPin(), LOW);
  }
  // Else, turn on LED.
  else 
  {
    digitalWrite(led.getPin(), HIGH);
  }
}