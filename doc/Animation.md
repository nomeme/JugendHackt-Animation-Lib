# Animationen

Was sind Animationen? Animationen sind eine Art optische Täuschung in der statische Bilder so schnell hintereinander angezeigt werden, dass für unsere Augen der Eindruck einer flüssigen Bewegung entsteht.
Wenn wir heute von Animationen reden, dann meinen wir eigentlich immer [Stroboskopische Bewegungen](https://de.wikipedia.org/wiki/Beta-Bewegung).
Die Magische Grenze für unsere Augen liegt etwa bei 24 Bildern pro Sekunde.
Was bedeutet das denn jetzt?
Stellen wir uns vor wir haben 24 Bilder von einem Ball auf denen dieser Ball langsam von einer Seite auf die andere Seite roll.
Wenn wir die Bilder nach einander anschauen dann sehen wir nur einen Ball der auf dem Boden liegt.
Wenn wir aber alle 24 Bilder in etwa gleichen Zeitabständen innerhalb einer Sekunde sehen, dann denkt unser Auge, dass sich der Ball über den Boden bewegt.

## Schleifen und Animationen

Wie können wir denn jetzt eine Animation mit useren LEDs und einem Arduino erzeugen?
Dabei hilft uns ein weiteres Konzept in der Programmierung, die Schleife.
Mit einer Schleife können wir Aufgaben immer wieder ausführen und müssen sie nur ein mal aufschreiben.
Wir können auch sagen wie oft diese Aufgaben ausgeführt werden sollen.
Wie Schleifen genau funktionieren könnt ihr [hier](Grundlagen.md#schleifen) sehen.

Schauen wir uns eine Schleife an. Hier handelt es sich um eine `for` schleife.

``` C++
for(int i = 0; i < 12; i++)
{
  // Alles hier wird zwölf mal ausgeführt
}
```

Jede `for` Schleife hat einen Startwert. Wir definieren ihn als eine Ganzzahl mit dem Namen `i` und geben ihr den Wert `0` (`int i = 0`)
Jede `for` Schleife braucht auch eine Abbruchbedingung, sonst würde sie ja unendlich lange weiter laufen. Wir sagen dass die `for` Schleife so lange laufen soll wie unsere Variable `i` kleiner als `12` ist (`i < 12`).
Wie Bedingungen funktionieren wir [hier](Grundlagen.md#bedingungen) nochmal genauer erklährt.
Jede `for` Schleife hat auch einen Bereich in dem man angibt was in jedem Schritt mit dem Startwert passiert.
Hier sagen wir, dass der Startwert in jedem Schritt um den Wert `i` erhöht wird (`i++`). Das `i++` is die kurze Schreibweise für `i = i + 1`. 
In dieser Schleife fangen wir also bei `0` an zu zählen. In jedem Schritt erhöhen wir `i` um den Wert `1` und hören auf sobald `i` nichtmehr kleiner als `12` ist.


### Beispiel

Aber was hat das jetzt mit unseren Animationen zu tun?
Ganz einfach. Wenn wir jetzt in der Schleife Farben für unsere LEDs setzen, dann können wir daraus Animationen basteln.
Schauen wir uns doch den Sketch AnimationSchleife genauer an. Öffnet das Beispiel `Datei|Beispiele|Jugend Hackt Animation-lib|AnimationSchleife`

``` C++
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
```

Habt ihr die Schleife schon entdeckt?
Schauen wir sie uns doch genauer an.

``` C++
  for (int i = 0; i < 12; i++)
  {
    FastLED.clear(); // Wir löschen erstmal alle Farben für alle LEDs.
    leds[i] = farbe; // Wir setzen den neuen Farbwert für die LED an der Stelle i.
    FastLED.show(); // Wir zeigen die neue Farbe an.
    delay(500); // Wir warten eine halbe Sekunde.
  }
```

Hier seht ihr eine Schleife die von `0` bis `11` zählt. Und jedes mal bestimmte Aktionen ausführt.
Zuerst werden alle Farben für alle LEDs gelöscht `FastLED.clear();`.
Nachdem alle Werte gelöscht wurden setzen wir eine neue farbe `leds[i] = farbe;`.
Hier setzen wir eine Farbe für die LED an der Stelle `i`.
Da wir `i` immer um `1` erhöhen setzen wir in jedem Schritt die Farbe für eine andere LED.
Mit `FastLED.show();` zeigen wir die neue Farbe an.
Dann warten wir eine halbe Sekunde  `delay(500);`.

Soweit so gut. Drückt den Upload Knopf und schaut euch an was passiert.
Spielt mit dem Quelltext herum. Was passiert denn zum Beispiel wenn ihr die Wartezeit verändert.
Die Funktion `delay()` nimmt die Wartezeit in millisekunden entgegen. Eine Millisekunde ist ein Tausendstel einer sekunde.
Wir haben gelernt, dass das Auge eine flüssige Bewegung ab 24 Bildern in der Sekunde wahrnimmt.
Wenn wir den Wert für `delay()` auf `40` setzen warten wir 40 millisekunden und ändern damit die Farbe 25 mal in der Sekunde.
Was passiert wenn ihr statt `delay(500)` einfach `delay(40)` schreibt?
Glückwunsch ihr habt eure erste Animation programmiert.
Das war doch garnicht so schwer oder?
