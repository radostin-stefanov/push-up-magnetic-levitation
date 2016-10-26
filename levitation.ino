int readPin = A2; // used to connect the input
int i1Pin = 36;  // connected to the motor driver board I1 interface
int i2Pin = 37;  // motor drive board to connect the I2 interface
int powerPin = 8;// motor drive board The EA interface
int adjustPin = A6;

boolean flag = true;
int power = 0;
int readValue = 0;
int adjustValue = 0;

void GetPowerValue () {
  power = readValue - adjustValue;
  if (power < 0) power = 0;
  if (power > 50) power = 50;
  power = power * 16 / 10;
}

void setup () {
  pinMode(i1Pin, OUTPUT);
  pinMode(i2Pin, OUTPUT);     // I1 and I2 are used to control the current direction
  pinMode (powerPin, OUTPUT); // output by duty cycle mode (pin1, pin2, pin2, pin2) Analog signal
  digitalWrite (i1Pin, !flag);
  digitalWrite (i2Pin, flag);
//  Serial.begin(9600); // Set the baud rate
}

void loop () {
  // Read potentiometer and sensor
  readValue = analogRead (readPin);
  // sensor voltage range is 220 ~ 580, so adjust the potentiometer range can be adjusted slightly
  adjustValue = analogRead (adjustPin) / 3 + 220;
  GetPowerValue ();
//  Serial.print("readValue: ");
//  Serial.println(readValue);
//  Serial.print("adjustValue: ");
//  Serial.println(adjustValue);
//  Serial.print("power: ");
//  Serial.println (power);

  analogWrite (powerPin, power);
//  delay (200);
}
