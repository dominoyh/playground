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
////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);
  for(int i=3;i<14;i++){
    pinMode(i,OUTPUT);
  }
  for(int i=3;i<11;i++){
    pin(i,0);
  }
  pin(13,1);
  pin(12,1);
  pin(11,1);
}

void loop() {/*
  int num = 9;
  for(int i=0;i<7;i++){
    pin(10-i,number[num][i]);
  }*/
  pin(4,1);
}
////////////////////////////////////////////////////
void pin(byte p,byte c){
  if(c){
    analogWrite(p,614);//614
  }
  else{
    analogWrite(p,0);
  }
}
