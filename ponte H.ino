/*
---------------------------------------------------------
Proxecto: Control de motor DC con ponte H
Descrición:
Control dun motor DC con 4 relays simulando unha ponte H.
O sistema funciona cunha máquina de estados finitos.

Estados:
-1 -> Freado por inercia
0  -> (a) Xiro antihorario
1  -> (b) Freado inmediato
2  -> (c) Xiro horario
3  -> (d) Freado inmediato
Trabajo realizado por Diego Cadiz Perez
Fecha 05/03/2026
---------------------------------------------------------
*/

int S1 = 8;
int S2 = 9;
int S3 = 10;
int S4 = 11;
int pinPulsador = 12;
int estado = -1;
int tiempo = 50;


void setup() {

  Serial.begin(9600);

  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S4, OUTPUT);

  pinMode(pinPulsador, INPUT);

  // Estado inicial
    digitalWrite (S1, 0);
    digitalWrite (S2, 0);
    digitalWrite (S3, 0);
    digitalWrite (S4, 0);
  Serial.println("Estado (-1) freado por inercia");
}


void loop() {

 if (digitalRead(pinPulsador) == HIGH) {
      delay(tiempo);
      if (digitalRead(pinPulsador) == HIGH) {
          estado = estado +1;
      if (estado >= 4){
    estado = 0;
      }
 }
    }
      if (estado = 0){
    digitalWrite (S1, 1);
    digitalWrite (S2, 0);
    digitalWrite (S3, 0);
    digitalWrite (S4, 1);
    }
      else if (estado = 2){
    digitalWrite (S1, 0);
    digitalWrite (S2, 1);
    digitalWrite (S3, 1);
    digitalWrite (S4, 0);
      }
        else 
    digitalWrite (S1, 1);
    digitalWrite (S2, 0);
    digitalWrite (S3, 1);
    digitalWrite (S4, 0);
}
