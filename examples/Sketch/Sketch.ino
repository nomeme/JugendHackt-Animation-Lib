// Das ist eine kommentarzeile.

/* Das hier ist auch ein Kommentar*/

/*
 * Kommentare haben keine Auswirkungen auf unser Programm.
 *
 * Kommentare benutzen wir um uns Notizen im Quelltext zu machen.
 * Das ist wichtig damit wir anderen erklären können was wir tun.
 * Es hilft uns aber auch später zu verstehen was wir früher mal
 * gemacht haben.
 * Ich benutze Kommentare um euch zu erklären was der code macht
 * und wie er eigentlich funktioniert.
 */

/*
 * Was ihr hier seht ist ein Arduino Sketch.
 * Das ist der code, der später auf eurem Arduino läuft.
 * Jeder Arduino Sketch ist gleich aufgebaut.
 *
 * Es gibt eine setup methode und eine loop methode.
 *
 * Eine methode oder funktion bietet uns die Möglichkeit code
 * zu gruppieren. Wenn ich etwas immer wieder machen will, dann
 * muss ich es nicht immer wieder aufschreiben, sondern kann das
 * alles in eine methode schreiben und diese dann aufrufen.
 *
 * Programmierer sind halt alle ziemlich faule leute.
 */



/*
 * Das hier ist die setup methode.
 * Jeder Arduino Sketch hat genau eine setup methode.
 *
 * Die setup methode wird immer am anfang ein einziges mal aufgerufen.
 * Hier können wir wichtige Einstellungen vornehmen, die wir brauchen,
 * damit unser Programm funktioniert.
 */
void setup() {
  /*
   * Hier stellen wir unsere serielle Verbindung ein.
   *
   * Mit der seriellen Verbindung können wir Text an unseren Computer schicken.
   * Wir können aber auch Text vom Computer zum Arduino schicken.
   *
   * Hier sagen wir einfach nur, dass die seriell Verbindung mit einer Datenrate
   * von 115200 bits pro sekunde kommunizieren soll.
   * Wenn wir die gleiche Geschwindigkeit in unserem seriellen monitor auf dem
   * Computer einstellen, dann können wir alles lesen, was der Arduino uns schickt.
   */
  Serial.begin(115200);// Nach jeder Aktion müssen wir einen Strichpunkt  ";" schreiben.
  /*
   * Hier rufen wir die Methode delay auf.
   * Die Methode delay macht nichts anderes als den Arduino für eine bestimmte Zeit
   * warten zu lassen.
   * Hier lassen wir den Arduino 1000 millisekunden warten. Das ist genau eine Sekunde.
   */
  delay(1000);// Der Arduino arbeitet seine Aufgaben immer Schritt für Schritt ab.
  /*
   * Da wir unsere serielle Schnitstelle jetzt fertig haben, wollen wir natürlich
   * wissen ob die auch funktioniert.
   * Deshalb schicken wir jetzt einen Text an den Computer.
   * Und zwar den Text "Hallo".
   * Texte müssen immer in Anführungszeichen sein.
   * Aber keine Angst, die Anführungszeichen werden nicht mit gesendet.
   */
  Serial.println("Hallo");// Der Strichpunkt sagt dem Arduino, dass dieser Schritt fertig ist und er ihn ausführen kann.
}


/*
 * Das hier ist die loop methode.
 * Jeder Arduino sketch hat genau eine loop methode.
 *
 * Diese methode wird immer wieder aufgerufen.
 * Hier werden wir unsere Hauptaufgaben für den Arduino schreiben.
 */
void loop() {
  /*
   * Wir schicken den Text Hallo an unseren Computer.
   * Fällt euch was auf?
   * Genau! in der setup methode haben wir Serial.println("Hallo") benutzt,
   * nicht Serial.print(Hallo).
   */
  Serial.print("Hallo");
  delay(3000);
  /*
   * Aus diesem Grund kommt "Hallo" und " Welt" jetzt in der gleichen Zeile.
   */
  Serial.println(" Welt");
  /*
   * Und wir warten immer drei Sekunden bis der nächste Text erscheint.
   */
  delay(3000);
  /*
   * Das schöne an der loop methode ist, dass das jetzt endlos so weiter geht
   * bis wir dem Arduino den Stecker ziehen.
   */
}
