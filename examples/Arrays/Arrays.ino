
/*
   Hier ist wieder unsere Setup Methode.
*/
void setup() {
  Serial.begin(115200);// Wir stellen wieder unsere Übertragungsrate ein.
  delay(1000);// Dann warten wir eine Sekunde.
  Serial.println("Arrays.");// Nun schicken wir den Begrüßungstext an den Computer.
}

/*
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  int werte[10]; // Wir definieren ein Array vom Typ int der Länge 10.
  
  // In der Informatik fangen wir bei 0 an zu zählen.
  werte[0] = 1; // Wir setzen den Wert an der ersten Stelle auf 1.
  Serial.print("Der Wert an Stelle 0: ");
  Serial.println(werte[0]); // Wir schicken den Wert an der Stelle 0 zum Computer.
  delay(1000);
  
  werte[1] = werte[0] + 1; // Wir addieren zu dem Wert an der Stelle 0 eins dazu und speichern es an der Stelle 1.
  Serial.print("Der Wert an Stelle 1: ");
  Serial.println(werte[1]); // Wir schicken den Wert an der Stelle 1 zum Computer.
  delay(1000);
  
  delay(30000);
}
