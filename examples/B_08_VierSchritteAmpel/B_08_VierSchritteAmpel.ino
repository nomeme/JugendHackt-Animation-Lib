#include <FastLED.h> // Wir benutzen die FastLED Bibliothek.

const uint8_t NUM_LEDS = 12; // Wir definieren wie viele LEDs wir steuern möchten.
const uint8_t LED_PIN = 6; // Wir definieren an welchem Pin unsere LEDs angeschlossen sind.

CRGB leds[NUM_LEDS];

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
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  /*
     Wir definieren unsere Farben für die Ampel.
  */
  // Die dritte LED soll immer rot leuchten.
  CRGB rot{255, 0, 0};
  // Die zweite LED soll immer gelb leuchten.
  CRGB gelb{255, 255, 0};
  // Die erste LED soll immer grün leuchten.
  CRGB gruen{0, 255, 0};

  /*
     Hier kommen unsere Bedingungen.
     Unsere Ampel schaltet immer von grün nach gelb und dann nach rot.
     Nach rot sollen rot und gelb gleichzeitig leuchten.
     Das machen wir über diese Bedingungen.
     Da immer eine andere LED mit einer anderen Farbe leuchtet schauen wir uns
     auch immer die zur Farbe passende LED an.
  */
  if (leds[0] == gruen) { // Wenn die erste LED, also an der Stelle 0 grün leuchtet.
    FastLED.clear(); // Dann löschen wir zuerst alle LEDs.
    leds[1] = gelb; // Und dann setzen wir die Farbe der zweiten LED, also an der Stelle 1 auf gelb.
  } else if (leds[1] == gelb) { // Wenn die erste LED nicht grün ist aber die zweite LED gelb ist.
    /*
       Hier haben wir eine verschachtelte Bedingung.
       Ja richtig, wir können in einer Bedinging eine weitere Bedingung einbauen.

       Es gibt jetzt zwei Zustände in denen die gelbe LED leuchtet.
       Das ist einmal, wenn nur die gelbe LED leuchtet und einmal, wenn die gelbe und die rote LED leuchten.
       Das überprüfen wir hier.
    */
    if (leds[2] == rot) { // Wenn die gelbe LED und die rote LED leuchten.
      FastLED.clear(); // Dann löschen wir zuerst alle LEDs.
      leds[0] = gruen; // Und dann setzen wir die Farbe der ersten LED, also an der Stelle 0 auf grün.
    } else { // Wenn die gelbe LED leuchtet und die rote LED nicht leuchtet.
      FastLED.clear(); // Dann löschen wir zuerst alle LEDs.
      leds[2] = rot; // Und dann setzen wir die Farbe der dritten LED, also an der Stelle 2 auf rot.
    }
  } else { // Wenn alle Fälle nicht zugetroffen haben.
    FastLED.clear(); // Dann löschen wir zuerst alle LEDs.
    leds[1] = gelb; // Und dann setzen wir die Farbe der zweiten LED, also an der Stelle 1 auf gelb.
    leds[2] = rot; // Und due dritte LED, also an der Stelle 2 auf rot.
  }
  // Wir zeigen die aktuelle Farbe an.
  FastLED.show();
  // Wir warten eine sekunde
  delay(1000);
}
