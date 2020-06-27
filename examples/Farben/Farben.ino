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
  Serial.println("Schau mal unsere Farben an.");// Nun schicken wir den Begrüßungstext an den Computer.
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS); // Einstellungen für FastLED.
}

/*
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  CRGB rot; // Wir erzeugen eine Variable für unsere rote farbe
  rot.red = 255; // Wir setzen den Wert für rot auf ganz hell
  rot.green = 0; // Wir setzen den Wert für grün auf ganz dunkel
  rot.blue = 0; // Wir setzen den Wert für blau auf ganz dunkel

  /*
   * Und hier nochmal das Ganze in Grün.
   */
  CRGB gruen;
  gruen.red = 0;
  gruen.green = 255;
  gruen.blue = 0;

  /*
   * Und hier das Ganze in Blau.
   */
  CRGB blau;
  blau.red = 0;
  blau.green = 0;
  blau.blue = 255;

  leds[0] = rot; // Wir setzen die aktuelle Farbe für unseren Pixel
  FastLED.show(); // Wir sagen FastLed, dass es die neue Farbe anzeigen soll.
  delay(1000); // Wir warten eine Sekunde.
  leds[0] = gruen;
  FastLED.show();
  delay(1000);
  leds[0] = blau;
  FastLED.show();
  delay(1000);
  FastLED.clear(); // Wir löschen alle Farben.
  FastLED.show();
  delay(1000);

  // Um Schreibarbeit zu sparen können wir Farben auch so definieren.
  CRGB meineTolleFarbe{255, 0, 128}; // Rot ist 255, grün ist 0 und blau ist 128.
  leds[0] = meineTolleFarbe;
  FastLED.show();
  delay(1000);
}
