#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6

#define NUMPIXELS      2

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

unsigned long time;

void setup() {
  randomSeed(analogRead(0));
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif  

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  long randnumber; // Generates a random number
  long pixelnumber; // Random pixel 

  randnumber=random(0,3);
  pixelnumber=random(0,2);
  time = millis();
  while(time%50==0){
  switch(randnumber){
    case 0: pixels.setPixelColor(pixelnumber, pixels.Color(0,150,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    pixels.setPixelColor(pixelnumber, pixels.Color(0,0,0));
      
    break;

    case 1: pixels.setPixelColor(pixelnumber, pixels.Color(150,0,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    pixels.setPixelColor(pixelnumber, pixels.Color(0,0,0));


    break;

    case 2: pixels.setPixelColor(pixelnumber, pixels.Color(0,0,150)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    pixels.setPixelColor(pixelnumber, pixels.Color(0,0,0));


    break;

  }
)
   
}
