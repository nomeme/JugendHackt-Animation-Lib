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
  uint8_t basis = 127; // Hier definieren wir unseren Basiswert für die Farbe.

  // Hier sagen wir, dass farbe für Rot den wert von basis, also 128 annehmen soll.
  CRGB farbe{basis, 0, 0};
  // Hier sagen wir, dass farbeDoppelt für Rot doppelt so hell wie basis sein soll.
  // basis * 2 multipliziert den Wert der Variable basis mit 2.
  CRGB farbeDoppelt{basis * 2, 0, 0};
  // Hier sagen wir, dass farbeHalb für Rot halb so hell wie basis sein soll.
  // basis / 2 dividiert den Wert der Variable basis durch 2.
  CRGB farbeHalb{basis / 2, 0, 0};
  // Hier sagen wir, dass farbePlus um 32 Einheiten heller sein soll als basis.
  // basis + 32 addiert den Wert von 32 auf basis.
  CRGB farbePlus{basis + 100, 0, 0};
  // Hier sagen wir, dass farbeMinus um 32 Einheiten dunkler sein soll als basis.
  // basis + 32 addiert den Wert von 32 auf basis.
  CRGB farbeMinus{basis - 100, 0, 0};
  /* 
   * Hier sagen wir, dass für die farbeMix für rot den Wert basis annehmen soll
   * und für grün halb so hell wie basis sein soll.
   */
  CRGB farbeMix{basis, basis / 2, 0};
  /*
   * Hier sagen wir dass farbeBlau für blau halb so hell sein soll wie farbe für rot.
   */
  CRGB farbeBlau{0, 0, farbe.red / 2};
   
  leds[0] = farbe; // Wir setzen die aktuelle Farbe für unseren Pixel
  FastLED.show(); // Wir sagen FastLed, dass es die neue Farbe anzeigen soll.
  delay(1000); // Wir warten eine Sekunde.
  leds[0] = farbeDoppelt;
  FastLED.show();
  delay(1000);
  leds[0] = farbeHalb;
  FastLED.show();
  delay(1000);
  leds[0] = farbePlus;
  FastLED.show();
  delay(1000);
  leds[0] = farbeMinus;
  FastLED.show();
  delay(1000);
  leds[0] = farbeMix;
  FastLED.show();
  delay(1000);
  leds[0] = farbeBlau;
  FastLED.show();
  delay(1000);


  FastLED.clear();
  FastLED.show();
  delay(3000); // Wir warten drei sekunden.
}
