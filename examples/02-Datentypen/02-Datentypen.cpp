/*
 * Hier reden wir kurz über Datentypen.
 * Ein Arduino ist ja sowas wie ein kleiner Computer.
 * Computer werden auch Rechner genannt und das hat einen Grund.
 *
 * Was wir mit dem Arduino tun ist eigentlich immer irgend eine
 * Art von Berechnung.
 * Damit der Arduino weiß, was er berechnen muss gibt es sogenannte
 * Datentypen.
 */

/*
 * Wir stellen in der setup methode wieder unsere serielle Schnittstelle ein.
 */
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Hallo");
}

/*
 * Datentypen haben mit bits und bytes zu tun.
 * Ein bit kann 0 oder 1 sein und 8 bit ergeben ein byte.
 *
 * Wenn wir mit Zahlen rechnen unterscheiden die sich einfach
 * danach wie groß die Zahlen sein können.
 * Je mehr bits, desto größer kann die Zahl sein mit der wir rechnen.
 *
 * Damit das nicht so kompliziert wird wird die größe eines Datentyps
 * in bytes angegeben.
 *
 * Außerdem kann man dem Arduino sagen ob es negative Zahlen gibt oder nicht.
 */
void loop() {
  /*
   * Der einfachste Datentyp ist der Boolean oder bool.
   * Der sagt einfach nur ob etwas wahr oder falsch ist.
   * Dazu reicht uns ein bit. 0 = falsch, 1 = wahr.
   */
  bool boolean = true;

  /*
   * Am einfachsten sind ganze Zahlen, also 1,2,3,4 und so weiter.
   */


  /*
   * Der kleinste Ganzzahlige Datentyp ist das byte, es hat genau 8 bit und kann
   * Zahlen von 0 bis 255 speichern.
   */
  byte b = 16;

  /*
   * Der nächstgrößere Datentyp is int.
   * Int hat ein byte mehr platz als byte und kommt damit auf 2 byte oder 16 bit.
   * Und er kann negativ sein!
   * Damit können wir schon alle Zahlen von -32 768 bis 32 767 speichern.
   */
  int i = -16000;

  /*
   * Wenn wir noch größere Zahlen brauchen gibt es long.
   * Long ist doppelt so groß wie int und hat damit 4 byte oder 32 bit platz.
   * Damit können wir alle Zahlen von -2 147 483 648 2 147 483 647 speichern.
   * Das ist ganz schön viel!
   */
  long l = -3141568;

  /*
   * Manchmal müssen wir aber auch mit kommas rechnen.
   * Was ist denn zum Beispiel wenn ich die Häfte von fünf ausrechnen will?
   * Dazu gibt es Fließkommazahlen.
   */

  /*
   * Dafür gibt es den float.
   * Der float kann fließkommazahlen, also sowas wie 2.5 oder 3.1415 speichern.
   * Dazu verwendet er 4 bytes oder 32 bit.
   */
  float f = 3.1415;

  // Und jetzt kommt das Tolle, wir können diese Zahlen auch alle an unseren Computer schicken.
  
  Serial.println(b);
  Serial.println(i);
  Serial.println(l);
  Serial.println(f);

  /*
   * Und wir können sogar speichern wie lange wir warten sollen, nur welchen Datentyp brauchen wir dafür?
   * Wenn wir 15 sekunden warten wollen, dann sind das 15000 millisekunden.
   * das viel zu groß für unser byte, aber passt git in einen int.
   */
  int wartezeit = 15000;
  delay(wartezeit);

}
