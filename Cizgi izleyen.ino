/*Mert Arduino and Raspberry Pi - Line Following Robot*/

//Define Pins

int ENA = 3; //Enable Pin of the Right Motor (must be PWM)
int IN1 = 1; //Control Pin
int IN2 = 2;

int ENB = 6; //Enable Pin of the Left Motor (must be PWM)
int IN3 = 4;
int IN4 = 5;

//Speed of the Motors
#define ENASpeed 70
#define ENBSpeed 70

int sag = 0;
int sol = 0;
int orta = 0;


void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(sag, INPUT);
  pinMode(sol, INPUT);
  pinMode(orta, INPUT);
  
}

void loop(){

  //Use analogWrite to run motor at adjusted speed
  analogWrite(ENA, ENASpeed);
  analogWrite(ENB, ENBSpeed);

  //Read the Sensor if HIGH (BLACK Line) or LOW (WHITE Line)
  sag = digitalRead(10);
  sol = digitalRead(11);
  orta = digitalRead(12);
  //Set conditions for FORWARD, LEFT and RIGHT

  if(sol == HIGH && sag == LOW){

    //Turn LEFT
    //motor A Backward
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    //motor B Forward
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  else if (sol == LOW && sag == HIGH){

    //Turn RIGHT
    //motor A Forward
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    //motor B Backward
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  else{

    //if(Sensor4 == LOW && Sensor3 == HIGH && Sensor2 == HIGH && Sensor1 == LOW

    //FORWARD
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
}
