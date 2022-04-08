 #include <SoftwareSerial.h>
int S_A = 6;  //speed motor a
int M_A1 = 2; //motor a = -
int M_A2 = 3; //motor a = +
int M_B1 = 4; //motor b = +
int M_B2 = 5; //motor b = -
int S_B = 11;  //speed motor b
 
int R_S = A4; //sincer R
int S_S = A2; //sincer S
int L_S = A3; //sincer L
 
void setup()
{Serial.begin(9600);
pinMode(M_B1, OUTPUT);
pinMode(M_B2, OUTPUT);
pinMode(M_A1, OUTPUT);
pinMode(M_A2, OUTPUT);
pinMode(S_B, OUTPUT);
pinMode(S_A, OUTPUT);
 
pinMode(L_S, INPUT);
pinMode(S_S, INPUT);
pinMode(R_S, INPUT);
 
delay(200);
}
void forword(){
digitalWrite(M_A2, HIGH);
digitalWrite(M_A1, LOW);
digitalWrite(M_B2, LOW);
digitalWrite(M_B1,HIGH );
analogWrite(  S_A,175);
analogWrite(  S_B,175);
}
 
 
void turnRight(){
digitalWrite(M_A2, HIGH);
digitalWrite(M_A1, LOW);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
analogWrite(  S_A,175);
analogWrite(  S_B,175); 
}

/*void turnHardRight(){
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B2, HIGH);
  digitalWrite(M_B1, LOW);
}
 */
void turnLeft(){
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B2, LOW);
  digitalWrite(M_B1, HIGH);
analogWrite(  S_A,175);
analogWrite(  S_B,175);
}
/*void turnHardLeft(){
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B2, LOW);
  digitalWrite(M_B1, HIGH);
}
*/
/*void Maze(){
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B2, LOW);
  digitalWrite(M_B1, HIGH);
  //analogWrite(  S_B,175); 
//void forword();
 } */
void loop(){
if ((digitalRead(L_S) ==0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){forword();
Serial.println("forword");}
 
//if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnHardLeft();}
else if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) ==1)&&(digitalRead(R_S) == 0)) {turnRight();
Serial.println("turnright");}
 
//if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){turnHardRight();}
else if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnLeft();
Serial.println("turnleft");}
 
else if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 0)){turnLeft();
Serial.println("turnleft");}
}

 
