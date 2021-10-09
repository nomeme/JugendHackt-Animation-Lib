#include <FastLED.h> // Wir benutzen die FastLED Bibliothek.

const uint8_t NUM_LEDS = 12; // Wir definieren wie viele LEDs wir steuern möchten.
const uint8_t LED_PIN = 6; // Wir definieren an welchem Pin unsere LEDs angeschlossen sind.

/*
   Das hier ist sowas wie eine Liste von LEDs, die wir für die FastLED Bibliothek brauchen.
   Wie das genau funktioniert schauen wir uns später an.
*/
CRGB leds[NUM_LEDS];

/*
 * Hier deklarieren wir eine Variable für Farbe. Wenn wir eine Variable hier deklarieren,
 * dann existiert sie so lange wie unser Arduino läuft.
 */
CRGB farbe;
/*
   Hier ist wieder unsere Setup Methode.
*/
void setup() {
  Serial.begin(115200);// Wir stellen wieder unsere Übertragungsrate ein.
  delay(1000);// Dann warten wir eine Sekunde.
  Serial.println("Unsere erste Ampel.");// Nun schicken wir den Begrüßungstext an den Computer.
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS); // Einstellungen für FastLED.
}



/*
   Hier führen wir Berechnungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  /*
   * Wir definieren unsere Farben für die Ampel.
   */
  CRGB rot{255, 0, 0};
  CRGB gruen{0, 255, 0};
  CRGB gelb{255, 255, 0};

  /*
   * Hier kommen unsere Bedingungen.
   * Unsere Ampel schaltet immer von grün nach gelb und dann nach rot.
   * Das machen wir über diese Bedingungen.
   */
  if(farbe == rot) { // Wenn farbe jetzt rot ist
    farbe = gruen; // Dann ändern wir farbe zu grün
  }else if(farbe == gruen) { // Wenn farbe nicht rot ist aber grün
    farbe = gelb; // Dann ändern wir farbe zu gelb.
  } else { // Wenn farbe weder rot noch grün ist.
    farbe = rot; // Dann ändern wir farbe zu rot.
  }
  // Wir setzen die Farbe der LED auf den wert von farbe.
  leds[0] = farbe;
  // Wir zeigen die aktuelle Farbe an.
  FastLED.show();
  // Wir warten eine sekunde
  delay(1000);
}
