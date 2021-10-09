
/*
   Hier ist wieder unsere Setup Methode.
*/
void setup() {
  Serial.begin(115200);// Wir stellen wieder unsere Übertragungsrate ein.
  delay(1000);// Dann warten wir eine Sekunde.
  Serial.println("Schleifen.");// Nun schicken wir den Begrüßungstext an den Computer.
}

/*
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  int zahl = 2; // Unsere Zahl hat den Wert 2.
  int ergebnis = zahl; // Wir fangen mit dem Wert von Zahl an.
  /*
     Das hier ist unsere for Schleife.
     Wir können damit sagen wie oft alle Aktionen zwischen den zwei Klammern { und }
     ausgeführt werden.
     Dazu legen wir drei Dinge fest.
     Unser Startwert ist eine Ganzzahl, heisst i und startet mit dem Wert 0 (int i = 0)
     Wir führen alle Aktionen so lange aus wie i kleiner als 5 ist. (i < 5).
     Und dann sagen wir noch was mit i in jedem Schritt passieren soll (i++).
     i++ ist genau das gleiche wie i = i + 1
  */
  for (int i = 0; i < 5; i++)
  {
    // Alles in diesen klammern wird jetzt 5 mal ausgeführt.
    ergebnis = ergebnis + zahl;
    Serial.print("Der Wert ist: ");
    Serial.println(ergebnis);
  }

  delay(30000);
}
