//-------------------------------------------------------------------------
// 2022/01/17
//
// S James Parsons Jr
// www.sjamesparsonsjr.com
//
//-------------------------------------------------------------------------
//Device Specs.
//Name: BTS7960 Power Motor Dirver
//Buy URL = https://amz.run/5EVI
//Price = $8.99/2pcs = $4.50pcs
//Power = 5V [VDC]
//Date = 22/01/17 10:50:39 AM
//Code URL =

/*
   Notes:
*/


//-------------------------------------------------------------------------
// +++ Libraries +++


//-------------------------------------------------------------------------
// +++ Variables +++
#define RPWM 5 // BLUE Wire
#define LPWM 6 // PURPLE Wire
#define REN 7 // GREY Wire
#define LEN 8 // WHITE Wire

#define LED_BUILTIN 13 // LED

#define ThermistorPin A1 //  Yellow wire

int Vo;                             // Thermistors variables
float R1 = 10190;                   // Thermistor voltage divider resistor value
float logR2, R2, T, Tc, Tf;         // Variables for Thermistor
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

//-------------------------------------------------------------------------

int Temperature() {
  Vo = analogRead(ThermistorPin);                             // Get V_out from analong data pin A1
  R2 = R1 * (1023.0 / (float)Vo - 1.0);                       // Solve for Thermistor resistance using voltage devider formula
  logR2 = log(R2);                                            // Log or R2 for the Steinhart-Hart equation
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2)); // Steinhart–Hart equation resistance to Kelvin formula
  Tc = T - 273.15;                                            //Convert Kelvin temp to Celsius
  return Tc;
}

//-------------------------------------------------------------------------
// +++ Setup +++
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
  pinMode(LEN, OUTPUT);
  pinMode(REN, OUTPUT);
  digitalWrite(REN, HIGH);
  digitalWrite(LEN, HIGH);
  Serial.println("Initializing...");
}

//-------------------------------------------------------------------------
// +++ Loop +++
void loop() {
  bool Heating = HIGH;
  Temperature(); // Gets thermistors current temperture
  if (Tc < 90 && Heating == HIGH) {
    analogWrite(RPWM, 0 );
    analogWrite(LPWM, 0);
    Serial.print("Temperture = ");
    Serial.println(Tc);
  }
  if (Tc == 90) {
    Heating = LOW;
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
  }
}
