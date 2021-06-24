#define Sensor_HIGH 250 //High level for optical sensor

int INITIAL_SPEED = 100;
#define INITIAL_SONAR_SPEED 150

const int MotorInput[2] = {9, 10};
const int MotorOutput[2] = {8, 11};

const int SonarEcho[3] = {40, 38, 36};
const int SonarTrig[3] = {41, 39, 37};

const int Sensors[7] = {A1, A2, A3, A4, A5, A7, A8};

int Directions[100] = {2, 0, 1, 0, -1};
//int Directions[100] = {2, 2, 0, 0, 2, 1, 0, 1, 2};
//int Directions[100] = {0, 1, 2, 1, 0, 2, 2, 0, 0};

int Motor[2] = {0};
bool Line[7] = {false};

int Mode = 0; //0 for line tracking, 1 for sonar routing

void (*SystemReset)(void) = 0;

long long int sys_start = 0;

void setup()
{
  for (int i = 0; i < 2; i++)
  {
    pinMode(MotorInput[i], OUTPUT);
    pinMode(MotorOutput[i], OUTPUT);
  }

  for (int i = 0; i < 7; i++)
  {
    pinMode(Sensors[i], INPUT);
  }

  Serial.begin(9600);
  StopAllMotor();
  sys_start = millis();
  Serial.println("System started");
}

void loop()
{
  FollowLine();
}
