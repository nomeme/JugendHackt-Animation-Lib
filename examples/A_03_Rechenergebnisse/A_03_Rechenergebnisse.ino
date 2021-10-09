/*
   Hier ist wieder unsere Setup Methode.
*/
void setup() {
  Serial.begin(115200);// Wir stellen wieder unsere Übertragungsrate ein.
  delay(1000);// Dann warten wir eine Sekunde.
  Serial.println("Ganzzahl Mathematik");// Nun schicken wir den Begrüßungstext an den Computer.
}

/*
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  int add = 5+5; // Die Variable add speichert das Ergebnis der Addition 5+5.
  int sub = 6-3; // Die Variable sub speichert das Ergebnis der Subtraktion 6-3.
  int mul = 2*2; // Die Variable mul speichert das Ergebnis der multiplikation 2*2.
  int div = 8/2; // Die Variable div speichert das Ergebnis der Division 8/2.
  /*
     Nun schicken wir einfach alle Ergebnisse an den Computer.
  */
  Serial.print("Variable add hat den Wert: ");
  Serial.println(add);
  delay(1000);
  Serial.print("Variable sub hat den Wert: ");
  Serial.println(sub);
  delay(1000);
  Serial.print("Variable mul hat den Wert: ");
  Serial.println(mul);
  delay(1000);
  Serial.print("Variable div hat den Wert: ");
  Serial.println(div);
  delay(1000);
  delay(30000); // Wir warten 30 Sekunden.
}
