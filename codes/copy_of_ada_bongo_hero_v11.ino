#include <Adafruit_NeoPixel.h>
 
#define LED_1 10
#define LED_2 11
#define LED_3 12
#define LED_4 13

#define NUMLED 10
#define NOTE_D4  294
 
 
Adafruit_NeoPixel pixel_1(NUMLED, LED_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel_2(NUMLED, LED_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel_3(NUMLED, LED_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixel_4(NUMLED, LED_4, NEO_GRB + NEO_KHZ800);
 
#define DELAYLOOP 500
 
void setup() {
	pixel_1.begin();
  	pixel_2.begin();
 	pixel_3.begin();
  	pixel_4.begin();
  
  	pinMode(2, INPUT);
  	pinMode(3, INPUT);
  	pinMode(4, INPUT);
  	pinMode(5, INPUT);
  	pinMode(6, OUTPUT);  //buzzer
}
  
void choose(int fita){
switch(fita){
  case 1:
    for(int i=0; i<NUMLED; i++){
    pixel_1.setPixelColor(i, pixel_1.Color(50, 100, 50));
    pixel_1.show();
	delay(DELAYLOOP);
    pixel_1.clear();
   }
   break; 
  case 2:
    for(int i=0; i<NUMLED; i++){
    pixel_2.setPixelColor(i, pixel_2.Color(100, 50, 50));
    pixel_2.show();
	delay(DELAYLOOP); 
    pixel_2.clear();
   }
    break; 
  case 3:
    for(int i=0; i<NUMLED; i++){
    pixel_3.setPixelColor(i, pixel_3.Color(50, 50, 100));
    pixel_3.show();
	delay(DELAYLOOP); 
    pixel_3.clear();
   }  
    break;
  case 4:
    for(int i=0; i<NUMLED; i++){
    pixel_4.setPixelColor(i, pixel_4.Color(100, 100, 100));
    pixel_4.show();
	delay(DELAYLOOP);
    pixel_4.clear();
   }  
    break; 
 }                      
}
                         
                      
void loop(){
  if((digitalRead(2) || digitalRead(3) || digitalRead(4) || digitalRead(5))==1){
   tone(6, NOTE_D4, 100); 
  }
  
  choose(1);
  choose(2);
  choose(3);
  
  //implementar velocidade e multuabilidade, ou seja, chamar mais de uma fita ao mesmo tempo
  
 
	/*for(int i=0; i<NUMLED; i++) {
 
		pixels.setPixelColor(i, pixels.Color(150, 0, 0));
 
		pixels.show();
 
		delay(DELAYLOOP);
	}*/
}