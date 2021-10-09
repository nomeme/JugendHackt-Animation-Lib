/*
   Hier ist wieder unsere Setup Methode.
*/
void setup() {
  Serial.begin(115200);// Wir stellen wieder unsere Übertragungsrate ein.
  delay(1000);// Dann warten wir eine Sekunde.
  Serial.println("Rechnen mit Fließkommazahlen");// Nun schicken wir den Begrüßungstext an den Computer.
}

/*
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  float pi = 3.1415;

  Serial.print("Variable pi hat den Wert: ");
  Serial.println(pi, 4); // Wir geben die Anzahl der Nachkommastellen mit dem zweiten Parameter an.
  delay(1000);

  float ergebnis1 = 5.0 / 2.0;
  // Nun hat unser Ergebnis endlich eine Nachkommastelle.
  Serial.print("Variable ergebnis1 hat den Wert: ");
  Serial.println(ergebnis1);
  delay(1000);

  int a = 5;
  int b = 2;

  /*
     Wenn wir zwei Ganzzahl ergebnisse mit einander verrechnen ist das Ergebnis trotzdem eine
     Ganzzahl und wird erst nach der Berechnung als Fließkommazahl abgespeichert.
  */

  float ergebnis2 = a / b;
  // Nun ist die Nachkommastelle auf einmal wieder verschwunden.
  Serial.print("Variable ergebnis2 hat den Wert: ");
  Serial.println(ergebnis2);
  delay(1000);

  /*
     Wir können diese Problem umgehen indem wir dem Arduino vor der Berechnung sagen,
     dass zumindest eine der beiden Zahlen eine Fließkomma zahl ist.
  */
  float c = 2;

  float ergebnis3 = a / c;
  Serial.print("Variable ergebnis3 hat den Wert: ");
  Serial.println(ergebnis3);
  delay(1000);

  /*
     Das funktioniert auch mit einem sogenannten typecast, damit wird der Typ der variable
     für die Berechnung umgewandelt.
     Das funktioniert indem man den typ in einer klammer vor den variablen namen oder wert schreibt.
  */
  float ergebnis4 = a / (float)b;
  Serial.print("Variable ergebnis4 hat den Wert: ");
  Serial.println(ergebnis4);
  delay(1000);

  /*
     Das funktioniert für jede Variable, die an der Berechnung beteiligt ist.
  */
  float ergebnis5 = (float)a / b;
  Serial.print("Variable ergebnis5 hat den Wert: ");
  Serial.println(ergebnis5);
  delay(1000);

  /*
     Das gleiche Problem haben wir, wenn wir die Zahl nicht mit einem "." aufschreiben.
  */

  float ergebnis6 = 5 / 2;
  Serial.print("Variable ergebnis6 hat den Wert: ");
  Serial.println(ergebnis6);
  delay(1000);

  /*
     Der Arduino geht immer zuerst davon aus, dass es sich um eine Ganzzahl handelt,
     außer wir weisen ihn ausdrücklich darauf hin.
  */
  float ergebnis7 = 5.0 / 2;
  Serial.print("Variable ergebnis7 hat den Wert: ");
  Serial.println(ergebnis7);
  delay(1000);

  delay(30000); // Wir warten 30 Sekunden.
}
