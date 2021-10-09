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
  Serial.println("Verschachtelte Schleifen.");// Nun schicken wir den Begrüßungstext an den Computer.
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS); // Einstellungen für FastLED.
}

/*
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  CRGB farbe{0, 0, 0};

  /*
     Wir fangen bei 0 and und zählen bis 11
     In jedem Schritt erhöhen wir den Wert der Variable j um 1.
     Wir machen das so lange wie j kleiner als 12 ist.

     Jedes mal werden alle Schritte zwischen den zwei Klammern { und } ausgeführt.
  */
  for (int j = 0; j < 12; j++) { // Äußere Schleife.
    // Hier haben wir also die Position für die LED.
    /*
       Jetzt holen wir noch den Wert für die Farbe.
       Der soll sich jedes mal, also für jede LED immer von 0 bis 254 ändern.
       Diese Schleife läuft also für jede LED 255 mal und erhöht i jeweils um 1.
     */
    for (int i = 0; i < 255; i++) { // Innere Schleife.
      FastLED.clear(); // Wir löschen erstmal alle Farben für alle LEDs.
      farbe.red = i; // Wir setzen den farbwert für rot auf i, also nach einander 0,1,2,3,...,254
      leds[j] = farbe; // Wir setzen den neuen Farbwert für die LED an der Stelle j.
      FastLED.show(); // Wir zeigen die neue Farbe an.
      delay(5); // Wir warten eine halbe Sekunde.
    }
  }
}
