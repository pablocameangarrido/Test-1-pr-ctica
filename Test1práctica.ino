Autor: Pablo Cameán Garrido
Data: Febreiro 2024
*/

//Declaración de pines
#define PULS 10       // Pulsador
#define INVS 13       // Inversor
#define MOTORUP 5    // Motor sube
#define MOTORDOWN 6  // Motor baixa
#define POT A0

//Declaración de variables
int contador = 0;
int motorActivo = 0;
int pot = 0;      // Almacena o valor lido do sensor de luminosidade
int rangomap = 0;      // Almacena o valor mapeado do sensor de luminosidade


void setup() {
  pinMode(PULS, INPUT_PULLUP);
  pinMode(MOTORUP, OUTPUT);
  pinMode(MOTORDOWN, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  digitalWrite(13, HIGH);
}

void loop() {
  
  if (digitalRead(PULS) == 1) {
    
    // Apaga ambos motores ó cambiar o motor activo
    digitalWrite(MOTORUP, LOW);
    digitalWrite(MOTORDOWN, LOW);
    if (contador > 0){
    contador = 0; 
    }
    else  {
      motorActivo = !motorActivo;  // Cambia o estado do motor activo
      if (motorActivo == 1) {  
    digitalWrite(MOTORUP, HIGH);  // Activa o MotorUP
      Serial.println("MotorUP activado");
 
    } 
    	else {
      		digitalWrite(MOTORDOWN, HIGH);  // Activa o MotorDOWN
      		Serial.println("MotorDOWN activado");
          
    		} 
      contador = 100; // Espera 90 segundos para apagar o motor
    }
       while(digitalRead(PULS) == 1) { // Espera a que se solte o pulsador
      	delay(10);
    	}
  }
  if(contador < 0) {
    digitalWrite(MOTORUP, LOW);
    digitalWrite(MOTORDOWN, LOW);
  }
    contador -= 1;
    delay(10);
  
  pot = analogRead(POT);
  Serial.print("Valor lido "); Serial.println(pot);
        Serial.print("Cor:"); Serial.println(cor);
  //delay(tempo);
  // Asignar un nivel (unha cor) (catro niveis)
  // Escribir o valor no LED RGB
  if(pot == 0) {
    digitalWrite(12, HIGH);
  }
 
  else if(pot >= 0 && pot <204) {
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
  }
   else if(pot >= 408 && pot < 612) {
    // Encenda verde
     setVerde();
  }
   else if(pot >= 612 && pot < 816) {
    // Encenda azul
     setAzul();
  }
   else {
    // Encenda blanco
     setBranco();
  }
}

  Serial.print("Contador: ");
  Serial.println(contador);
  Serial.println(analogRead(LDR));
}
