const int CLK = 5;
const int DT = 6;
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
      steps++;
    }
    else
    {
      steps--;
    }
    Serial.print("Steps:");
    Serial.println(steps);
  }
  previousstate = currentstate;
}
