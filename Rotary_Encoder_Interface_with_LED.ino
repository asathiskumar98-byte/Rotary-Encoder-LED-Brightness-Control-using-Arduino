const int CLK = 5;
const int DT = 6;
int led = 3;
int steps = 0;
int currentstate;
int previousstate;

void setup()
{
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  Serial.begin(9600);
  previousstate = digitalRead(CLK);
}

void loop()
{
  currentstate = digitalRead(CLK);
  if(currentstate != previousstate)
  {
    if(digitalRead(DT) != currentstate)
    {
      if(steps < 255)
      {
        steps++;
      }
    }
    else
    {
      if(steps > 0)
      {
        steps--;
      }
    }
    analogWrite(led,steps);
  }
  previousstate = currentstate;
  analogWrite(led,steps);
}
