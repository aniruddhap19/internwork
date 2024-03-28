#define lm35 A0
#define led 7
void setup() {
  pinMode(lm35, INPUT);
  pinMode(led, OUTPUT);
}

void loop(){
  float temp = analogRead(lm35);
  float cel_temp =((temp*4.88)/10);
  if(cel_temp<30){
    for(int i=0;i<1000;i++){
      digitalWrite(led, LOW);
      temp = analogRead(lm35);
      cel_temp =((temp*4.88)/10);
      if(cel_temp>30){
        goto skip;
      }
      }
      for(int i=0;i<1000;i++){
      digitalWrite(led, HIGH);
      temp = analogRead(lm35);
      cel_temp =((temp*4.88)/10);
      if(cel_temp>30){
        goto skip;
      }
      }
    }
  else if(cel_temp>30){
    for(int i=0;i<10000;i++){
      digitalWrite(led, LOW);
      temp = analogRead(lm35);
      cel_temp =((temp*4.88)/10);
      if(cel_temp<30){
        goto skip;
      }
    }
    for(int i=0;i<10000;i++){
      digitalWrite(led, HIGH);
      temp = analogRead(lm35);
      cel_temp =((temp*4.88)/10);
      if(cel_temp<30){
        goto skip;
      }
    }
  }
   skip:
  ;;
}  

