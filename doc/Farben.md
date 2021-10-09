# Von Farben und Physik

Jeder von euch kennt Farben. Es gibt unglaublich viele davon und man kann sie mit einander mischen und neue Farben erzeugen.
In diesem Kapitel wollen wir nichts anderes tun als Farben zu erzeugen und sie zu mischen um zu sehen was daraus entsteht.
Um das tun zu können schauen wir uns zuerst einmal an, wie das ganze funktioniert.

## Die Physik der Farben

Vereinfacht gesagt gehen wir davon aus, dass es die drei Grundfarben Rot, Grün und Blau gibt. Aus denen lassen sich alle anderen Farben erzeugen. Um euch davon zu überzeugen, dass das nicht ganz falsch zu sein scheint, müsst ihr einfach nur auf euer Computerdisplay schauen. Jeder Pixel auf eurem Display besteht aus drei Farbpunken, die unterschiedlich hell leuchten und damit einen unglaublich großen Farbbereich erzeugen können. Dabei ist es erstmal egal ob `OLED` oder `TFT`. Die theoretischen Grundlagen für das Mischen von Licht bleiben die gleichen.

Wir werden auch mit Pixeln arbeiten, nur sind unsere ein bisschen größer. Sie bestehen aus drei LEDs mit den Farben Rot, Grün und Blau.

## Farben Programmieren

Wir können die Helligkeit für jede Farbe einstellen und so unsere eigenen Farben definieren.
Dafür verwenden wir die [FastLED](https://github.com/FastLED/FastLED) Bibliothek, die es uns erlaubt für jeden unserer Pixel eine Farbe zu definieren. Dafür gibt es in dieser Bibliothek einen Typ mit dem wir den Anteil der drei Grundfarben Rot, Grün und Blau für jeden Pixel angeben können.

``` C++
struct CRGB {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};
```

Jeder Pixel hat also eine `uint8_t` Variable für Rot, Grün und Blau. Das `uint8_t`  steht für den Typen der Variable, `red`, `green` und `blue` sind die Namen der Variablen. 
Wenn ihr nicht wisst was Variablen sind. [Hier](Grundlagen.md#variablen) steht genauer was das bedeutet.
Der Typ sagt uns was die Variable sein soll. In unserem Fall eine Ganzzahl (Integer oder `int`). Sie ist ohne Vorzeichen, also nur positive Werte (unsigned, daher das u). Und sie ist 8 Bit groß, kann also Zahlen von 0 bis 255 speichern.
Wenn ihr wissen möchtet was Datentypen sind, könnt ihr [hier](Grundlagen.md#datentypen) etwas mehr darüber lesen.


Wie definieren wir nun eine Farbe?
Nun zuerst brauchen wir eine Variable vom typ CRGB. Das machen wir einfach wie unten gezeigt.

``` C++
CRGB rot;
```

Jetzt haben wir einen Pixel an dem wir die Farbe einstellen können.
Wie die Variable heisst ist erstmal egal. Aber es macht natürlich Sinn der Variable einen Wert zu geben der beschreibt was es sein soll. Darum nennen wir unsere Variable erst einmal `rot`.

``` C++
rot.red = 255;
rot.green = 0;
rot.blue = 0;
```

Da wir einen roten Pixel haben wollen stellen wir die Farbe des Pixels ein.
Damit der Pixel richtig rot leuchtet stellen wir den Wert für Rot auf ganz hell, also `255`.
Alle anderen Werte stellen wir auf ganz dunkel, also `0`.

Wir können auch einen grünen Pixel bauen.

``` C++
CRGB gruen;
gruen.red = 0;
gruen.green = 255;
gruen.blue = 0;
```

Oder einen blauen Pixel.

``` C++
GRGB blau;
blau.red = 0;
blau.green = 0;
blau.blue = 255;
```

Aber Informatiker sind ja alle schreibfaul. Aus diesem Grund können wir das alles auch so schreiben.

``` C++
CRGB rot{255, 0, 0}; // Rot ganz hell, rest dunkel
CRGB gruen{0, 255, 0}; // Blau ganz hell, rest dunkel
CRGB blau{0, 0, 255}; // Grün ganz hell, rest dunkel
```

So setzen wir die Werte für die Farben `Rot`, `Grün` und `Blau`, in genau dieser Reihenfolge direkt beim Erzeugen der Variable.
Sehr praktisch oder?

### Beispiel

Es wird Zeit dass wir das alles mal selbst ausprobieren. Öffnet das Beispiel `Datei|Beispiele|Jugend Hackt Animation-lib|B_01_Farben` und schaut euch den Quelltext an.

``` C++
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
   Hier führen wir Berechnungen aus und schicken die Ergebnisse an den Computer.
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
```

Das alles sieht erstmal nach viel aus, aus diesem Grund schauen wir uns alles Schritt für Schritt an, dann werden wir sehen, dass das alles garnicht so kompliziert ist wie es vielleicht im ersten Moment aussieht.

``` C++
#include <FastLED.h> // Wir benutzen die FastLED Bibliothek.

const uint8_t NUM_LEDS = 1; // Wir definieren wie viele LEDs wir steuern möchten.
const uint8_t LED_PIN = 6; // Wir definieren an welchem Pin unsere LEDs angeschlossen sind.

/*
   Das hier ist sowas wie eine Liste von LEDs, die wir für die FastLED Bibliothek brauchen.
   Wie das genau funktioniert schauen wir uns später an.
*/
CRGB leds[NUM_LEDS];
```

Hier definieren wir alles für die **FastLED** library. Wie das genau funktioniert schauen wir uns später genauer an.
Im Wesentlichen sagen wir hier nur ein wie viele LEDs wir haben und an welchem Pin des Arduinos wir die LEDs angeschlossen haben.

``` C++
void setup() {
  Serial.begin(115200);// Wir stellen wieder unsere Übertragungsrate ein.
  delay(1000);// Dann warten wir eine Sekunde.
  Serial.println("Schau mal unsere Farben an.");// Nun schicken wir den Begrüßungstext an den Computer.
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS); // Einstellungen für FastLED.
}
```

Hier ist wieder unsere `setup()` Methode. Wir haben eine neue Zeile hinzugefügt um die **FastLED** Bibliothek zu konfigurieren.
Hier verwenden wir dann die oben definierten Werte wie `NUM_LEDS`, `LED_PIN` und `leds`.

``` C++
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
```

Die `loop()` Methode sieht groß aus, aber es passiert tatsächlich garnicht so viel.
Wir definieren drei Variablen für die Farben `rot`, `gruen` und `blau`.
Danach stellen wir die Farben so ein, dass jeweils die rote, grüne und blaue led ganz hell ist (`255`) und alle anderen ganz dunkel (`0`).
Garnicht so kompliziert oder?

``` C++
  leds[0] = rot; // Wir setzen die aktuelle Farbe für unseren Pixel
  FastLED.show(); // Wir sagen FastLed, dass es die neue Farbe anzeigen soll.
  delay(1000); // Wir warten eine Sekunde.
```

Erinnert ihr euch daran, dass wir eine Liste von LEDs definiert haben, ganz am Anfang. Diese hat den Namen `leds`.
Mit `leds[0] = rot` sagen wir, dass die Farbe für die erste LED (die Erste Stelle ist hier immer `0`) jetzt rot ist.
Damit die FastLED diese Änderung umsetzt müssen wir ihr das auch sagen.
Dafür rufen wir die Methode `FastLED.show()` auf.
Und danach warten wir einfach eine Sekunde.

``` C++
  leds[0] = gruen;
  FastLED.show();
  delay(1000);
  leds[0] = blau;
  FastLED.show();
  delay(1000);
```

Hier machen wir das ganze nochmal für Grün und Blau.

``` C++
  FastLED.clear(); // Wir löschen alle Farben.
  FastLED.show();
  delay(1000);
```

Manchmal möchten wir alle Farben unserer LEDs löschen um neue Farben darzustellen. Dazu können wir einfach die Methode `FastLED.clear()` aufrufen. Danach sind alle LEDs wieder dunkel und wir können alles neu einstellen.

``` C++
  // Um Schreibarbeit zu sparen können wir Farben auch so definieren.
  CRGB meineTolleFarbe{255, 0, 128}; // Rot ist 255, grün ist 0 und blau ist 128.
  leds[0] = meineTolleFarbe;
  FastLED.show();
  delay(1000);
```

Als letztes Stellen wir eine neue Farbe ein. Sie ist eine Mischung aus rot und Blau. Was für eine Farbe wird wohl daraus entstehen?
Überlegt was es sein könnte und drückt den Upload Knopf um herauszufinden ob ihr richtig liegt.

Verändert doch die Werte der Farben, oder fügt neue Farben hinzu. Ihr wisst ja jetzt wie das funktioniert. Was für Farben könnt ihr erzeugen? Was ist eure Lieblingsfarbe? Könnt ihr diese Farbe einstellen?
Nehmt euch Zeit für eure Experimente. Wenn das Programm nicht mehr funktioniert könnt ihr es einfach wieder neu laden und weiter experimentieren.
Wir sehen uns im nächsten Kapitel.

## Fußgängerampel

Ihr kennt alle Fußgängerampeln. Wenn man den Knopf an der Ampel drückt schaltet sie für eine Kurze Zeit von Rot auf Grün.
Wenn wir den Knopf weg lassen, dann können wir einfach eine Ampel bauen die automatisch von Rot auf Grün und zurück schaltet.
Dazu schauen wir uns Bedingungen an.
Wenn die Ampel Rot ist, dann soll sie auf Grün schalten. Wenn die Ampel Grün ist, dann soll sie auf Rot schalten.
Wenn ihr mehr über Bedingungen wissen möchtet, schaut euch doch einfach mal das Kapitel [Bedingungen](Grundlagen.md#bedingungen) an.

Schauen wir uns ein Beispiel dazu an. Nehmen wir an wir wollen schauen ob eine Farbe rot ist.
Zuerst definieren wir die Farbe `rot` mit `CRGB rot{255, 0 ,0};`.
Dann definieren wir eine weitere Farbe mit dem Namen `farbe` ganz einfach mit `CRGB farbe{255, 0, 0};`.
Wenn wir nun schauen wollen, ob die Farben gleich sind, brauchen wir eine Bedingung.
Eine Bedingung ist so etwas wie *wenn, dann*. Auf englisch heißt das *if, then* und für den Arduino eben `if`.
Auf `if` folgt die Bedingung zwischen den Klammern `(` und `)`.
Wenn wir schauen wollen ob die Farben gleich sind dann brauchen wir die `==` Bedingung für Gleichheit.
Das ganze sieht für unsere beiden Farben dann so aus `if(farbe == rot)`.
Bedingungen sind immer wahr oder falsch. Wenn die Bedingung wahr ist, dann werden die Befehle zwischen den beiden Klammern `{` und `}` ausgeführt.
Das Ganze sieht dann so aus:


``` C++
  CRGB rot{255, 0, 0};
  CRGB farbe{255, 0, 0};
  if(farbe == rot) {
    Serial.println("Farbe ist rot");
  }
```

Wir definieren unsere beiden Farben `rot` und `farbe`. Dann schreiben wir unsere Bedingung *wenn farbe gleich rot, dann* oder `if(farbe == rot) {`.
Wenn unsere `farbe` gleich ist wie `rot`, dann werden die Befehle zwischen den Klammern `{` und `}` ausgeführt. In unserem Fall also den Befehl `Serial.println("Farbe ist rot");`.
Also geben wir den Text `"Farbe ist rot"` aus, wenn unsere `farbe` gleich ist wie `rot`.

Was wenn wir auch etwas machen wollen, wenn die Farben nicht gleich sind?
Man kann unsere Bedingung auch mit einem *sonst* Fall erweitern, also *wenn, dann, sonst*. Auf englisch also *if, then, else* oder für den Arduino `if(){}else{}`. Wie das mit dem *sonst* Fall genau funktioniert ist [hier](Grundlagen.md#bedingungen-und-alternativen) etwas genauer beschrieben.

Erweitern wir unser Beispiel um einen `else` Fall.

``` C++
  CRGB rot{255, 0, 0};
  CRGB farbe{255, 0, 0};
  if(farbe == rot) {
    Serial.println("Farbe ist rot");
  } else {
    Serial.println("Farbe ist nicht rot");
  }
```

Wir fügen also einen `else` Fall hinzu und schreiben zwischen die beiden Klammern `{` und `}` nach dem `else` was der Arduino machen soll, wenn die `farbe` nicht gleich ist wie `rot`. In unserem Fall geben wir dann den Text `"Farbe ist nicht rot"` aus.

Ist doch ganz einfach. Wie machen wir das jetzt mit unserer Ampel?


``` C++
  CRGB rot{255, 0, 0};
  CRGB gruen{0, 255, 0}
  CRGB farbe{255, 0, 0};
  if(farbe == rot) {
    farbe = gruen;
  } else {
    farbe = rot;
  }
```

Was steht jetzt genau da? Wenn die `farbe` `rot` ist dann ändern wir die `farbe` auf `gruen`.
Wenn die Farbe nicht `rot` ist, dann ändern wir die `farbe` auf `rot`.
Ist doch garnicht schwer.

### Beispiel

Öffnet das Beispiel `Datei|Beispiele|Jugend Hackt Animation-lib|B_02_FussgaengerAmpel` und schaut euch den Quelltext an.

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

  /*
   * Hier kommen unsere Bedingungen.
   * Unsere Ampel schaltet immer von rot nach grün.
   * Das machen wir über diese Bedingungen.
   */
  if(farbe == rot) { // Wenn farbe jetzt rot ist
    farbe = gruen; // Dann ändern wir farbe zu grün
  }else { // Wenn farbe nicht rot ist
    farbe = rot; // Dann ändern wir farbe zu rot.
  } 
  // Wir setzen die Farbe der LED auf den wert von farbe.
  leds[0] = farbe;
  // Wir zeigen die aktuelle Farbe an.
  FastLED.show();
  // Wir warten eine sekunde
  delay(1000);
}
```

Als aller Erstes fällt uns auf, dass oben, direkt unter der Definition der LEDs `CRGB leds[NUM_LEDS]` eine neue Zeile steht.
Dazu muss man wissen, dass eine Variable, die innerhalb einer Methode erzeugt wird nach dem Abarbeiten aller Befehle in der Methode aufgeräumt wird. Das bedeutet diese Werte sind dann nicht mehr da.
Die Methode `loop()` wird vom Arduino immer wieder ausgeführt und alle Werte in der Methode werden danach aufgeräumt.
Wir wollen uns aber den Wert der Variable `farbe` für das nächste mal merken. Deshalb deklarieren wir die Variable `farbe` hier oben und außerhalb der Methoden. Damit bleibt sie immer für uns erreichbar.

``` C++
  CRGB rot{255, 0, 0};
  CRGB gruen{0, 255, 0};
```

In der `loop()` Methode definieren wir dann unsere beiden Farben `rot` und `gruen`, wie wir es schon kennen.

``` C++
  if(farbe == rot) { // Wenn farbe jetzt grün ist
    farbe = gruen; // Dann ändern wir farbe zu gelb
  }else { // Wenn farbe nicht grün ist aber gelb
    farbe = rot; // Dann ändern wir farbe zu rot.
  }
```
Danach kommt unsere Bedingung in der wir den Wert für unsere Variable `farbe` anpassen, wie oben schon besprochen.
Wenn die Variable `farbe` den gleichen Wert wie `rot` hat, dann ändern wir den Wert für Farbe auf den Wert von `gruen`.
Wenn die Variable `farbe` nicht den gleichen Wert hat wie `rot`, dann ändern wir den Wert für `farbe` auf rot.

``` C++
  leds[0] = farbe;
  FastLED.show();
  delay(1000);
```

Danach setzen wir für unsere LED den aktuellen Wert für `farbe`. Das passiert mit diesem Befehl `leds[0] = farbe;`.
Wir sagen der **FastLED** Bibliothek, dass die neue Farbe angezeigt werden soll. Das passiert mit dem Befehl `FastLED.show();`.
Und dann warten wir eine Sekunde lang mit dem Befehl `delay(1000);`.

Das war doch garnicht so schwer. Wir haben eine automatische Fußgängerampel gebaut und dabei gelernt wie Bedingungen funktionieren.
Wir werden dieses Beispiel immer wieder erweitern, wenn wir neue Dinge gelernt haben. Vielleicht haben wir am Ende ja eine funktionierende Ampel?
Im nächsten Schritt schauen wir uns an was man mit Farben und Mathe alles machen kann.

## Farben und Mathe

Farben und Mathe? Das hört sich erstmal komisch an. Aber wenn wir Animationen erzeugen wollen, dann hilft es uns wenn wir ein bisschen Mathe einsetzen können um Farben zu modifizieren.

Was ist denn zum Beispiel wenn wir wollen dass eine LED doppelt so hell leuchtet wie eine andere LED, oder halb so hell?
Können wir die Werte auch addieren?
Alles das ist möglich und es ist auch garnicht so schwer.

### Beispiel

Öffnet das Beispiel `Datei|Beispiele|Jugend Hackt Animation-lib|B_03_FarbenMathe` und schaut euch den Quelltext an.

``` C++
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
   Hier führen wir Berechnungen aus und schicken die Ergebnisse an den Computer.
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
```

Sieht nach viel aus, aber eigentlich ist es garnicht so kompliziert. Wir schauen uns das alles nun Schritt für Schritt an. Solltet ihr mal etwas nicht genau verstehen könnt ihr auch schnell im Grundlagenkapitel zum Bereich [Mathematik](Grundlagen.md#die-mathematik) nachlesen wie das mit dem Rechnen auf dem Arduino genau funktioniert und dann wieder hier her zurück kommen.

Die Parameter für `FastLED` und unsere `setup()` Methode haben sich nicht verändert. Aber unsere `loop()` Methode schaut etwas anders aus. Was hat sich denn da verändert?

``` C++
  uint8_t basis = 127;
```

Zuerst definieren wir eine Variable mit dem Namen `basis` vom Typ `uint8_t`. Das ist der selbe Typ, der in der Struktur `CRGB` für die Farben Rot, Grün und Blau verwendet wird. Wir weißen dieser Variable den Wert `127` zu. Wenn ihr nich ganz versteht was genau da passiert könnt ihr auch [hier](Grundlagen.md#variablen) noch einmal nachschauen.

Die nächsten Zeilen definieren verschiedene Farben, deren Rot wert durch Berechnungen mit der variable `basis` entstehen.
Wie das mit mathematischen Berechnungen mit Variablen funktioniert wird [hier](Grundlagen.md#beispiel-rechnen-mit-variablen) nochmal genau gezeigt. Aber schauen wir uns die Schritte man im Detail an.

``` C++
  CRGB farbe{basis, 0, 0};
```

Ihr kennt diese Schreibweise ja schon aus dem letzen Beispiel. Nur schreiben wir hier nicht direkt den Wert `127` hin, sondern den Namen der Variablen die den Wert `127` gespeichert hat. Das Ergebnis ist das gleiche. Ihr könntet auch einfach `127` hin schreiben. Warum das mit den Variablen aber nützlich sein kann sehen wir im nächsten Schritt.

``` C++
  CRGB farbeDoppelt{basis * 2, 0, 0};
```

Nehmen wir an, dass die LED nun doppelt so hell leuchten soll. Wir können dann einfach den Wert von `basis` mit `2` multiplizieren.
Das ist was hier passiert. Wenn euch das zu schnell geht könnt ihr auch [hier](Grundlagen.md#die-mathematik) noch einmal nachlesen wie das mit dem Rechnen auf dem Arduino funktioniert.
Wenn wir möchten, dass die LED jetzt nur noch halb so hell leuchtet wie ganz am Anfang können wir den Anfangswert auch halbieren.

``` C++
  CRGB farbeHalb{basis / 2, 0, 0};
```

Hier seht ihr wie wir den Wert der Variable `basis` durch den Wert `2` teilen. Wichtig dabei ist, dass sich der Wert der Variable `basis` dabei nicht verändert, nur der Wert der später in der Farbe für Rot abgespeichert wird ändert sich. Das ist so weil wir hier der Variable `farbeHalb` einen Wert zuweisen, nicht aber der variable `basis`. Genauer erklärt ist das Ganze [hier](Grundlagen.md#variablen).

Wir können Werte auch addieren und subtrahieren.

``` C++
  CRGB farbePlus{basis + 100, 0, 0};
```

Hier Addieren wir einfach den Wert von `basis` mit `100`, also `127` von Basis und `100`, was dann `227`ergibt.

``` C++
  CRGB farbeMinus{basis - 100, 0, 0};
```

Und hier ziehen wir einfach `100` von dem in der Variable `basis` gespeicherten Wert ab. Also `127` für `basis` minus `100` ist `27`.
Wir können auch mehrere Grundfarben von unserem `basis` Wert ableiten.

``` C++
  CRGB farbeMix{basis, basis / 2, 0};
```

Hier sagen wir zum Beispiel dass Grün halb so hell sein soll wie Rot.

``` C++
  CRGB farbeBlau{0, 0, farbe.red / 2};
```

Oder hier sagen wir dass für `farbeBlau` die blaue LED nur halb so hell leuchten soll wie die rote LED der Farbe `Farbe`.

``` C++
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
```

Hier zeigen wir einfach nach einander alle Farben an und warten immer eine Sekunde bevor die nächste Farbe kommt.
Drückt den Upload Knopf und schaut was passiert.
Ihr seht verschieden helle rote Farben, eine Mischung aus Rot und Grün und am ende Blau.
Was ist hier passiert. Spielt selbst mit den Werten und schaut was passiert.
Im nächsten Kapitel schauen wir uns an wie wir Farben mischen können.

## Farben Mischen

Ja wir können Farben auch mischen. Das ist auch der Grund warum wir uns das mit der Mathematik angeschaut haben.
Denn wenn wir Farben mischen wollen, dann funktioniert das auf dem Arduino so, dass wir Berechnungen mit diesen Farben ausführen.
Das klingt auch erstmal wieder total kompliziert, aber keine Angst, wir machen das Schritt für Schritt und eigentlich ist das auch garnicht so schwer.

### Beispiel

Öffnet das Beispiel `Datei|Beispiele|Jugend Hackt Animation-lib|B_04_FarbenMischen` und schaut euch den Quelltext an.
Das sieht erstmal nach viel aus, aber wir schauen uns das Schritt für schritt an.

``` C++
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
   Hier führen wir Berechnungen aus und schicken die Ergebnisse an den Computer.
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
```

Wie beim letzen Mal unterscheiden sich die Einstellungen für die `FastLED` library und die `setup()` Methode nicht.
Aber die `loop()` Methode hat sich verändert.

Schauen wir uns Schritt für Schritt an was hier passiert.

``` C++
  uint8_t hell = 255;

  CRGB rot{hell, 0, 0};
  CRGB gruen{0, hell, 0};
  CRGB blau{0, 0, hell};
```

Wir definieren wieder einen Basiswert, diesmal für ganz hell, also `255` und geben ihm den Namen `hell`.
Danach definieren wir unsere drei Grundfarben Rot, Grün und Blau.
So weit, so einfach.
Im nächsten Schritt beginnen wir Farben zu mischen und zwar nennt sich das hier *Additive Farbmischung*. Wir addieren verschiedene Farben mit einander um neue Farben zu erzeugen. Genau nach diesem Prinzip funktioniert auch euer Monitor.
Ihr habt viele Punkte auf dem Monitor, die die drei Farben Rot, Grün und Blau haben können. Diese Punkte heißen auch Pixel.
Und je nach dem wie hell der Pixel in der Farbe Rot, Grün und Blau leuchtet, sehen wir eine andere Farbe.

``` C++
  CRGB gelb = rot + gruen;
  CRGB cyan = gruen + blau;
  CRGB magenta = rot + blau;
```

Hier sehen wir drei neue Farben. Cyan, Magenta, und Gelb. Das sind die Basisfarben aus denen euer Drucker Farben mischt.
Euer Drucker setzt dazu *subtraktive Farbmischung* ein.
Er misch zum Beispiel Grün mit Gelb und Cyan.

``` C++
  CRGB weiss = rot + gruen + blau;
```

Wollen wir weiss müssen wir eifach alle Farben addieren. Soweit eigentlich logisch.
Wir können Farben aber auch von einander abziehen.

``` C
  CRGB magenta2 = weiss - gruen;
  CRGB gruen2 = weiss - magenta;
```

Hier ziehen wir von Weiß die Farbe Grün ab. Also bleiben rot und blau übrig, was Magenta ist.
Oder wir ziehen von der Farbe Weiß magenta ab und es bleibt logischerweise grün übrig, weil Magenta aus Blau und Rot besteht.

``` C++
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
```

Hier zeigen wir einfach nach einander alle unsere Farben an.
Drückt den Upload Knopf um zu sehen was passiert. Mischt neue Farben oder ändert die Farbwerte. Was passiert wenn ihr eigene Farben erzeugt und diese addiert?
Wir sehen uns im nächsten Kapitel wo wir uns anschauen wie man mehrere LEDs steuern kann.

## Ein-Pixel Ampel

Erinnert ihr euch noch an unser Beispiel mit der [Fußgängerampel](Farben.md#fußgängerampel)?
Wir haben mit der Hilfe von Bedingungen zwischen den Farben Rot und Grün gewechselt.

``` C++
  CRGB rot{255, 0, 0};
  CRGB gruen{0, 255, 0}
  CRGB farbe{255, 0, 0};
  if(farbe == rot) {
    farbe = gruen;
  } else {
    farbe = rot;
  } 
```

Jetzt haben wir gelernt wie wir Farben mischen können. Also wäre es doch an der Zeit unsere Ampel zu einer richtigen Ampel zu erweitern oder?
In unserem Fall schaltet die Ampel dann von Grün zuerst auf Gelb und dann erst auf Rot.
Dazu fügen wir die Farbe Gelb hinzu. Gelb ist die Mischung aus Rot und Grün.

``` C++
  CRGB rot{255, 0, 0};
  CRGB gruen{0, 255, 0}
  CRGB gelb{255, 255, 0};
  CRGB farbe{255, 0, 0};
```

Jetzt ist noch die Frage wie wir zwischen den Farben umschalten können.
Schauen wir uns das Beispiel mit der Fußgängerampel noch ein mal an.

``` C++
  if(farbe == rot) {
    farbe = gruen;
  } else {
    farbe = rot;
  }
```

Wenn die Farbe Rot ist, dann schalten wir auf Grün. Das ist so schon richtig.
Wie können wir aber von Grün auf Gelb schalten?
Das ist ganz einfach. Wir können zu dem `else` eine weitere Bedingung hinzufügen.
Schreiben wir es doch einfach auf.

*Wenn* die Farbe Rot ist, *dann* schalte auf Grün, *sonst, wenn* die Farbe Grün ist, *dann* schalte auf Gelb, *sonst* schalte auf Rot.

Für den Arduino können wir das dann so aufschreiben.

``` C++
  if(farbe == rot) {
    farbe = gruen;
  }else if(farbe == gruen){
    farbe = gelb;
  } else {
    farbe = rot;
  }
```

Wenn die `farbe` gleich ist wie `rot` dann ändern wir sie zu `gruen`.
Wenn die `farbe` nicht gleich ist wie `rot`, aber gleich ist wie `gruen`, dann ändern wir sie zu `gelb`.
Wenn die `farbe` nicht gleich ist wie `rot` und nicht gleich ist wie `gruen`, dann ändern wir sie zu `rot`.

Schauen wir uns mal das Beispiel dazu an.

### Beispiel

Öffnet das Beispiel `Datei|Beispiele|Jugend Hackt Animation-lib|B_05_EinPixelAmpel` und schaut euch den Quelltext an.

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
```

Wir definieren unsere drei Farben `rot`, `gruen` und `gelb` und wenden die gleichen Bedingungen an, wie oben besprochen.

Danach setzen wir die aktuelle Farbe mit `leds[0] = farbe` und sagen dem Arduino, dass er sie anzeigen soll `FastLED.show()`.
Gratulation, du hast dein Wissen über Bedingungen und das Mischen von Farben kombiniert um die Ampel um eine weitere Farbe zu erweitern.

Aber irgendwas fehlt doch noch. Richtig, eine echte Ampel hat doch eigentlich mehrere Lampen oder?
Wie das funktioniert schauen wir uns im nächsten Abschnitt an.

## Mehrere LEDs

Bisher haben wir ja nur eine einzelne LED angesteuert. Unser LED Ring hat aber ganze zwölf davon. Wie können wir die denn alle ansteuern?
Sicher habt ihr euch auch schon gefragt was die ersten Zeilen in den bisherigen Sketches denn eigentlich so machen. Jetzt wird es Zeit sich das mal etwas genauer an anzuschauen.

Bisher sahen die ersten Zeilen unserer Sketches immer so aus.

``` C++
#include <FastLED.h> // Wir benutzen die FastLED Bibliothek.

const uint8_t NUM_LEDS = 1; // Wir definieren wie viele LEDs wir steuern möchten.
const uint8_t LED_PIN = 6; // Wir definieren an welchem Pin unsere LEDs angeschlossen sind.

/*
   Das hier ist sowas wie eine Liste von LEDs, die wir für die FastLED Bibliothek brauchen.
   Wie das genau funktioniert schauen wir uns später an.
*/
CRGB leds[NUM_LEDS];
```

Ihr seht die Variable `NUM_LEDS`. Sie hat den Wert `1`. Wenn wir diesen Wert verändern können wir auch mehr LEDs ansprechen. Aber wie funktioniert das?
In der letzten Zeile des Beispiels definieren wir ein Array aus Farbwerten, welches die Länge `NUM_LEDS` hat.
Jeder dieser Farbwerte steht für eine LED auf unserem Pixel Ring.
Wenn ihr nicht genau wisst was Arrays sind ist das kein Problem. Ihr könnt [hier](Grundlagen.md#arrays) einfach nachlesen was ein Array ist und wie man es verwendet.

Um also mehrere LEDs zu kontrollieren müssen wir einfach das Array `leds` größer machen und das machen wir indem wir einfach eine größere Zahl dort eintragen.

### Beispiel

Öffnet das Beispiel `Datei|Beispiele|Jugend Hackt Animation-lib|B_06_FarbenMehrere` und schaut euch den Quelltext an.

``` C++
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
   Hier führen wir Berechnungen aus und schicken die Ergebnisse an den Computer.
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
```

Das sieht schon ein wenig anders aus als vorher oder?

``` C++
const uint8_t NUM_LEDS = 12;
```

Hier stellen wir die neue Anzahl an LEDs ein.
Die Variable wid hier verwendet um die Größe des Arrays einzustellen.

``` C++
CRGB leds[NUM_LEDS];
```

Nun haben wir zwölf LEDs denen wir Farben zuweisen können.
Schauen wir also in die `loop()` Methode und sehen uns an wie das funktioniert.

``` C++
  uint8_t hell = 255;

  CRGB rot{hell, 0, 0};
  CRGB gruen{0, hell, 0};
  CRGB blau{0, 0, hell};

  CRGB gelb = rot + gruen;
  CRGB cyan = gruen + blau;
  CRGB magenta = rot + blau;
  CRGB weiss = rot + gruen + blau;
```

Das kennen wir noch aus den letzen Sketches. Wir definieren ein paar Variablen mit Farbwerten, die wir dann später unseren LEDs zuweisen. Soweit eigentlich alles bekannt.
Aber der nächste Schritt wird interessant.

Bisher haben wir Farben immer unserer einen LED an der Stelle `0` zugewiesen. Das ändert sich nun.

``` C++
  leds[0] = rot; 
  leds[1] = gruen;
  leds[2] = blau;
  leds[3] = gelb;
  leds[4] = cyan;
  leds[5] = magenta;
  leds[6] = weiss;
  FastLED.show();
  delay(2000);
```

Fällt euch was auf? Ja genau. Wir setzen für die LED an der Stelle `0` den Farbwert von `rot`. Für die LED an der stelle `1` den Farbwert von `gruen` und immer so weiter.
Wir setzen also alle unsere Farbwerte und sagen der **FastLED** Bibliothek dann nur ein mal, dass es alle Farben für alle LEDs anzeigen soll und zwar mit `FastLED.show()`.

Schaut euch das Ergebnis an indem ihr den Upload Knopf drückt. Spielt mit den Sketch herum. Ihr habt noch sechs LEDs die noch keine Farbe haben. Gebt ihnen eine der bereits definierten Farben oder definiert eine neue Farbe. Färbt alle LEDs gleich ein oder unterschiedlich oder erzeugt ein Muster indem ihr verschiedene Farben abwechselt.

## Ampel mit mehreren LEDs

Jetzt wissen wir, wie man mehrere LEDs ansteuert. Dann können wir unsere Ampel jetzt auch so erweitern, dass sie, wie eine echte Ampel, drei Lichter hat, oder?
Dafür sollten wir aber überlegen welche Zustände unsere Ampel eigentlich hat.
Eine richtige Ampel hat vier Zustände. Wenn man fahren darf leuchtet das grüne Licht.
Bevor die Ampel auf Rot schaltet leuchtet das gelbe Licht. Wenn man stehen muss, dann leuchtet das rote Licht.
Bevor die Ampel wieder auf Grün schaltet leuchtet sowohl das rote Licht, wie auch das gelbe Licht.
Also leuchten der Reihe nach folgende Lichter:

* *Grün*
* *Gelb*
* *Rot*
* *Rot* und *Gelb*

Wir erinnern uns an unsere letze Ampel mit drei Farben und einer einzigen LED.
Da haben wir zuerst die Farben definiert.

``` C++
  CRGB rot{255, 0, 0};
  CRGB gruen{0, 255, 0}
  CRGB gelb{255, 255, 0};
  CRGB farbe{255, 0, 0};
```

An den Farben hat sich ja nichts verändert. Es ändert sich nur die LED, die wir mit der Farbe leuchten lassen wollen.
Ganz oben an der Ampel ist das rote Licht.
In der Mitte ist das gelbe Licht.
Ganz unten ist das grüne licht.

Wenn wir also alle unsere lichter gleichzeitig leuchten lassen wollen, dann würde das so aussehen.

``` C++
  leds[2] = rot;
  leds[1] = gelb;
  leds[0] = gruen;
```

Damit leuchten jetzt drei nebeneinender liegende LEDs auf unserem LED Ring.
Die erste LED (an der Position `0`) leuchtet grün,
Die zweite LED (an der Position `1`) leuchtet gelb.
Die dritte LED (an der Position `2`) leuchtet rot.
Soweit eigentlich garnicht so schwer. Wie können wir jetzt die LEDs einzeln und nach einander einschalten?
Dazu schauen wir einfach welche LED gerade leuchtet und schalten dann die nächste ein.
Das machen wir wieder mit [Bedingungen](Grundlagen.md#bedingungen).
Schauen wir uns erst einmal an wie wir von Grün zu Gelb und dann zu Rot wechseln können.

``` C++
  if(leds[0] == gruen) {
    // Momentan leuchtet also die erste LED grün.
    // Also schalten wir hier die zweite LED auf gelb.
  } else if(leds[1] == gelb){
    // Momentan leuchtet also die zweite LED gelb.
    // Also schalten wir hier die dritte LED auf rot.
  } else if(leds[2] == rot) {
    // Momentan leuchtet also die dritte LED rot.
    // Also schalten wir hier die erste LED wieder auf grün.
  }
```

Mit der Zeile `if(leds[0] == gruen){` schauen wir ob die erste LED, also die an der Stelle `0` die gleiche Farbe hat wie `gruen`.
Mit der Zeile `}else if(leds[1] == gelb){` schauen wir ob die zweite LED, also die an der Stelle `1` die gleiche Farbe hat wie `gelb`. Das machen wir wegen dem `else` aber nur, wenn die erste Bedingung nicht zutrifft, also die erste LED nicht die gleiche Farbe hatte wie `gruen`.
Mit der Zeile `}else if(leds[2] == rot){` schauen wir ob die dritte LED, also die an der Stelle `2` die gleiche Farbe hat wie `rot`. Das machen wir wegen dem `else` aber nur, wenn die erste und die zweite Bedingung nicht zutreffen.
Also wenn die erste LED nicht die gleiche Farbe hat wie `gruen` und die zweite LED nicht die gleiche Farbe hat wie `gelb`.

Uff das war aber kompliziert.
Jetzt müssen wir nur noch irgendwie die LEDs richtig einfärben. Wie das geht seht ihr im nächsten Codeschnipsel.

``` C++
  if(leds[0] == gruen) {
    FastLED.clear();
    leds[1] = gelb;
  } else if(leds[1] == gelb){
    FastLED.clear();
    leds[2] = rot;
  } else if(leds[2] == rot) {
    FastLED.clear();
    leds[0] = gruen;
  }
```

In den Klammern der Bedingungen stehen jetzt die passenden Befehle.
Bevor wir die passende LED einfärben löschen wir erstmal alle Farben mit dem Befehl `FastLED.clear()`.
Danach färben wir die LED an der passenden Stelle mit der gewünschten Farbe ein.

### Beispiel

Wie das in Form eines Sketches aussieht seht ihr im Beispiel `Datei|Beispiele|Jugend Hackt Animation-lib|B_07_MehrPixelAmpel`.

``` C++
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
   Hier führen wir Berechnungen aus und schicken die Ergebnisse an den Computer.
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
     Das machen wir über diese Bedingungen.
     Da immer eine andere LED mit einer anderen Farbe leuchtet schauen wir uns
     auch immer die zur Farbe passende LED an.
  */
  if (leds[0] == gruen) { // Wenn die erste LED, also an der Stelle 0 grün leuchtet.
    FastLED.clear(); // Dann löschen wir zuerst alle LEDs.
    leds[1] = gelb; // Und dann setzen wir die Farbe der zweiten LED, also an der Stelle 1 auf gelb.
  } else if (leds[1] == gelb) { // Wenn die erste LED nicht grün ist aber die zweite LED gelb ist.
    FastLED.clear(); // Dann löschen wir zuerst alle LEDs.
    leds[2] = rot; // Und dann setzen wir die Farbe der dritten LED, also an der Stelle 2 auf rot.
  } else { // Wenn die erste LED nicht grün ist und die zweite LED nicht gelb ist.
    FastLED.clear(); // Dann löschen wir zuerst alle LEDs.
    leds[0] = gruen; // Und dann setzen wir die Farbe der ersten LED, also an der Stelle 0 auf grün.
  }
  // Wir zeigen die aktuelle Farbe an.
  FastLED.show();
  // Wir warten eine sekunde
  delay(1000);
}
```

Hier könnt Ihr das Beispiel unserer letzten Ampel mit drei LEDs sehen.
Wie oben bereits besprochen definieren wir die Farben `rot`, `gelb` und `gruen`.
Dann schauen wir der Reihe nach welche LED gerade in welcher Farbe leuchtet, löschen alle LEDs und setzen die nächste Farbe für die nächste LED.

Was würde denn passieren wenn wir die LEDs nicht immer löschen würden?
Löscht doch einfach die Zeilen mit dem Befehl `FastLED.clear()` und schaut nach was passiert.
Komisch irgendwann leuchten einfach nur noch die grüne und die gelbe LED, aber warum?
Da am Anfang keine LED leuchtet kommen wir in den `else` Fall und schalten die grüne LED an.
Im nächsten schritt leuchtet dann die grüne LED und wir schalten die gelbe LED an.
Da wir die anderen LEDs nicht mehr löschen, leuchten jetzt beide LEDs.
Da wir als erstes schauen ob die erste LED grün leuchtet und das jetzt immer stimmt schalten wir einfach immer wieder die gelbe LED an und es passiert nichts mehr.

Schauen wir uns im nächsten Beispiel an wie wir den vierten Schritt, in dem die gelbe und rote LED gleichzeitig leuchten einbauen können.

## VierSchritteAmpel

Im letzen Beispiel haben wir uns angeschaut wie wir mit unserem Wissen über Bedingungen und Arrays eine Ampel mit drei LEDs bauen können. Um eine richtige Ampel nachzubauen fehlt uns aber noch ein Zustand. Und zwar der Zustand, dass die rote und die gelbe LED gleichzeitig leuchten.
Wie können wir das einbauen?

Schauen wir uns die Bedingungen aus dem letzten Beispiel noch einmal an.

``` C++
  if(leds[0] == gruen) {
    FastLED.clear();
    leds[1] = gelb;
  } else if(leds[1] == gelb){
    FastLED.clear();
    leds[2] = rot;
  } else  {
    FastLED.clear();
    leds[0] = gruen;
  }
```

Ok was passiert wenn wir den Zustand einbauen, dass die gelbe und die grüne LED gleichzeitig leuchten?
Dann würde es in beiden Fällen stimmen, dass die zweite LED, also die LED an der Stelle `1` gelb leuchtet.
Das wäre natürlich nicht hilfreich, weil wir bisher immer die rote LED einschalten, wenn die gelbe LED leuchtet, wie ihr in der zweiten Bedingung oben sehen könnt.
Gibt es vielleicht eine Möglichkeit zwischen dem Zustand "nur die gelbe LED leuchtet" und "die gelbe LED und die rote LED leuchtet" zu unterscheiden?

Den gibt es tatsächlich. Wir können Bedingungen in einander verschachteln. Also in eine Bedingung eine weitere Bedingung einbauen.
Schauen wir uns das doch mal an.

``` C++
  if(leds[1] == gelb) {
    if(leds[2] == rot) {
      // Hier leuchten gelb und rot.
    } else {
      // Hier leuchtet gelb und rot nicht.
    }
  }
```

Die erste Bedingung schaut nur ob die zweite LED, also die LED an der Stelle `1` die Farbe `gelb` hat.
Nur wenn das zutrifft, dann schauen wir in die Klammern `{` und `}` hinein.
Trifft das nicht zu, dann schauen wir garnicht erst in die Klammern und ignorieren den Inhalt.
Wenn die erste Bedingung also zutrifft finden wird dann die zweite Bedingung zwischen den Klammern `{` und `}`, die zur ersten Bedingung gehören.
Dann erst schauen wir uns diese Bedingung an. In der inneren Bedingung schauen wir ob die dritte LED die Farbe `rot` hat.
Wenn das stimmt, dann leuchten also sowohl die gelbe als auch die rote LED.
Wenn das nicht stimmt, dann leuchtet wohl nur die gelbe LED.

Wir erinnern uns an die Reihenfolge der Ampelzustände:

* *Grün*
* *Gelb*
* *Rot*
* *Rot und Gelb*

Wenn also nur die gelbe LED leuchtet schalten wir die rote LED an. Wenn die rote und die gelbe LED leuchten, dann schalten wir die grüne LED wieder an.
Wie sieht dass dann im Quelltext aus?

``` C++
  if(leds[1] == gelb) {
    if(leds[2] == rot) {
      FastLED.clear();
      led[0] = gruen;
    } else {
      FastLED.clear();
      led[2] = rot;
    }
  }
```

Das war ein bisschen kompliziert aber zusammen haben wir das doch irgendwie geschafft. Schauen wir uns das ganze doch mal mit den anderen Zuständen zusammen an.

``` C++
  if(leds[0] == gruen) {
    FastLED.clear();
    leds[1] = gelb;
  } else if(leds[1] == gelb){
    if(leds[2] == rot) {
      FastLED.clear();
      led[0] = gruen;
    } else {
      FastLED.clear();
      led[2] = rot;
    }
  } else  {
    FastLED.clear();
    leds[1] = gelb;
    leds[2] = rot;
  }
```

Wow sieht das kompliziert aus, aber nicht aufgeben! Wir haben uns ja alle Schritte ganz genau angeschaut und wir wissen mittlerweile ganz gut wie Bedingungen funktionieren. Deshalb verstehen wir auch was in diesem Codeschnipsel passiert.
Wir müssen uns das nur Schritt für Schritt anschauen und nicht versuchen alles auf einmal zu verstehen.
Schauen wir uns erstmal die allererste Bedingung an.

``` C++
  if(leds[0] == gruen) {
    FastLED.clear();
    leds[1] = gelb;
  }
```

Die erste Bedingung schaut ob die erste LED grün ist und wenn das stimmt, dann werden alle LEDs gelöscht und die zweite LED auf gelb geschaltet. Wenn das nicht stimmt dann schauen wir uns die zweite Bedingung an.

``` C++
  } else if(leds[1] == gelb){
    if(leds[2] == rot) {
      FastLED.clear();
      led[0] = gruen;
    } else {
      FastLED.clear();
      led[2] = rot;
    }
  }
```

Die zweite Bedingung kennen wir schon von oben. Wenn die zweite LED gelb leuchtet, dann schauen wir uns die innere Bedingung an.
Dort schauen wir ob die dritte LED rot ist. Wenn das stimmt dann leuchten die gelbe und die rote LED und wir löschen alle LEDs und schalten danach die grüne LED an.
Wenn die dritte LED nicht rot ist, dann leuchtet nur die gelbe und wir löschen wieder alle LEDs und schalten dann die rote LED ein.
Aber was passiert wenn weder die gelbe LED leuchtet, noch die grüne LED?
Dann springen wir in den letzten Teil der Bedingung, den `else` Fall.

``` C++
  } else  {
    FastLED.clear();
    leds[1] = gelb;
    leds[2] = rot;
  }
```

In den Vorhergehenden Bedingungen haben wir geschaut ob die erste LED grün leuchtet oder die zweite LED gelb leuchtet.
Wenn beides nicht stimmt, dann bleibt uns nur noch die dritte LED, die rot leuchtet.
Wenn wir uns die Reihenfolge der Ampel anschauen, dann folgt auf Rot der Zustand Rot und Gelb.
Und genau diese Beiden LEDs schalten wir dann auch ein.

Puh das war richtig viel. Aber jetzt könnt ihr ein richtige Ampel bauen und ganz viele andere Dinge bei denen eine einfache Bedingung nicht ausreicht.
Schauen wir uns das komplette Beispiel einmal an.

### Beispiel

Wie das in Form eines Sketches aussieht seht ihr im Beispiel `Datei|Beispiele|Jugend Hackt Animation-lib|B_08_VierSchritteAmpel`.

``` C++
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
   Hier führen wir Berechnungen aus und schicken die Ergebnisse an den Computer.
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
```

Mit Eurem Wissen aus der Erklärung weiter oben sollte der Sketch für euch mittlerweile kein Problem mehr darstellen.
Zum letzten Beispiel haben sich eigentlich nur die Bedingungen verändert und die haben wir uns ja zusammen ganz genau angeschaut.
Wie ihr sehen könnt kann man mit dem Arduino und ein paar LEDs ganz schön komplexe Dinge bauen, wenn man über ein paar wenige Werkzeuge ein bisschen bescheid weiss, dann ist das auch alles garnicht so schwer wie man das vielleicht am Anfang denkt.

Ihr habt in diesem Kapitel schon sehr viel gelernt.
Ihr habt gelernt wie Farben physikalisch funktionieren. Das man mit Farben rechnen kann und damit aus Farben neue Farben erzeugen kann. Ihr habt gelernt wie Arrays funktionieren und wie man damit verschiedene LEDs einfärben kann und ihr habt gelernt wie Bedingungen funktionieren.

Das ist wirklich viel und im Nächsten Kapitel seht ihr dann was man mit diesem ganzen Wissen noch machen kann, nämlich [Animationen](Animation.md).

---

[Anfang](../Readme.md) | [Zurück](Grundlagen.md) | [Weiter](Animation.md)

---

[Anfang](../Readme.md) | [Setup](Setup.md) | [Grundlagen](Grundlagen.md) | [Von Farben und Physik](Farben.md) | [Animationen](Animation.md)

