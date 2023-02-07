
/**
 * Control a Pac Man light so that it works directly from power
 * and chooses the lighting mode I want.
 * 
 * Existing light uses a single button that cycles through power & 3 different modes.
 * If it loses power it loses state. There is no way to have it turn on automatically
 * 
 * I ran the usb power (from the light) to the arduino.
 * Arduino then provides power to the light
 * 
 * Pins:
 * Power In (from original light) -> GND + VIN
 * Power Out (from Arduino) -> GND + D2
 * Button control (on light) -> GND + D9
 * 
 * I essentially cut the wires coming from the USB plug:
 * - connected power to the arduino (to provide power to arduino)
 * - connected the other cut end (light power) to the Arduino (Pin D2)
 * 
 * The button for the light is using ground to determine a button press.
 * So I just set the BUTTON pin to LOW to indicate a button press
 * 
 */

#define POWER 2
#define BUTTON 9

void setup() {
  Serial.begin(9600);

  pinMode(POWER, OUTPUT);
  pinMode(BUTTON, OUTPUT);

  digitalWrite(POWER, LOW);
  digitalWrite(BUTTON, HIGH);

  Serial.println("Hello! Ready!");

  delay(1000);

  log("turning power on");
  delay(1000);

  turnDeviceOn();
  delay(1000);

  log("pressing button 1");
  delay(1000);
  pressButton();
  //delay(1000);

  log("pressing button 2");
  delay(1000);
  pressButton();

  log("worked?");
}

void log(String message) {
   Serial.println(message);
}

void turnDeviceOn() {
  digitalWrite(POWER, HIGH);
}

void pressButton() {
  digitalWrite(BUTTON, LOW);
  delay(200);
  digitalWrite(BUTTON, HIGH);
}

void loop() {
  // no operation
}
