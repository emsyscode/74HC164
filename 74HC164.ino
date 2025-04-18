//I use the 8 rows by 4 columns, the wheigt of bit is:
// //I let first row empty, but is possible use it on "Q", or "Ç" for example, put it in the last!
//
//       1 2 4 8 //Firts word of 4 bits on Byte  // This is top of char...
//       1 2 4 8 //Second workd of 4 bits on Byte 
//       1 2 4 8 //Firts word of 4 bits on Byte
//       1 2 4 8 //Second workd of 4 bits on Byte
//       1 2 4 8 //Firts word of 4 bits on Byte
//       1 2 4 8 //Second workd of 4 bits on Byte
//       1 2 4 8 //Firts word of 4 bits on Byte
//       1 2 4 8 //Second workd of 4 bits on Byte //This is bottom of char...
//
// How draw number "1": 0x02,0x32,0x22,0x27, //1
// How draw letter "A": 0x0F,0x99,0xF9,0x99, //A


#define data 8
#define clock 9
#define led 10
#define ctrl 11

uint8_t letter[110] = { 0x0F,0x99,0xF9,0x99, //A
                        0x07,0xAA,0x7A,0xA7, //B
                        0x07,0x11,0x11,0x17, //C
                        0x07,0xAA,0xAA,0xA7, //D
                        0x07,0x11,0x71,0x17, //E
                        0x07,0x11,0x71,0x11, //F
                        0x0F,0x11,0xD9,0x9F, //G
                        0x09,0x99,0xF9,0x99, //H
                        0x07,0x22,0x22,0x27, //I
                        0x07,0x44,0x45,0x57, //J
                        0x09,0x55,0x35,0x59, //K
                        0x01,0x11,0x11,0x17, //L
                        0x09,0xF9,0x99,0x99, //M
                        0x09,0xBD,0x99,0x99, //N
                        0x0F,0x99,0x99,0x9F, //O
                        0x0F,0x99,0xF1,0x11, //P
                        0x0F,0x99,0x99,0xDF, //Q
                        0x07,0x99,0x73,0x59, //R
                        0x07,0x11,0x74,0x47, //S
                        0x07,0x22,0x22,0x22, //T
                        0x09,0x99,0x99,0x96, //U
                        0x09,0x99,0x55,0x31, //V
                        0x09,0x96,0x69,0x99, //X
                        0x07,0x44,0x22,0x17, //Z
                        0x09,0x99,0x99,0xF9, //W
                      }; 

uint8_t numbers[40] = { 0x07,0x55,0x55,0x57, //0
                        0x02,0x32,0x22,0x27, //1
                        0x07,0x44,0x22,0x17, //2
                        0x07,0x44,0x74,0x47, //3
                        0x05,0x55,0x74,0x44, //4
                        0x07,0x11,0x74,0x47, //5
                        0x07,0x11,0x69,0x96, //6
                        0x07,0x44,0x44,0x44, //7
                        0x06,0x99,0x69,0x96, //8
                        0x06,0x99,0x68,0x86, //9
                      };


uint8_t byte_1 = 0x00;
uint8_t byte_2 = 0x00;
uint8_t byte_3 = 0x00;
uint8_t byte_4 = 0x00;

void setup(){
  pinMode(clock, OUTPUT); // make the clock pin an output
  pinMode(data , OUTPUT); // make the data pin an output
  pinMode(led, OUTPUT);  // make the led pin an output
  pinMode(ctrl, OUTPUT);
  digitalWrite(led, HIGH);
  digitalWrite(ctrl, HIGH);

  Serial.begin(115200);
}
void ledPanel(){
  for(uint8_t i = 0; i < 6; i++){
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
  }
}
void allOn(){
long length32 = 0x00000000;  //Hexadecimal declaration filled.
     length32 = 0B11111111111111111111111111111111;  //Binary filled
        byte_4 = (length32 & 0xff000000) >>  24; 
        byte_3 = (length32 & 0x00ff0000) >>  16;
        byte_2 = (length32 & 0x0000ff00) >>  8;
        byte_1 = (length32 & 0x000000ff) >>  0;
    // Serial.print("lng: ");
    // Serial.println(length32, BIN);
  shiftOut(data, clock, MSBFIRST, ~byte_1);// 
  shiftOut(data, clock, MSBFIRST, ~byte_2);//  
  shiftOut(data, clock, MSBFIRST, ~byte_3);// 
  shiftOut(data, clock, MSBFIRST, ~byte_4);//
  delay(1000);  
}
void allOff(){
long length32 = 0x00000000;  //Hexadecimal declaration filled.
     length32 = 0B00000000000000000000000000000000;  //Binary filled
        byte_4 = (length32 & 0xff000000) >>  24; 
        byte_3 = (length32 & 0x00ff0000) >>  16;
        byte_2 = (length32 & 0x0000ff00) >>  8;
        byte_1 = (length32 & 0x000000ff) >>  0;
    // Serial.print("lng: ");
    // Serial.println(length32, BIN);
  shiftOut(data, clock, MSBFIRST, ~byte_1);// 
  shiftOut(data, clock, MSBFIRST, ~byte_2);//  
  shiftOut(data, clock, MSBFIRST, ~byte_3);// 
  shiftOut(data, clock, MSBFIRST, ~byte_4);//
  delay(1000);  
}
void oneByOne(){
long length32 = 0x00000000;  //Hexadecimal declaration filled.
  for(uint8_t i = 0; i < 32; i++){
     length32 = 0B00000000000000000000000000000001;  //Binary filled
    length32 = (length32 << i);
        byte_4 = (length32 & 0xff000000) >>  24; 
        byte_3 = (length32 & 0x00ff0000) >>  16;
        byte_2 = (length32 & 0x0000ff00) >>  8;
        byte_1 = (length32 & 0x000000ff) >>  0;
    // Serial.print("lng: ");
    // Serial.println(length32, BIN);
  shiftOut(data, clock, MSBFIRST, ~byte_1);// 
  shiftOut(data, clock, MSBFIRST, ~byte_2);//  
  shiftOut(data, clock, MSBFIRST, ~byte_3);// 
  shiftOut(data, clock, MSBFIRST, ~byte_4);//
  delay(1000);  
  }
}
void loop() {
  ledPanel();
for(uint8_t s = 0; s < 4; s++){
  allOn();
  delay(100);
  allOff();
  delay(100);
}
  oneByOne();
for (uint8_t ch = 0; ch <40; ch=ch+4){
      byte_1 = numbers[ch];
      byte_2 = numbers[ch+1];
      byte_3 = numbers[ch+2];
      byte_4 = numbers[ch+3];

      shiftOut(data, clock, MSBFIRST, ~byte_1); // 
      shiftOut(data, clock, MSBFIRST, ~byte_2); //  
      shiftOut(data, clock, MSBFIRST, ~byte_3); // 
      shiftOut(data, clock, MSBFIRST, ~byte_4); //  
      delay(1000);
  }
  for (uint8_t ch = 0; ch <100; ch=ch+4){
      byte_1 = letter[ch];
      byte_2 = letter[ch+1];
      byte_3 = letter[ch+2];
      byte_4 = letter[ch+3];

      shiftOut(data, clock, MSBFIRST, ~byte_1); // 
      shiftOut(data, clock, MSBFIRST, ~byte_2); //  
      shiftOut(data, clock, MSBFIRST, ~byte_3); // 
      shiftOut(data, clock, MSBFIRST, ~byte_4); //  
      delay(1000);
  }
}

