/*ENCENDER Y APAGAR UN LED MEDIANTE EL MISMO PULSADOR*/

int led = 9; //DECLARAR EL PIN DEL LED
int pulsador = 8; //DECLARAR EL PIN DEL PULSADOR

int almacen = 0; //PARA GUARDAR EL VALOR DEL PULSADOR
int valoranterior = 0;  //ESTADO ANTERIOR DEL PULSADOR
int on = 0;     //encender o apagar el LED

void setup() {
  pinMode(led, OUTPUT); //LED
  pinMode(pulsador, INPUT); //PULSADOR
  Serial.begin(9600);  //COMUNICACION CON EL SERIAL BEGIN

}

void loop() {
  almacen = digitalRead(pulsador); //LEE EL VALOR DEL PULSADOR, ALMACEN = PULSADOR

  if (almacen && valoranterior == 0) { //SI EL ALMACEN Y EL VALORANTERIOR SON IGUALES A 0 (SIEMPRE OCURRE CUANDO NO SE PULSA

    on = 1 - on;  //AL PRICIPIO ON ES 0, PERO LA RESTA DE 1-0 LO PONE A 1 Y ENTRA EN EL 2º IF. EN EL CASO DE QUE ON SEA 1 (1-1), CAMBIARIA A 0 Y ENTRARIA EN EL 1º ELSE
    delay(100); //DELAY ANTIRREBOTES
  }

  valoranterior = almacen;  //CAMBIA EL ESTADO DE VALORANTERIOR RESPECTO A ALMACEN. SI ALAMCEN ES 1 NO ENTRA EN EL 1º IF.

  if (on) {    //2º IF. CUANDO ON ES 1
    digitalWrite(led, 1);  //LED ENCENDIDO
  }

  else {  //1º ELSE CUANDO ON ES 0

    digitalWrite(led, 0);  //LED APAGADO
  }
}
