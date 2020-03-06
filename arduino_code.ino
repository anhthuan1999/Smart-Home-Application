#include <SoftwareSerial.h>+66
double KoTinHieu=0; //ứng dụng trong sensor chuyển động
double CoTinHieu=0; //ứng dụng trong sensor chuyển động
bool LanChayDau = true;//ứng dụng trong sensor chuyển động
int tinhieunhanduoc = 0; //Nếu là 1 thì sensor được phép làm việc, còn là 0 thì không làm việc
bool tinhieuchuyendong=false;
bool tinhieukhiga=false;
bool tinhieulua=false;
bool tinhieurole=false;
bool trangthairole=false;
bool landaulua=true,landaukhiga=true;
double ktinhieulua=0,cotinhieulua=0;
double ktinhieukhiga=0,cotinhieukhiga=0;
String s="Mo cam bien chuyen dong: 1 \nMo cam bien khi ga: 2 \nMo cam bien lua:3 \nMo role: 4\nTat cam bien chuyen dong: 5\nTat cam bien khi ga: 6\nTat cam bien lua: 7 \nTat role: 8 \nBat tat ca: A\nTat tat ca: N\nNhan ? de xem lai ";
void setup() 
{
  Serial.begin(38400);
  pinMode(8,INPUT); //cảm biến khí gas
  pinMode(9,INPUT);//cảm biến chuyển động
  pinMode(A0,INPUT);
  pinMode(7, INPUT);//cảm biến lửa
  pinMode(5, OUTPUT);//Rơ le
  pinMode(13,OUTPUT); //loa báo hiệu chuyển động
  pinMode(12,OUTPUT); //loa báo hiệu khí gas
  pinMode(11,OUTPUT); // loa báo hiệu cháy
  Serial.print(s);
}
//===========================================================
void nhanduoc() //Nhận tín hiệu cho phép hoạt động từ PC và gán vào Status
{
  if (Serial.available() > 0)
  {
    while (Serial.available() > 0)
    {
      tinhieunhanduoc = Serial.read(); //Đọc tín hiệu được gửi từ PC 
    }
  }
 } 
//======================= CHUYỂN ĐỘNG ===================================
void cambienchuyendong(int cambienchuyendong2) 
{
     
      if(digitalRead(cambienchuyendong2)==HIGH) // Có báo dộng
      {
        digitalWrite(13,HIGH);
        KoTinHieu=0;
        CoTinHieu=CoTinHieu+0.2;
        Serial.print("q");
        LanChayDau = false;    
      }
      else
      {
        digitalWrite(13,LOW);
        KoTinHieu=KoTinHieu+0.2;
        if((KoTinHieu>3) or (LanChayDau == true))
        {
          Serial.print("w");
        }
        else
        {
          digitalWrite(13,HIGH);
          Serial.print("q"); //Thời gian chờ trước khi có tín hiệu mới hoặc Chuyển qua không tín hiệu
          CoTinHieu=0;
        }      
      }
    }

//========================== KHÍ GAS =====================================
void cambienkhiga(int cambienkhiga) 
{     
      
      if(digitalRead(8)==HIGH) //khong co khi gas
          {
              
            digitalWrite(12,LOW);
            
            ktinhieukhiga+=0.2;
            if((ktinhieukhiga>5) or (landaukhiga == true))
              {
                Serial.println("r");
              } else
              {
                digitalWrite(12,HIGH);
                Serial.print("e"); //Thời gian chờ trước khi có tín hiệu mới hoặc Chuyển qua không tín hiệu
                cotinhieukhiga=0;
              }
          }else 
          {
            digitalWrite(12,HIGH);
            Serial.println("e");
            ktinhieukhiga=0;
            cotinhieukhiga+=0.2;
            landaukhiga = false;
          }   
          
          
 }
//====================== CẢM BIẾN LỬA ================================
void cambienlua(int cambienlua) 
{
  
  if(digitalRead(cambienlua)==HIGH) //Không lửa
  {
    
     digitalWrite(11,LOW);
            
            ktinhieulua+=0.2;
            if((ktinhieulua>5) or (landaulua == true))
              {
                Serial.println("y");
              } else
              {
                digitalWrite(11,HIGH);
                Serial.print("t"); //Thời gian chờ trước khi có tín hiệu mới hoặc Chuyển qua không tín hiệu
                cotinhieulua=0;
              }
    
  }
  else
  {
    digitalWrite(11,HIGH);
    Serial.println("t");
    ktinhieulua=0;
    cotinhieulua+=0.2;
    landaulua = false;
  }
  
}


void loop()
{
 nhanduoc();
 switch(tinhieunhanduoc)
 {
  //=================Bật=============
  case 49: //1 trong hệ ASCII là số 49 trong hệ unsigned
    
    tinhieuchuyendong=true;
    break;
  case 50://2 trong hệ ASCII là số 50 trong hệ unsigned
    
    tinhieukhiga=true;
    break;
  case 51://3 trong hệ ASCII là số 51 trong hệ unsigned
    
    tinhieulua=true;
    break;
  case 52://4 trong hệ ASCII là số 52 trong hệ unsigned
  
    tinhieurole=true; //role bật
    break;
//=====================Tắt=========
 case 53: //5 trong hệ ASCII là số 53 trong hệ unsigned
  
  tinhieuchuyendong=false;
 break;
 case 54://6 trong hệ ASCII là số 54 trong hệ unsigned
  
  tinhieukhiga=false;
  break;
 case 55://7 trong hệ ASCII là số 55 trong hệ unsigned
  
  tinhieulua=false;
  break;
 case 56://8 trong hệ ASCII là số 56 trong hệ unsigned
 
  tinhieurole=false;//rơ le tắt
  break;
 case 63: // dấu ?
  Serial.print(s);
  tinhieunhanduoc=0;
  break;
  
}
//===========Thực thi===========
if(tinhieuchuyendong== true)
{
  cambienchuyendong(9);
}
else{digitalWrite(13,LOW);}
if(tinhieukhiga == true)
{
  cambienkhiga(8);
  
}else{digitalWrite(12,LOW);}
if(tinhieulua == true)
{
  cambienlua(7);
}else{digitalWrite(11,LOW);}
if(tinhieurole == true  )
{
  digitalWrite(5,HIGH);
  
}else 
{
  digitalWrite(5,LOW);
}
  delay(200);
}
