#include "GameManager.h"

#include "Adafruit_WS2801.h"
#include "SPI.h" // Comment out this line if using Trinket or Gemma
#ifdef __AVR_ATtiny85__
 #include <avr/power.h>
#endif

/*****************************************************************************
Example sketch for driving Adafruit WS2801 pixels!


  Designed specifically to work with the Adafruit RGB Pixels!
  12mm Bullet shape ----> https://www.adafruit.com/products/322
  12mm Flat shape   ----> https://www.adafruit.com/products/738
  36mm Square shape ----> https://www.adafruit.com/products/683

  These pixels use SPI to transmit the color data, and have built in
  high speed PWM drivers for 24 bit color per pixel
  2 pins are required to interface

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution

*****************************************************************************/

// Choose which 2 pins you will use for output.
// Can be any valid output pins.
// The colors of the wires may be totally different so
// BE SURE TO CHECK YOUR PIXELS TO SEE WHICH WIRES TO USE!
uint8_t dataPin  = 11;    // Yellow wire on Adafruit Pixels
uint8_t clockPin = 13;    // Green wire on Adafruit Pixels

// Don't forget to connect the ground wire to Arduino ground,
// and the +5V wire to a +5V supply

// Set the first variable to the NUMBER of pixels. 25 = 25 pixels in a row
Adafruit_WS2801 strip = Adafruit_WS2801(120 + 8, dataPin, clockPin);

// Optional: leave off pin numbers to use hardware SPI
// (pinout is then specific to each board and can't be changed)
//Adafruit_WS2801 strip = Adafruit_WS2801(25);

// For 36mm LED pixels: these pixels internally represent color in a
// different format.  Either of the above constructors can accept an
// optional extra parameter: WS2801_RGB is 'conventional' RGB order
// WS2801_GRB is the GRB order required by the 36mm pixels.  Other
// than this parameter, your code does not need to do anything different;
// the library will handle the format change.  Examples:
//Adafruit_WS2801 strip = Adafruit_WS2801(25, dataPin, clockPin, WS2801_GRB);
//Adafruit_WS2801 strip = Adafruit_WS2801(25, WS2801_GRB);


// ------------------------------------------------------------------------------------

// Thumb Joystick example
// Mike Grusin, SparkFun Electronics 3/11
// This code is free, baby. Use it however you like.

// This sketch shows the basic operation of the Thumb Joystick (COM-09032) and breakout board (BOB-09110).
// The joystick outputs two analog voltages (VERT and HORIZ), and one digital signal (SEL) for the pushbutton.

// Connections to joystick (change if you use different pins):

const int VERT = 0; // analog
const int HORIZ = 1; // analog
const int SEL = 2; // digital

// Also connect the joystick VCC to Arduino 5V, and joystick GND to Arduino GND.

// This sketch outputs serial data at 9600 baud (open Serial Monitor to view).

// ------------------------------------------------------------------------------------

GameManager gameManager;

void setup() {
  // Serial:
  Serial.begin(9600);
  Serial.print("init1");
  
  gameManager = GameManager(strip);

  // --------------------------------------------------------------------------------  
  // JOYSTICK
  // make the SEL line an input
  pinMode(SEL,INPUT);
  // turn on the pull-up resistor for the SEL line (see http://arduino.cc/en/Tutorial/DigitalPins)
  digitalWrite(SEL,HIGH);
  // --------------------------------------------------------------------------------


  // --------------------------------------------------------------------------------  
  // LED
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  strip.begin();

  // Update LED contents, to start they are all 'off'
  strip.show();
  // --------------------------------------------------------------------------------  
}


void check_joystick() 
{
  int vertical, horizontal, select;
  
  // read all values from the joystick
  
  vertical = analogRead(VERT); // will be 0-1023
  horizontal = analogRead(HORIZ); // will be 0-1023
  select = digitalRead(SEL); // will be HIGH (1) if not pressed, and LOW (0) if pressed
  
  // print out the values
  if (vertical > 600)
  {
    Serial.print("UP ");
    gameManager.PlayerRequestedPointerMove(DIRECTION_UP);
  }
  if (vertical < 450)
  {
    Serial.print("DOWN ");
    gameManager.PlayerRequestedPointerMove(DIRECTION_DOWN);
  }
  if (horizontal > 600)
  {
    Serial.print("RIGHT ");
    gameManager.PlayerRequestedPointerMove(DIRECTION_RIGHT);
  }
  if (horizontal < 450)
  {
    Serial.print("LEFT ");
    gameManager.PlayerRequestedPointerMove(DIRECTION_LEFT);
  }

  const bool VERBOSE_JOYSTICK_PRINT = false;

  if (VERBOSE_JOYSTICK_PRINT)
  {
      Serial.print("vertical: ");
      Serial.print(vertical,DEC);
      Serial.print(" horizontal: ");
      Serial.print(horizontal,DEC);
      Serial.print(" select: ");
  }
  if(select == HIGH)
  {
    if (VERBOSE_JOYSTICK_PRINT)
    {
        Serial.println("not pressed");
    }
  }
  else
  {
    Serial.println("PRESSED!");
    gameManager.PlayerPressed();
  }

  if (not VERBOSE_JOYSTICK_PRINT)
  {
    Serial.println(".");
  }
}  

void DisplayBoardWithLeds()
{
    for (int i=0; i < strip.numPixels(); i++)
    {
        strip.setPixelColor(i, Color(255, 0, 0));
    }

    int joystick_location = gameManager.GetJoystickLocation();

    // Verify joystick location is not out of bounds
    if ((joystick_location >=0) && (joystick_location < strip.numPixels()))
    {
        strip.setPixelColor(joystick_location, Color(0, 255, 0));
    }

    int selected_location = gameManager.GetSelectedLocation();

    // Verify joystick location is not out of bounds
    if ((selected_location >=0) && (selected_location < strip.numPixels()))
    {
        if (selected_location != joystick_location)
        {
            strip.setPixelColor(selected_location, Color(0, 0, 255));
        }
        else
        {
            strip.setPixelColor(selected_location, Color(0, 100, 200));
        }
    }

    strip.show(); 
    gameManager.PrintBoardForDebug();

    delay(500);
}

void loop() {
  Serial.print("loop1");
  check_joystick();
  
  // Some example procedures showing how to display to the pixels
  
  const bool DO_RAINBOW_FROM_EXAMPLE = false;

  if (DO_RAINBOW_FROM_EXAMPLE)
  {
      colorWipe(Color(255, 0, 0), 50);
      colorWipe(Color(0, 255, 0), 50);
      colorWipe(Color(0, 0, 255), 50);
      rainbow(20);
      rainbowCycle(20);
  }
  else
  {
    //DisplayBoardWithLeds();
    gameManager.PrintBoardForDebug();

    Serial.print("Before handle tick\n");
    gameManager.HandleTick();
    Serial.print("After handle tick\n");
    delay(500);
  }
}


void rainbow(uint8_t wait) {
  int i, j;
   
  for (j=0; j < 256; j++) {     // 3 cycles of all 256 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel( (i + j) % 255));
    }  
    strip.show();   // write all the pixels out
    check_joystick();
    delay(wait);
  }
}

// Slightly different, this one makes the rainbow wheel equally distributed 
// along the chain
void rainbowCycle(uint8_t wait) {
  int i, j;
  
  for (j=0; j < 256 * 5; j++) {     // 5 cycles of all 25 colors in the wheel
    for (i=0; i < strip.numPixels(); i++) {
      // tricky math! we use each pixel as a fraction of the full 96-color wheel
      // (thats the i / strip.numPixels() part)
      // Then add in j which makes the colors go around per pixel
      // the % 96 is to make the wheel cycle around
      strip.setPixelColor(i, Wheel( ((i * 256 / strip.numPixels()) + j) % 256) );
    }  
    strip.show();   // write all the pixels out
    delay(wait);
    check_joystick();
  }
}

// fill the dots one after the other with said color
// good for testing purposes
void colorWipe(uint32_t c, uint8_t wait) {
  int i;
  
  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

/* Helper functions */

//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g -b - back to r
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85) {
   return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
   WheelPos -= 85;
   return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170; 
   return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
