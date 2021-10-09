/*
   Hier ist wieder unsere Setup Methode.
*/
void setup() {
  Serial.begin(115200);// Wir stellen wieder unsere Übertragungsrate ein.
  delay(1000);// Dann warten wir eine Sekunde.
  Serial.println("Arrays und Schleifen.");// Nun schicken wir den Begrüßungstext an den Computer.
}

/*
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  int zahlen[10]; // Wir definieren ein Array vom Typ int der Länge 10.

  /*
     Hier setzen wir für jeden Eintrag im Array einen Wert.

     Wir fangen bei 0 an zu zählen und hören bei 10 auf.
     Das bedeutet wir setzen für die Stellen 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
     einen Wert.
     Und zwar setzen wir den wert i, also 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.

     Bei Arrays müssen wir immer aufpassen, dass wir innerhalb der Grenzen des
     Arrays bleiben. Unser Array hat die Länge 10.
     Also sind die Grenzen 0 bis 9.
  */
  for (int i = 0; i < 10; i++)
  {
    zahlen[i] = i;
  }

  /*
     Hier geben wir die Werte aus.
     Die Schleife hat die gleichen Werte wie oben.
  */
  for (int i = 0; i < 10; i++)
  {
    Serial.print("Wert an der Stelle: ");
    // Hier könnt ihr den Wert von i für jeden Schritt sehen.
    Serial.print(i);
    Serial.print(" ist: ");
    // Hier geben wir den Inhalt des Arrays an der Stelle i aus.
    Serial.println(zahlen[i]);
  }

  delay(30000);
}
