// Define the pin numbers for the components
const int fireSensorPin = A0; // Analog pin for the fire sensor
const int buzzerPin = 8; // Digital pin for the buzzer
const int relayPin = 9; // Digital pin for the relay

void setup() {
  // Set the buzzer and relay pins as output
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  
  // Initialize the serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the fire sensor
  int sensorValue = analogRead(fireSensorPin);
  
  // Convert the analog value to a voltage
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Print the voltage value for debugging
  Serial.print("Voltage: ");
  Serial.println(voltage);
  
  // Check if the voltage exceeds a certain threshold (indicating fire)
  if (voltage > 2.0) {llow}
    // Sound the buzzer
    digitalWrite(buzzerPin, HIGH);
    
    // Turn on the relay
    digitalWrite(relayPin, HIGH);
    
    // Print a message indicating fire detection
    Serial.println("Fire detected!");
  } else {
    // Turn off the buzzer
    digitalWrite(buzzerPin, LOW);
    
    // Turn off the relay
    digitalWrite(relayPin, LOW);
  }
  
  // Delay for a short period before reading the sensor again
  delay(1000);
}
