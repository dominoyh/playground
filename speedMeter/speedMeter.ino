long preTime = 0;
byte preState = 0;
byte digit = 0;
float spd = 0;
byte number[10][7] = {
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,1,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};

float circumference = 50;   //set your circumference(cm)

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  for(int i=3;i<14;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  if(digitalRead(2)==0&&preState==0){
    spd = cul(millis()-preTime,circumference);
    Serial.println(spd);
    preTime = millis();
    preState = 1;
  }
  else if(digitalRead(2)==0&&preState==1){
  
  }
  else{
    preState = 0;
  }
  fnd();
}

float cul(float tic,float cir){
  return 36*cir/tic;
}

void pin(byte p,byte c){
  if(c){
    analogWrite(p,614);//614
  }
  else{
    analogWrite(p,0);
  }
}

void fnd(){
  byte num = 0;
  if(digit==0){
    digit=1;
    pin(13,0);
    pin(12,1);
    pin(11,1);
    num = (int)spd/10;
    for(int i=0;i<7;i++){
      pin(10-i,number[num][i]);
    }
    Serial.println("0");
  }
  else if(digit==1){
    digit=2;
    pin(13,1);
    pin(12,0);
    pin(11,1);
    num = (int)spd%10;
    for(int i=0;i<7;i++){
      pin(10-i,number[num][i]);
    }
    pin(3,1);
    Serial.println("1");
  }
  else{
    digit=0;
    pin(12,1);
    pin(11,1);
    pin(10,0);
    num = (int)(spd*10)%10;
    for(int i=0;i<7;i++){
      pin(10-i,number[num][i]);
    }
    Serial.println("2");
  }
  pin(13,1);
  pin(12,1);
  pin(11,1);
  pin(3,0);
  Serial.println("3");
}
