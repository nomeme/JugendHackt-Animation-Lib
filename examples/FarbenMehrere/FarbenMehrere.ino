#include <FastLED.h> // Wir benutzen die FastLED Bibliothek.

const uint8_t NUM_LEDS = 12; // Wir definieren wie viele LEDs wir steuern möchten. Unser LED Ring hat 12.
const uint8_t LED_PIN = 6; // Wir definieren an welchem Pin unsere LEDs angeschlossen sind.

/*
   Das hier ist sowas wie eine Liste von LEDs, die wir für die FastLED Bibliothek brauchen.
*/
CRGB leds[NUM_LEDS];

/*
   Hier ist wieder unsere Setup Methode.
*/
void setup() {
  Serial.begin(115200);// Wir stellen wieder unsere Übertragungsrate ein.
  delay(1000);// Dann warten wir eine Sekunde.
  Serial.println("Farben und Mathe.");// Nun schicken wir den Begrüßungstext an den Computer.
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS); // Einstellungen für FastLED.
}

/*
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  uint8_t hell = 255;

  CRGB rot{hell, 0, 0};
  CRGB gruen{0, hell, 0};
  CRGB blau{0, 0, hell};

  CRGB gelb = rot + gruen;
  CRGB cyan = gruen + blau;
  CRGB magenta = rot + blau;
  CRGB weiss = rot + gruen + blau;

  // Wir setzen die aktuelle Farben für unsere Pixel.
  leds[0] = rot; 
  leds[1] = gruen;
  leds[2] = blau;
  leds[3] = gelb;
  leds[4] = cyan;
  leds[5] = magenta;
  leds[6] = weiss;
  FastLED.show();
  delay(2000);

  FastLED.clear();
  FastLED.show();
  delay(3000); // Wir warten drei sekunden.
}
