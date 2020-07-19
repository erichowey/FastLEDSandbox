#include <FastLED.h>
#include <JC_Button.h> 

#define DATA_PIN    22
#define NUM_LEDS    72
#define BRIGHTNESS  255
#define BUTTON_PIN  20

#define FRAMES_PER_SECOND  60

CRGB leds[NUM_LEDS];

CRGBPalette16 bloodPalette;

Button alertBtn(BUTTON_PIN);

byte offset = 0;

void setup()
{
  delay(3000);

  Serial.begin(9600);
  
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();


  bloodPalette[0] = CRGB::Cyan;
  bloodPalette[1] = CRGB::Cyan;
  bloodPalette[2] = CRGB::Cyan;
  bloodPalette[3] = CRGB::Cyan;
  bloodPalette[4] = CRGB::Cyan;
  bloodPalette[5] = CRGB::Cyan;
  bloodPalette[6] = CRGB::LightSalmon;
  bloodPalette[7] = CRGB::LightSalmon;
  bloodPalette[8] = CRGB::Cyan;
  bloodPalette[9] = CRGB::Cyan;
  bloodPalette[10] = CRGB::Cyan;
  bloodPalette[11] = CRGB::Cyan;
  bloodPalette[12] = CRGB::Cyan;
  bloodPalette[13] = CRGB::Cyan;
  bloodPalette[14] = CRGB::LightSalmon;
  bloodPalette[15] = CRGB::LightSalmon;

  alertBtn.begin();

}

void loop()
{

  for (uint16_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette(bloodPalette, (i*255)/NUM_LEDS + offset);
    leds[i].fadeLightBy(220);
  }

  FastLED.show();

  FastLED.delay(1000/FRAMES_PER_SECOND);

  offset++;

  alertBtn.read();
  
  if (alertBtn.wasPressed()) {
    alert();
  }
  
}

void alert()
{
  
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.delay(500);

  for (byte i=0; i<=2; i++) {
    fill_solid(leds, NUM_LEDS, CRGB::Red);
    FastLED.delay(500);
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.delay(500);
    
  }
  
}
