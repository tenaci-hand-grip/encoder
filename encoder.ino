#include <Servo.h>

#define ENCODER_PIN_A 2
#define ENCODER_PIN_B 3

volatile unsigned int encoder_pos = 0;

void encoderTriggerA();
void encoderTriggerB();

void setup()
{
    pinMode(ENCODER_PIN_A, INPUT);
    pinMode(ENCODER_PIN_B, INPUT);

    // encoder pin on INT0 (pin 2)
    attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_A), encoderTriggerA, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_B), encoderTriggerB, RISING);

    Serial.begin(9600);
    Serial.println("start");
}

void loop()
{
    Serial.print("pos: "); Serial.println(encoder_pos);
    delay(100);
}


void encoderTriggerA()
{
    // check channel B to see which way encoder is turning
    if (digitalRead(ENCODER_PIN_B) == LOW)
    {
        encoder_pos += 1; // CW
    }
    else
    {
        encoder_pos -= 1; // CCW
    }
}

void encoderTriggerB()
{
    // check channel A to see which way encoder is turning
    if (digitalRead(ENCODER_PIN_A) == LOW)
    {
        encoder_pos -= 1; // CCW
    }
    else
    {
        encoder_pos += 1; // CW
    }
}