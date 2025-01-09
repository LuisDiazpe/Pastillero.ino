#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Conexión de la pantalla LCD

int buzzerPin = 15;
int ledPin = 16;
int botonPin = 9;
int interruptorPin = 13;

boolean alarmaActivada = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(botonPin, INPUT_PULLUP);
  pinMode(interruptorPin, INPUT_PULLUP);

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

  // Comprueba el interruptor para apagar la alarma
  if (digitalRead(interruptorPin) == LOW) {
    alarmaActivada = false;
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Hora actual:");
    lcd.setCursor(0, 1);
    lcd.print("00:00:00");
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
