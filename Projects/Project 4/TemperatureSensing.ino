/*
	File Name:			  TemperatureSensing.ino
	Date Created:   	February 15, 2025
    Embedded Engineer:  Bien Carlo Halili
    Project Description:
    	This project demonstrates Temperature Sensing with Serial Interface and LED Indication for outputs.
*/

#define TMP_PIN A0
#define MAX_VOLTAGE 5
#define OFFSET_VOLTAGE 0.5
#define RED_LED 9
#define BLUE_LED 8

void setup()
{
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void loop()
{
  // Get the ADC Value of the Temperature Sensor
  int tempADCValue = analogRead(TMP_PIN);
  // Convert the ADC Value of the 
  // Temperature Sensor to a Voltage
  // Rating.
  // How to get the voltage rating from ADC?
  // 	1. Note that there are 1024 ADC values.
  //	2. Note that ADC Values ranges from 0 to 1023.
  //	3. Note that getting 0 means minimum voltage rating (0 V).
  //	4. Note that getting 1023 means maximum voltage rating (5 V).
  //	5. Equation:
  //			V = ADCValue / 1024 (Working Equation)
  float tempVoltage = MAX_VOLTAGE * tempADCValue / 1024.0;
  // Convert Temperature Voltage Rating to Celsius.
  // Equation:
  // 			C = (tempVoltage - OFFSET_VOLTAGE) (V) / 10 mV/C
  //			C = (tempVoltage - OFFSET_VOLTAGE) (V) / 10 (0.001) V/C
  //			C = (tempVoltage - OFFSET_VOLTAGE) (V) / 0.01 V/C (Working Equation)
  // Scale:     
  //			1 V = 1000 mV
  //			1 mV = 0.001 V
  float tempCelsius = (tempVoltage - OFFSET_VOLTAGE) / 0.01;
  // Convert Temperature in Celsius to Fahrenheit.
  // Equation:
  //			F = (9/5) * tempCelsius + 32 (Working Equation)
  float tempFahrenheit = (9.0/5) * tempCelsius + 32;
  
  // Temperature Prints
  Serial.print("Temperature (C): ");
  Serial.print(tempCelsius);
  Serial.print("\t");
  Serial.print("Temperature (F): ");
  Serial.println(tempFahrenheit);
  
  // LED Outputs
  // If tempCelsius < 15 degree celsius, 
  // turn on Blue LED and turn off Red LED. 
  if (tempCelsius < 15)
  {
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  }
  // Else ff tempCelsius > 34 degree celsius, 
  // turn off Blue LED and turn on Red LED. 
  else if (tempCelsius > 34)
  {
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
  else 
  {
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(RED_LED, LOW);
  }
}