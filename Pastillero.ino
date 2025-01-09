/* Programa Pastillero con Alarma y Reloj */

#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 6, 11, 12, 13, 14);

int buzzerPin = 15;
int ledPin = 16;
int botonPin = 2;

boolean alarmaActivada = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(botonPin, INPUT_PULLUP);

  lcd.setCursor(0, 0);
  lcd.print("Hora actual:");
  lcd.setCursor(0, 1);
  lcd.print("00:00:00");

  while (digitalRead(botonPin) == HIGH) {
    // Espera
  }

  activarAlarma();
}

void loop() {
  int horaActual = hour();
  int minutoActual = minute();
  int segundoActual = second();

  // Formatea la hora en "hh:mm:ss"
  char horaFormateada[9];
  sprintf(horaFormateada, "%02d:%02d:%02d", horaActual, minutoActual, segundoActual);

  // Muestra la hora en el LCD
  lcd.setCursor(0, 1);
  lcd.print(horaFormateada);

  // Comprueba si es la hora de la toma y activa la alarma
  if (horaActual == 14 && minutoActual == 30 && alarmaActivada) {
    activarAlarma();
  }
}

void activarAlarma() {
  alarmaActivada = true;
  tone(buzzerPin, 1000);
  digitalWrite(ledPin, HIGH);

  lcd.setCursor(0, 0);
  lcd.print("Hora de tomar:");
  lcd.setCursor(0, 1);
  lcd.print("Pastillas");

  while (digitalRead(botonPin) == HIGH) {
    // Espera
  }

  alarmaActivada = false;
  noTone(buzzerPin);
  digitalWrite(ledPin, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Hora actual:");
  lcd.setCursor(0, 1);
  lcd.print("00:00:00");
}
