🔄 Rotary Encoder LED Brightness Control using Arduino

This project demonstrates how to use a rotary encoder to control the brightness of an LED through PWM (Pulse Width Modulation) on an Arduino.
Rotating the encoder clockwise increases brightness, while rotating it counterclockwise decreases it.

🧠 Working Principle

A rotary encoder provides two outputs — CLK and DT — that toggle in a specific sequence when the shaft is rotated.
By comparing these two signals, the direction of rotation is determined:

Clockwise: steps++

Counterclockwise: steps--

The PWM signal on the LED pin adjusts brightness proportionally to the rotation.

🧩 Components Required
Component	Quantity
Arduino UNO	1
Rotary Encoder	1
LED	1
220Ω Resistor	1
Jumper Wires	As needed
Breadboard	1
⚡ Circuit Connections
Component Pin	Arduino Pin
CLK	D5
DT	D6
LED	D3 (PWM pin)
GND (Encoder & LED)	GND

The LED is connected through a 220Ω resistor to limit current.

💻 Arduino Code
const int CLK = 5;
const int DT = 6;
int led = 3;
int steps = 0;
int currentstate;
int previousstate;

void setup()
{
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  Serial.begin(9600);
  previousstate = digitalRead(CLK);
}

void loop()
{
  currentstate = digitalRead(CLK);
  if (currentstate != previousstate)
  {
    if (digitalRead(DT) != currentstate)
    {
      if (steps < 255)
      {
        steps++;
      }
    }
    else
    {
      if (steps > 0)
      {
        steps--;
      }
    }
    analogWrite(led, steps);
  }
  previousstate = currentstate;
  analogWrite(led, steps);
}

📊 Output Behavior
Encoder Direction	LED Brightness	PWM Value
Clockwise	Increases	0 → 255
Counterclockwise	Decreases	255 → 0

Serial output shows the step changes in brightness (optional).

🧩 Code Explanation

CLK and DT read the encoder signals.

When the state of CLK changes, direction is determined by reading DT.

The steps variable controls the LED brightness via analogWrite().

PWM range is 0–255, where 0 = OFF and 255 = maximum brightness.

🛠️ Applications

Volume or brightness control knobs

Menu navigation interfaces

User input for embedded systems

Adjustable speed or intensity controllers

⚙️ Notes

Use hardware debouncing (capacitors) or software debouncing if your encoder gives noisy readings.

The encoder must share a common ground with Arduino.

Adjust the LED pin if you’re using a non-PWM digital pin.
