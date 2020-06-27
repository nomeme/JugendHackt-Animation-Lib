/*
   Hier ist wieder unsere Setup Methode.
*/
void setup() {
  Serial.begin(115200);// Wir stellen wieder unsere Übertragungsrate ein.
  delay(1000);// Dann warten wir eine Sekunde.
  Serial.println("Rechnen mit Variablen");// Nun schicken wir den Begrüßungstext an den Computer.
}

/*
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  int a = 5;
  int b = 10; 

  int c = a + 1; 
  int d = a - 1; 
  int e = a + b;
  int f = b - a;
  int g = b / a;
  int h = a * a;
  int i = a + a * b;
  int j = a / 2;
  /*
     Nun schicken wir einfach alle Ergebnisse an den Computer.
  */
  Serial.print("Variable c hat den Wert: ");
  Serial.println(c);
  delay(1000);
  Serial.print("Variable d hat den Wert: ");
  Serial.println(d);
  delay(1000);
  Serial.print("Variable e hat den Wert: ");
  Serial.println(e);
  delay(1000);
  Serial.print("Variable f hat den Wert: ");
  Serial.println(f);
  delay(1000);
  Serial.print("Variable g hat den Wert: ");
  Serial.println(g);
  delay(1000);
  Serial.print("Variable h hat den Wert: ");
  Serial.println(h);
  delay(1000);
  Serial.print("Variable i hat den Wert: ");
  Serial.println(i);
  delay(1000);
  Serial.print("Variable j hat den Wert: ");
  Serial.println(j);
  delay(1000);
  delay(30000); // Wir warten 30 Sekunden.
}
