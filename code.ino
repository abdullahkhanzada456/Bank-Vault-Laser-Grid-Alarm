// Pin Definitions matching your circuit
const int PIR_PIN = 3;       // Green wire
const int BUZZER_PIN = 2;    // Blue wire
const int RESET_BUTTON_PIN = 4; // Your new reset button pin

// State Management Variable
bool isAlarmTripped = false;

void setup()
{
  pinMode(PIR_PIN, INPUT);
  pinMode(RESET_BUTTON_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
  int sensor_state = digitalRead(PIR_PIN);
  int reset_state = digitalRead(RESET_BUTTON_PIN);

  // 1. LATCH TRIGGER: If motion is detected, lock the alarm state to TRUE
  if (sensor_state == HIGH) {
    isAlarmTripped = true;
  }

  // 2. MANUAL RESET: Only clear the alarm if the reset button is pressed
  if (reset_state == HIGH) {
    isAlarmTripped = false;
  }

  // 3. OUTPUT CONTROL: Play tone if the system is latched tripped
  if (isAlarmTripped == true) {
    tone(BUZZER_PIN, 220); // Keep ringing!
  } else {
    noTone(BUZZER_PIN);    // Silent until tripped again
  }

  delay(10); // Performance stabilization delay
}