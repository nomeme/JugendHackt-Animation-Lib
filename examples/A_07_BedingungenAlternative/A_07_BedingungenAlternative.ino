
/*
   Hier ist wieder unsere Setup Methode.
*/
void setup() {
  Serial.begin(115200);// Wir stellen wieder unsere Übertragungsrate ein.
  delay(1000);// Dann warten wir eine Sekunde.
  Serial.println("BedingungenAlternative");// Nun schicken wir den Begrüßungstext an den Computer.
}

/*
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  int wert = 12;
  if(wert == 12){ // Hier prüfen wir auf Gleichheit.
    Serial.println("Der Wert ist gleich 12");
  } else { // Wenn die Bedingung nicht zutrifft dann wird das hier ausgeführt
    Serial.println("Der Wert ist nicht gleich 12");
  }
  if(wert < 12) {
    Serial.println("Der Wert ist kleiner 12");
  } else {
    Serial.println("Der Wert ist nicht kleiner 12");
  }
  
  delay(1000); // Wir warten eine Sekunde.
}
