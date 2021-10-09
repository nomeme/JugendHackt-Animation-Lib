
/*
   Hier ist wieder unsere Setup Methode.
*/
void setup() {
  Serial.begin(115200);// Wir stellen wieder unsere Übertragungsrate ein.
  delay(1000);// Dann warten wir eine Sekunde.
  Serial.println("Bedingungen");// Nun schicken wir den Begrüßungstext an den Computer.
}

/*
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  int wert = 12;
  if(wert == 12){ // Hier prüfen wir auf Gleichheit.
    Serial.println("Der Wert ist gleich 12");
  }
  if(wert != 12) { // Hier prüfen wir auf Ungleichheit.
    Serial.print("Der Wert ist nicht gleich 12");
  }
  if(wert < 12) { // Hier prüfen wir ob der Wert kleiner ist als 12.
    Serial.println("Wert ist kleiner als 12");
  }
  if(wert > 12) { // Hier prüfen wir ob der Wert größer ist als 12.
    Serial.println("Wert ist größer als 12");
  }
  if(wert <= 12) { // Hier prüfen wir ob der Wert kleiner oder gleich 12 ist.
    Serial.println("Wert ist kleiner oder gleich 12");
  }
  if(wert >= 12) { // Hier prüfen wir ob der Wert größer oder gleich 12 ist.
    Serial.println("Wert ist größer oder gleich 12");
  }
  delay(1000); // Wir warten eine Sekunde.
}
