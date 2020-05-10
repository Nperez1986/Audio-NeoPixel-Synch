// NeoPixel Ring/Jewel Skecth by Norberto Pérez Urquia
// Used NeoPixel library than modified

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            2

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      70

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(70, 2, NEO_GRB + NEO_KHZ800);

int delayval = 0; // delay for half a second (500)

void setup() {
  pinMode(3, INPUT); //define the pin as the INPUT source to read the voltage from your switch
  pinMode(6, OUTPUT); //add output if required
  
  
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  int switchState;
    
  switchState=digitalRead(3);
    
  if(switchState == HIGH){
    for(int i=0;i<NUMPIXELS;i++)
    
    pixels.setPixelColor(i, pixels.Color(30,30,30)); // Set the Color you want in the Normal state.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(0); // Delay for a period of time (in milliseconds).
  }
      
  if (switchState == LOW){
        
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Set the color you want when you hit the switch
    pixels.show(); 
    delay(12000);
    for(int i=0;i<NUMPIXELS;i++)
    pixels.setPixelColor(i, pixels.Color(50,50,50)); // Set the color you want when you hit the switch
    pixels.show();
    delay (750); 
    for(int i=0;i<NUMPIXELS;i++)
    pixels.setPixelColor(i, pixels.Color(80,90,100)); // Set the color you want when you hit the switch
    pixels.show();
    delay (750); 
    for(int i=0;i<NUMPIXELS;i++)
    pixels.setPixelColor(i, pixels.Color(90,120,250)); // Set the color you want when you hit the switch
    pixels.show();
    delay (2000); 
  }
}
