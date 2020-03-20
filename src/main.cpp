#include <Arduino.h>


int aout1_pin = 6;
int pot_pin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(aout1_pin, OUTPUT);
  pinMode(pot_pin, INPUT);
}

int output;
int motor_value;
int voltage;

void pot_controls_vactrol();

void loop() {
    pot_controls_vactrol();
}

// Vactrol voltage is controlled by a potmeter
void pot_controls_vactrol() {
    output = analogRead(pot_pin);
    motor_value = map(output, 0, 1023, 0, 255);
    voltage = map(output, 0, 1023, 0, 50);

    analogWrite(aout1_pin, motor_value);    
    Serial.println(voltage);
    delay(500);
}