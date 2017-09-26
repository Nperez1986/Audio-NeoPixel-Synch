# Audio-NeoPixel-Synch
Using a sperate Soundboard to trigger no only a sound, but also a lighting sequence on a seperate board (ProTrinket)

The list of items that are being used for this project are (aside from the obvious power sources)
  1. Adafruit Pro-Trinket 5V
  2. Adafruit MAX6744 20 W Stereo Amplifier powering 2x Rockford Fosgate 30W RMS 4" Speakers
  3. 1X Audo FX 16MB Sound Board w
  4. 1 NeoPixel Ring/Jewel combination
  
  What this project entails is 2 seperate componenets, both of which I have working seperately at this moment.
  Part A
  The Audio FX16MB sound has about 4 WAV files which work just fine. I've set the board in analog mode to use the on board volume adjustment. This connects to the Adafruit MAX6744 20 Watt amplifier and sounds great
  
  Part B
  The Adafruit Pro Trinket 5V coded to turn on the 17 pixels I have with the NeoPixel Ring and Jewel togther, creating a 1.5-2" light. 
  
  The end state: To have the Soundboard in Part A send a signal to the ProTrinket in Portion B to "brighten" the lights from 50/255 to about a 100-150/255 for X amount of time. 
  
 The below code allows me to do this
  
  Looking at perhaps placing a switch to set the trigger for this
 ----------------------------------------------------------------------------------------------------------------------------- 
  I've placed the code I've been using on the Pro Trinket with the neopixels below. 
  
 // NeoPixel Ring/Jewel Skecth by Norberto Pérez Urquia
// Used NeoPixel library than modified

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            4

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      19

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(19, 4, NEO_GRB + NEO_KHZ800);

int delayval = 0; // delay for half a second (500)

void setup() {
  pinMode(5, INPUT); //define the pin as the INPUT source to read the voltage from your switch
  pinMode(3, INPUT); 
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
  int switchState2;
  
  switchState=digitalRead(5);
  switchState2=digitalRead(3);
  
  if(switchState == HIGH){
    digitalWrite(6, LOW);
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(i, pixels.Color(50,0,1)); // Set the Color you want in the Normal state.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(250); // Delay for a period of time (in milliseconds).
  }
    if(switchState == LOW){
      digitalWrite(6, HIGH);    
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(i, pixels.Color(150,0,2)); // Set the color you want when you hit the switch
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(2250); // Delay for a period of time (in milliseconds). Dictate timing based off sound file

  }
  
  if (switchState2 == LOW){
      
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Set the color you want when you hit the switch
    pixels.show(); 
    delay(500);     
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(18, pixels.Color(10,0,0)); // Set the color you want when you hit the switch
    pixels.show(); 
    delay(500);    
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Set the color you want when you hit the switch
    pixels.show(); 
    delay(500);     
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(18, pixels.Color(10,0,0)); // Set the color you want when you hit the switch
    pixels.show(); 
    delay(500);    
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Set the color you want when you hit the switch
    pixels.show(); 
    delay(500);     
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(18, pixels.Color(10,0,0)); // Set the color you want when you hit the switch
    pixels.show(); 
    delay(500);    
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Set the color you want when you hit the switch
    pixels.show(); 
    delay(500);     
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(18, pixels.Color(10,0,0)); // Set the color you want when you hit the switch
    pixels.show(); 
    delay(500);    
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Set the color you want when you hit the switch
    pixels.show(); 
    delay(500);     
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(18, pixels.Color(10,0,0)); // Set the color you want when you hit the switch
    pixels.show(); 
    delay(500); 
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Set the color you want when you hit the switch
    pixels.show(); 
    delay(500);     
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(18, pixels.Color(10,0,0)); // Set the color you want when you hit the switch
    pixels.show(); 
    delay(500);  
    for(int i=0;i<NUMPIXELS;i++)    
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Set the color you want when you hit the switch
    pixels.show(); 
    delay(3500);
    for(int i=0;i<NUMPIXELS;i++)
    pixels.setPixelColor(i, pixels.Color(50,0,1)); // Set the color you want when you hit the switch
    pixels.show();
    delay (500); 
  }
}
