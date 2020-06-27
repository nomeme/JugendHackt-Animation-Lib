
/*
   Hier ist wieder unsere Setup Methode.
*/
void setup() {
  Serial.begin(115200);// Wir stellen unsere Übertragungsrate ein.
}

/*
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  Serial.print("Hallo Zahl: "); // Wir geben einen Text aus ohne eine neue Zeile am Ende
  Serial.print(42); // Wir geben eine Zahl aus ohne neue Zeile am Ende
  Serial.println(); // Wir geben nichts aus, aber erzeugen eine neue Zeile
  delay(1000); // Wir warten eine Sekunde.
}
