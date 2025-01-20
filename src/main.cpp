#include <Arduino.h>

//change pin numbers accordingly to your set up
#define MA1 2
#define MA2 4
#define MB1 7
#define MB2 8
#define PWM_A 3
#define PWM_B 5

class motors {
public:
  void init(){
    pinMode(MA1, OUTPUT);
    pinMode(MA2, OUTPUT);
    pinMode(MB1, OUTPUT);
    pinMode(MB2, OUTPUT);
    pinMode(PWM_A, OUTPUT);
    pinMode(PWM_B, OUTPUT);
  }

  void move(char motion, byte pwm_a, byte pwm_b, int t){
    switch (motion) {
    case 'F':
      digitalWrite(MA1, HIGH);
      digitalWrite(MA2, LOW);
      digitalWrite(MB1, HIGH);
      digitalWrite(MB2, LOW);
      analogWrite(PWM_A, pwm_a);
      analogWrite(PWM_B, pwm_b);
      break;

    case 'B':
      digitalWrite(MA1, LOW);
      digitalWrite(MA2, HIGH);
      digitalWrite(MB1, LOW);
      digitalWrite(MB2, LOW);
      analogWrite(PWM_A, pwm_a);
      analogWrite(PWM_B, pwm_b);
      break;
    
    case 'R':
      digitalWrite(MA1, HIGH);
      digitalWrite(MA2, LOW);
      digitalWrite(MB1, LOW);
      digitalWrite(MB2, HIGH);
      analogWrite(PWM_A, pwm_a);
      analogWrite(PWM_B, pwm_b);
      break;

    case 'L':
      digitalWrite(MA1, LOW);
      digitalWrite(MA2, HIGH);
      digitalWrite(MB1, HIGH);
      digitalWrite(MB2, LOW);
      analogWrite(PWM_A, pwm_a);
      analogWrite(PWM_B, pwm_b);
      break;
    }
  }

  void stop(String state, int t){
    if(state == "halt"){
      digitalWrite(MA1, HIGH);
      digitalWrite(MA2, HIGH);
      digitalWrite(MB1, HIGH);
      digitalWrite(MB2, HIGH);
      analogWrite(PWM_A, 255);
      analogWrite(PWM_B, 255);
    }else if(state == "off"){
      digitalWrite(MA1, LOW);
      digitalWrite(MA2, LOW);
      digitalWrite(MB1, LOW);
      digitalWrite(MB2, HIGH);
      analogWrite(PWM_A, 0);
      analogWrite(PWM_B, 0);
    }
  }
};

motors TB6612FNG ;

void setup() {
  //initialize the motors
  TB6612FNG.init();
}

void loop() {
  //example of how to use the motor class functions
  
  //move the motor forwards for 3 seconds
  TB6612FNG.move('F', 128, 128, 3000);

  //move the motor backwards for 2 seconds
  TB6612FNG.move('B', 255, 255, 2000);

  //halt the motors for half a second
  TB6612FNG.stop("HALT", 500);
}
