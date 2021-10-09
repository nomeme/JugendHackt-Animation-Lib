#include <FastLED.h> // Wir benutzen die FastLED Bibliothek.

const uint8_t NUM_LEDS = 12; // Wir definieren wie viele LEDs wir steuern möchten.
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
  Serial.println("Animationen und Schleifen.");// Nun schicken wir den Begrüßungstext an den Computer.
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS); // Einstellungen für FastLED.
}

/*
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  CRGB farbe{255, 64, 0};

  /*
     Wir fangen bei 0 and und zählen bis 11
     In jedem Schritt erhöhen wir den Wert der Variable i um 1.
     Wir machen das so lange wie i kleiner als 12 ist.

     Jedes mal werden alle Schritte zwischen den zwei Klammern { und } ausgeführt.
  */
  for (int i = 0; i < 12; i++)
  {
    FastLED.clear(); // Wir löschen erstmal alle Farben für alle LEDs.
    leds[i] = farbe; // Wir setzen den neuen Farbwert für die LED an der Stelle i.
    FastLED.show(); // Wir zeigen die neue Farbe an.
    delay(500); // Wir warten eine halbe Sekunde.
  }
}
