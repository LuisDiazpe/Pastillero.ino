/*
   Despliega en un LCD la hora, activa una alarma con mensaje, LED y zumbador, 
   y maneja un motor que gira la rueda del pastillero.

   Configuración de pines:
   * Pin RS del LCD al pin 12
   * Pin E del LCD al pin 11
   * Pin D4 del LCD al pin 5
   * Pin D5 del LCD al pin 4
   * Pin D6 del LCD al pin 3
   * Pin D7 del LCD al pin 2
   * Pin R/W del LCD a tierra
   * Pin del interruptor al pin 13
   * Pin del botón al pin 9
   * Pin del zumbador al pin 15
   * Pin del LED al pin 16
   * Pin del motor al pin 7 (PWM)
   * Pin del motor al pin 8
*/

#include <LiquidCrystal.h>

// Variables LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Variables de tiempo
long tiempoBase;
int tiempoRet = 500;

// Variables de alarma
int pinInterruptor = 13;
int pinBoton = 9;
int pinZumbador = 15;
int pinLED = 16;
boolean alarmaActivada = false;

// Variables de motor
int pinMotorDir = 7;  // Pin PWM para dirección
int pinMotorEn = 8;   // Pin de control motor

void setup() {
  // Configuración del LCD
  lcd.begin(16, 2);

  // Hora de reinicio
  int horaInicio = 2;
  int minutoInicio = 30;
  tiempoBase = horaInicio * 3600000L + minutoInicio * 60000L;

  // Configuración de pines
  pinMode(pinInterruptor, INPUT_PULLUP);  // Utiliza una resistencia pull-up interna
  pinMode(pinBoton, INPUT_PULLUP);        // Utiliza una resistencia pull-up interna
  pinMode(pinZumbador, OUTPUT);
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinZumbador, LOW);
  digitalWrite(pinLED, LOW);
  
  // Configuración del motor
  pinMode(pinMotorDir, OUTPUT);
  pinMode(pinMotorEn, OUTPUT);
  digitalWrite(pinMotorDir, LOW);   // Motor girando en sentido horario (CW)
  digitalWrite(pinMotorEn, LOW);    // Motor desactivado al inicio
}

void loop() {
  long tiempoActual = millis() + tiempoBase;
  int horaActual = tiempoActual / 3600000L;
  int minActual = (tiempoActual % 3600000L) / 60000;
  int segActual = (tiempoActual % 60000) / 1000;

  Despliegue(horaActual, minActual, segActual);

  // Verifica si el interruptor está presionado
  if (digitalRead(pinInterruptor) == LOW) {
    if (!alarmaActivada) {
      ActivarAlarma();
      alarmaActivada = true;
      MostrarMensaje("Hora de tomar pastilla");
    }
  } else {
    alarmaActivada = false;
  }

  // Verifica si el botón está presionado para apagar la alarma
  if (digitalRead(pinBoton) == LOW) {
    ApagarAlarma();
  }

  delay(tiempoRet);
}

void Despliegue(int horaActual, int minActual, int segActual) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hora ");
  lcd.print(horaActual);
  lcd.print(":");
  lcd.print(minActual);
  lcd.print(":");
  lcd.print(segActual);
}

void MostrarMensaje(const char *mensaje) {
  lcd.setCursor(0, 1);
  lcd.print("                "); // Limpia la línea
  lcd.setCursor(0, 1);
  lcd.print(mensaje);
}

void ActivarAlarma() {
  digitalWrite(pinZumbador, HIGH);
  digitalWrite(pinLED, HIGH);
}

void ApagarAlarma() {
  digitalWrite(pinZumbador, LOW);
  digitalWrite(pinLED, LOW);
  lcd.setCursor(0, 1);
  lcd.print("                "); // Limpia la línea
}

void ActivarMotor() {
  digitalWrite(pinMotorDir, HIGH);  // Cambia la dirección del motor (CW)
  digitalWrite(pinMotorEn, HIGH);   // Activa el motor
}

void DetenerMotor() {
  digitalWrite(pinMotorDir, LOW);   // Para el motor
  digitalWrite(pinMotorEn, LOW);    // Desactiva el motor
}
