int IN1 = 8;
int IN2 = 7;
int ENA = 9;

int IN3 = 13;
int IN4 = 12;
int ENB = 11;

int sensorIzq = 2;
int sensorDer = 4;

void setup() {

  Serial.begin(9600);

  pinMode(sensorIzq, INPUT);
  pinMode(sensorDer, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {

  int izq = digitalRead(sensorIzq);
  int der = digitalRead(sensorDer);

  Serial.print("Izq: ");
  Serial.print(izq);
  Serial.print("  Der: ");
  Serial.println(der);

  /*
    0 = detecta línea
    1 = no detecta línea
  */

  // Ambos sensores en línea
  if (izq == 0 && der == 0) {

    avanzar();
  }

  // Sensor izquierdo fuera de línea
  // Debe girar a la izquierda
  else if (izq == 1 && der == 0) {

    girarIzquierda();
  }

  // Sensor derecho fuera de línea
  // Debe girar a la derecha
  else if (izq == 0 && der == 1) {

    girarDerecha();
  }

  // Ambos fuera de línea
  else {

    detener();
  }

  delay(5);
}

// ===================== AVANZAR =====================
void avanzar() {

  // Motor derecho
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 90);

  // Motor izquierdo
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 90);

}

// ===================== GIRAR DERECHA =====================
void girarDerecha() {

  // Motor derecho detenido
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 90);

  // Motor izquierdo avanza
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 90);
      delay(50);
}

// ===================== GIRAR IZQUIERDA =====================
void girarIzquierda() {

  // Motor derecho avanza
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 90);

  // Motor izquierdo detenido
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 90);
      delay(50);
}

// ===================== DETENER =====================
void detener() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}