# Animationen

Was sind Animationen? Animationen sind eine Art optische Täuschung in der statische Bilder so schnell hintereinander angezeigt werden, dass für unsere Augen der Eindruck einer flüssigen Bewegung entsteht.
Wenn wir heute von Animationen reden, dann meinen wir eigentlich immer [Stroboskopische Bewegungen](https://de.wikipedia.org/wiki/Beta-Bewegung).
Die Magische Grenze für unsere Augen liegt etwa bei 24 Bildern pro Sekunde.
Was bedeutet das denn jetzt?
Stellen wir uns vor wir haben 24 Bilder von einem Ball auf denen dieser Ball langsam von einer Seite auf die andere Seite rollt.
Wenn wir die Bilder nach einander anschauen dann sehen wir nur einen Ball der auf dem Boden liegt.
Wenn wir aber alle 24 Bilder in etwa gleichen Zeitabständen innerhalb einer Sekunde sehen, dann denkt unser Auge, dass sich der Ball über den Boden bewegt.

## Schleifen und Helligkeit

Wie können wir denn jetzt eine Animation mit unseren LEDs und einem Arduino erzeugen?
Dabei hilft uns ein weiteres Konzept in der Programmierung, die Schleife.
Mit einer Schleife können wir Aufgaben immer wieder ausführen und müssen sie nur ein mal aufschreiben.
Wir können auch sagen wie oft diese Aufgaben ausgeführt werden sollen.
Wie Schleifen genau funktionieren könnt ihr [hier](Grundlagen.md#schleifen) sehen.

Schauen wir uns eine Schleife an. Hier handelt es sich um eine `for` schleife.

``` C++
for(int i = 0; i < 255; i++)
{
  // Alles hier wird 255 mal ausgeführt
}
```

Jede `for` Schleife hat einen Startwert. Wir definieren ihn als eine Ganzzahl mit dem Namen `i` und geben ihr den Wert `0` (`int i = 0`)
Jede `for` Schleife braucht auch eine Abbruchbedingung, sonst würde sie ja unendlich lange weiter laufen. Wir sagen, dass die `for` Schleife so lange laufen soll, wie unsere Variable `i` kleiner als `255` ist (`i < 255`).
Wie Bedingungen funktionieren wird [hier](Grundlagen.md#bedingungen) nochmal genauer erklärt.
Jede `for` Schleife hat auch einen Bereich in dem man angibt was in jedem Schritt mit dem Startwert passiert.
Hier sagen wir, dass der Startwert in jedem Schritt um den Wert `i` erhöht wird (`i++`). Das `i++` is die kurze Schreibweise für `i = i + 1`. 
In dieser Schleife fangen wir also bei `0` an zu zählen. In jedem Schritt erhöhen wir `i` um den Wert `1` und hören auf sobald `i` nichtmehr kleiner als `255` ist.

### Beispiel

Aber genug erklärt, lasst uns mal anschauen was man denn jetzt damit machen kann. Öffnet das Beispiel `Datei|Beispiele|Jugend Hackt Animation-lib|C_01_Animation`

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
  CRGB farbe{0, 0, 0};

  /*
     Wir fangen bei 0 and und zählen bis 254
     In jedem Schritt erhöhen wir den Wert der Variable i um 1.
     Wir machen das so lange wie i kleiner als 255 ist.

     Jedes mal werden alle Schritte zwischen den zwei Klammern { und } ausgeführt.
  */
  for (int i = 0; i < 255; i++)
  {
    FastLED.clear(); // Wir löschen erstmal alle Farben für alle LEDs.
    farbe.red = i; // Wir setzen den farbwert für rot auf i, also nach einander 0,1,2,3,...,254
    leds[0] = farbe; // Wir setzen den neuen Farbwert für die LED an der Stelle 0.
    FastLED.show(); // Wir zeigen die neue Farbe an.
    delay(40); // Wir warten eine halbe Sekunde.
  }
}
```

Der Anfang sieht ja schon sehr ähnlich aus. Aber was passiert denn nun in der `loop()` Methode?
Zuerst setzen wir den Wert für unsere Farbe auf schwarz.

``` C++
  CRGB farbe{0, 0, 0};
```

Das kennen wir ja schon.
Danach kommt aber etwas neues, unsere `for` Schleife.
Schauen wir uns mal genau an was in den Klammern der `for` Schleife steht.

``` C++
  for (int i = 0; i < 255; i++)
```

Wir deklarieren also eine Ganzzahlvariable mit dem Namen `i` und geben dieser den Wert `0` (`int i = 0`).
Dann legen wir die Abbruchbedingung fest (`i < 255`). Solange `i` also kleiner `255` ist werden die Aktionen in der `for` Schleife ausgeführt. Wir müssen aber auch noch festlegen, was mit der Variable `i` nach jedem Schleifendurchlauf passiert.
Das steht ganz am Ende (`i++`). Also wird nach jedem Schleifendurchlauf der Wert von `i` um `1` erhöht.
Aber jetzt wissen wir immernoch nicht was eigentlich in der Schleife passiert.
Schauen wir uns das Ganze doch einmal genauer an, so kompliziert ist das ja erstmal garnicht.

``` C++
  for (int i = 0; i < 255; i++)
  {
    FastLED.clear(); // Wir löschen erstmal alle Farben für alle LEDs.
    farbe.red = i; // Wir setzen den farbwert für rot auf i, also nach einander 0,1,2,3,...,254
    leds[0] = farbe; // Wir setzen den neuen Farbwert für die LED an der Stelle 0.
    FastLED.show(); // Wir zeigen die neue Farbe an.
    delay(40); // Wir warten eine halbe Sekunde.
  }
```

Wenn wir die Befehle innerhalb der Schleife der Reihe nach durchgehen, stellen wir fest, dass wir eigentlich nichts anderes tun, als bisher.
Mit `FastLED.clear();` löschen wir ersteinmal alle Farben.
In der nächsten Zeile setzen wir mit dem Befehl `farbe.red = i;` den Rotwert unserer Farbe auf den Wert der Variable `i`.
Soweit alles wie bisher. Im nächsten Schritt setzen wir dann mit dem Befehl `leds[0] = farbe;` für die erste LED (`leds[0]`) unseren Farbwert (`farbe`).
Danach sagen wir noch der `FastLed` Bibliothek, dass sie die Farben anzeigen soll (`FastLED.show();`) und warten dann `40` Millisikunden.

Soweit ist das alles wie bisher. Der Unterschied ist, das wir das alles jetzt genau `255` mal machen und sich der Wert der Variable `i` in jedem Schritt um den Wert `1` erhöht.
Das Bedeutet dass unsere LED in jedem Schritt etwas heller leuchtet.

Drückt den Upload Knopf und schaut euch an, was passiert.
Am Anfang wird unsere LED schnell immer Heller, aber am Ende scheint sich garnichts mehr zu verändern. Ist das nicht komisch?
Haben wir einen Fehler in unserem Programm?
Nein, das ist ganz normal. Unser Auge nimmt Helligkeiten [logarithmisch](https://de.wikipedia.org/wiki/Logarithmus) war.
Das bedeutet, dass je Heller es wird, desto weniger groß erscheint unserem Auge der Unterschied. Das ist also völlig normal und wir haben tatsächlich alles richtig gemacht.
Wenn ihr dazu etwas nachlesen möchtet gibt es auf [Wikipedia](https://de.wikipedia.org/wiki/Helligkeit) eine Erklärung dazu.

## Schleifen und Animationen

Das war ja schon einmal wirklich interessant. Mit der Hilfe von [Schleifen](Grundlagen.md#schleifen) können wir also den Eindruck von einer kontinuierlichen Veränderung erzeugen. Wir können aber noch so einiges mehr damit tun.
Schauen wir doch mal wie uns ein [Array](Grundlagen.md#arrays) helfen kann den Eindruck einer flüssigen Bewegung zu erzeugen.

Wir haben ja einen Pixel-Ring mit zwölf LEDs. Wie können wir denn damit Bewegung simulieren?
Wie wäre es denn, wenn wir versuchen unseren leuchtenden Pixel über alle LEDs springen zu lassen?
Das hört sich erstmal nach viel Arbeit an, weil wir ja einzeln jede LED ein und auschalten müssen.
Aber mit der Hilfe von [Array](Grundlagen.md#arrays) und [Schleifen](Grundlagen.md#schleifen) hält sich der Aufwand tatsächlich in Grenzen.

Das Prinzip ist auch ganz einfach. Anstatt die Position der LED, deren Farbwert wir ändern möchten, immer mit Zahlen anzugeben, wie wir das bisher gemacht haben.

``` C++
  leds[0] = farbe;
```

Machen wir das Ganze jetzt einfach mit einer Variable, zum Beispiel `i`.

``` C++
  int i = 0;
  leds[i] = farbe;
```

Und jetzt seht ihr bestimmt schon wo das hinführen wird.

``` C++
  for (int i = 0; i < 12; i++)
  {
    FastLED.clear();
    leds[i] = farbe;
    FastLED.show();
    delay(500);
  }
```

Und schon setzen wir nach einander den Farbwert für jede LED.

### Beispiel

Aber was hat das jetzt mit unseren Animationen zu tun?
Ganz einfach. Wenn wir jetzt in der Schleife Farben für unsere LEDs setzen, dann können wir daraus Animationen basteln.
Schauen wir uns doch den Sketch AnimationSchleife genauer an. Öffnet das Beispiel `Datei|Beispiele|Jugend Hackt Animation-lib|C_02_AnimationSchleife`.

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
Nachdem alle Werte gelöscht wurden setzen wir eine neue Farbe `leds[i] = farbe;`.
Hier setzen wir eine Farbe für die LED an der Stelle `i`.
Da wir `i` immer um `1` erhöhen setzen wir in jedem Schritt die Farbe für eine andere LED.
Mit `FastLED.show();` zeigen wir die neue Farbe an.
Dann warten wir eine halbe Sekunde  `delay(500);`.

Soweit so gut. Drückt den Upload Knopf und schaut euch an was passiert.
Spielt mit dem Quelltext herum. Was passiert denn zum Beispiel wenn ihr die Wartezeit verändert.
Die Funktion `delay()` nimmt die Wartezeit in Millisekunden entgegen. Eine Millisekunde ist ein Tausendstel einer Sekunde.
Wir haben gelernt, dass das Auge eine flüssige Bewegung ab 24 Bildern in der Sekunde wahrnimmt.
Wenn wir den Wert für `delay()` auf `40` setzen warten wir 40 Millisekunden und ändern damit die Farbe 25 mal in der Sekunde.
Was passiert wenn ihr statt `delay(500)` einfach `delay(40)` schreibt?
Glückwunsch ihr habt eure erste Animation programmiert.
Das war doch garnicht so schwer oder?

## Verschachtelte Schleifen

In den zwei vorhergehenden Beispielen haben wir gesehen wie [Schleifen](Grundlagen.md#schleifen) funktionieren, wofür man [Arrays](Grundlagen.md#arrays) braucht und was das alles mit Animationen zu tun hat.
Wir haben damit die Helligkeit von LEDs verändert oder Bewegung simuliert. Aber können wir das auch kombinieren?

Was wäre denn, wenn wir jede LED einzeln langsam aufleuchten lassen wollten?
Also haben wir eine Schleife in der wir die Helligkeit von `0` bis `255` erhöhen.

``` C++
  for (int i = 0; i < 255; i++)
  {
    FastLED.clear(); // Wir löschen erstmal alle Farben für alle LEDs.
    farbe.red = i; // Wir setzen den farbwert für rot auf i, also nach einander 0,1,2,3,...,254
    leds[0] = farbe; // Wir setzen den neuen Farbwert für die LED an der Stelle 0.
    FastLED.show(); // Wir zeigen die neue Farbe an.
    delay(40); // Wir warten eine halbe Sekunde.
  }
```

Und eine Schleife bei der wir jede einzelne LED ansteuern.

``` C++
for (int i = 0; i < 12; i++) {
    FastLED.clear(); // Wir löschen erstmal alle Farben für alle LEDs.
    leds[i] = farbe; // Wir setzen den neuen Farbwert für die LED an der Stelle i.
    FastLED.show(); // Wir zeigen die neue Farbe an.
    delay(500); // Wir warten eine halbe Sekunde.
  }
```

Aber wie können wir das jetzt kombinieren?
Das ganze könne wir erreichen, wenn wir diese beiden Schleifen verschachteln.
Aber fangen wir nochmal von vorne an.
Wir wollen dass jede LED einzeln langsam aufleuchtet. Also sich die Helligleit für diese LED langsam von `0` auf `255` erhöht.
Dazu nehmen wir einfach unsere Schleife aus dem ersten Beispiel und ersetzen den Zahlenwert `0` durch die Variable `j`.

``` C++
  for (int i = 0; i < 255; i++)
  {
    FastLED.clear(); // Wir löschen erstmal alle Farben für alle LEDs.
    farbe.red = i; // Wir setzen den farbwert für rot auf i, also nach einander 0,1,2,3,...,254
    leds[j] = farbe; // Wir setzen den neuen Farbwert für die LED an der Stelle 0.
    FastLED.show(); // Wir zeigen die neue Farbe an.
    delay(40); // Wir warten eine halbe Sekunde.
  }
```

Aber woher kommt jetzt das `j` und warum?
Ganz einfach. Wenn wir jetzt eine zweite `for` Schleife um unsere Schleife herum packen, dann können wir den Wert für `j` wie im letzten Beispiel immer um den Wert `1` erhöhen und so immer zur nächsten LED springen.

``` C++
  for (int j = 0; j < 12; j++) { // Äußere Schleife.
    for (int i = 0; i < 255; i++) { // Innere Schleife.
      FastLED.clear(); // Wir löschen erstmal alle Farben für alle LEDs.
      farbe.red = i; // Wir setzen den farbwert für rot auf i, also nach einander 0,1,2,3,...,254
      leds[j] = farbe; // Wir setzen den neuen Farbwert für die LED an der Stelle j.
      FastLED.show(); // Wir zeigen die neue Farbe an.
      delay(5); // Wir warten eine halbe Sekunde.
    }
  }
```

Was passiert hier jetzt?
Die äußere Schleife zählt den Wert der Variable `j` von `0` bis `11` immer um eins nach oben.
Die innere Schleife wird daher `12` mal neu gestartet. Jedes Mal ist der Wert für die Variable `j` um den Wert `1` größer.
Die innere Schleife läuft dann selbst `255` mal und zählt den Wert `i` von `0` bis `254` hoch.
Wir verwenden die Variable `j` um die Position der LED zu wählen (`leds[j] = farbe;`), also `0` bis `11`.
Wir verwenden die Variable `i` um den Rotwert unserer Farbe zu setzen (`farbe.red = i;`), also `0` bis `255`.
Das bedeutet, dass wir für jede LED genau `255` mal die Farbe ändern und dann zur nächsten LED springen.
Schauen wir uns das Ganze doch mal im Beispiel an.

### Beispiel

Das Beispiel hierzu findet ihr unter `Datei|Beispiele|Jugend Hackt Animation-lib|C_03_Verschachtelt`.

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
```

Aber was passiert hier jetzt genau?
Bis auf die zwei Schleifen bleibt erstmal alles gleich.

Die äußere Schleife kümmert sich darum die Position der LED auszuwälen, deren Farbe wir verändern wollen.
Wir wählen die Position der LED mit der Variable `j` aus (`leds[j] = farbe;`).
Aus diesem Grund zählt sie die äußere Schleife die Variable `j` von dem Wert `0` bis zum Wert `11` hoch.

``` C++
  for (int j = 0; j < 12; j++) { // Äußere Schleife.
```

Mit der inneren Schleife bestimmen wir den Farbwert den die LED annehmen soll. Den Farbwert bestimmen wir mit der Variablen `i` (`farbe.red = i;`).
Aus diesem Grund zählt die innere Schleife den Wert der Variablen `j` vom Wert `0` bis zum Wert `254` hoch.

``` C++
    for (int i = 0; i < 255; i++) { // Innere Schleife.
```

In der inneren Schleife löschen wir dann erstmal alle gespeicherten Farbwerte mit `FastLED.clear();`.
Danach setzen wir den neuen Farbwert `farbe.red = i;`.
Im nächsten Schritt setzen wir den Farbwert hn für die LED an der Position `j` mit dem Befehl `leds[j] = farbe;`.
Jetzt müssen wir der `FastLED` Bibliothek noch sagen, dass sie die LEDs auch einfärben soll.
Das machen wir mit dem Befehl `FastLED.show();` und danach warten wir noch fünf Millisikunden `delay(5);`.

Wichtig um zu verstehen was hier passiert ist außerdem, dass erst alle schritte der inneren Schleife abgearbeitet werden müssen, bevor wir den nächsten Schritt der äußeren Schleife starten.
Denn so lange die Abbruchbedingung der inneren Schleife (`j < 255`) nicht erfüllt ist, machen wir ja immer weiter und erhöhen `j` um den Wert `1`. Erreicht die Variable `j` dann den Wert `255` is `j` nichtmer kleiner als `255`, sondern gleich und wir verlassen die innere Schleife. 

Am Anfang setzen wir also in der äußeren Schleife für `j` den Wert `0`.
Dann gehen wir in die innere Schleife und setzen für die Variable `i` alle Werte von `0` bis `254`.
Wir färben also die LED an der Position `0` mit den Werten `0` bis `255` für Rot ein.
Erst danach gehen wir zurück in die äußere Schleife und machen das alles nochmal für die LED an der Position `1`, `2` bis `11`.

---

[Anfang](../Readme.md) | [Zurück](Farben.md)

---

[Anfang](../Readme.md) | [Setup](Setup.md) | [Grundlagen](Grundlagen.md) | [Von Farben und Physik](Farben.md) | [Animationen](Animation.md)

 ---

