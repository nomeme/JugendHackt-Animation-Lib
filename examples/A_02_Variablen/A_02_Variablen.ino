/*
   Hier ist wieder unsere Setup Methode.
*/
void setup() {
  Serial.begin(115200);// Wir stellen wieder unsere Übertragungsrate ein.
  delay(1000);// Dann warten wir eine Sekunde.
  Serial.println("Was sind Variablen");// Nun schicken wir den Begrüßungstext an den Computer.
}

/*
   Hier führen wir Berechungen aus und schicken die Ergebnisse an den Computer.
*/
void loop() {
  int a; // Wir deklarieren eine Variable vom Typ Integer (int), was Ganzzahl bedeutet.
  /*
     Eine Variable ist sowas wie ein Name für einen Wert, so können wir den Wert immer wieder
     mit seinem Namen abrufen und verwenden.
     Wenn wir eine Variable deklarieren, müssen wir immer einen Typ angeben, damit der Arduino weiss,
     was für ein Typ sich hinter dem Namen verbirgt.
  */
  a = 5; // Nun weisen wir der Variable den Wert 5 zu.
  /*
     Wenn wir einer Variable einen Wert zuweisen müssen wir den Typ nicht mehr angeben, denn
     der Arduino hat sich diesen bereits gemerkt.
  */
  Serial.print("Variable a hat den Wert: "); // Wir schicken einen Text an den Computer ohne die Zeile zu beenden.
  Serial.println(a); // Wir schicken den Wert der Variablen an den Computer und beenden die Zeile
  /*
     Da wir oben eine Ganzzahl Variable deklarieren haben und ihr einen Wert zugewiesen haben weiss der Arduino,
     dass er diesen Ganzzahl Wert an den Computer schicken soll.
  */
  delay(1000); // Wir warten eine Sekunde.

  int b = 10; // Wir können auch eine Variable deklarieren und ihr gleich einen Wert zuweisen.
  Serial.print("Variable b hat den Wert: ");
  Serial.println(b);
  delay(1000); // Wir warten eine Sekunde.

  b = 15; // Wir können den Wert der Variable auch verändern.
  Serial.print("Variable b hat den Wert: ");
  Serial.println(b);

  delay(30000); // Wir warten 30 Sekunden.
}
