#include <FastLED.h> // Wir benutzen die FastLED Bibliothek.

const uint8_t NUM_LEDS = 1; // Wir definieren wie viele LEDs wir steuern möchten.
const uint8_t LED_PIN = 6; // Wir definieren an welchem Pin unsere LEDs angeschlossen sind.

/*
   Das hier ist sowas wie eine Liste von LEDs, die wir für die FastLED Bibliothek brauchen.
   Wie das genau funktioniert schauen wir uns später an.
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
  /*
   * Zuerst definieren wir unsere Grundfarben, mit denen wir mischen wollen.
   */
  CRGB rot{hell, 0, 0};
  CRGB gruen{0, hell, 0};
  CRGB blau{0, 0, hell};

  // Nun können wir anfangen zu mischen.
  CRGB gelb = rot + gruen;
  CRGB cyan = gruen + blau;
  CRGB magenta = rot + blau;

  CRGB weiss = rot + gruen + blau;

  // Wir können Farben auch durch subtraktion erzeugen.
  CRGB magenta2 = weiss - gruen;
  CRGB gruen2 = weiss - magenta;
  
  leds[0] = rot; // Wir setzen die aktuelle Farbe für unseren Pixel
  FastLED.show(); // Wir sagen FastLed, dass es die neue Farbe anzeigen soll.
  delay(1000); // Wir warten eine Sekunde.
  leds[0] = gruen;
  FastLED.show();
  delay(1000);
  leds[0] = blau;
  FastLED.show();
  delay(1000);
  leds[0] = gelb;
  FastLED.show();
  delay(1000);
  leds[0] = cyan;
  FastLED.show();
  delay(1000);
  leds[0] = magenta;
  FastLED.show();
  delay(1000);
  leds[0] = weiss;
  FastLED.show();
  delay(1000);
  leds[0] = magenta2;
  FastLED.show();
  delay(1000);
  leds[0] = gruen2;
  FastLED.show();
  delay(1000);

  FastLED.clear();
  FastLED.show();
  delay(3000); // Wir warten drei sekunden.
}
