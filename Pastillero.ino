/* Programa Pastillero con Alarma */

// Incluye la biblioteca para LCD
#include <LiquidCrystal.h>

// Pines para el LCD
LiquidCrystal lcd(4, 6, 11, 12, 13, 14);

// Pines para la alarma
int buzzerPin = 15;
int ledPin = 16;

// Botón para apagar la alarma
int botonPin = 2;
boolean alarmaActivada = false;

// Hora de inicio (2:30 PM)
int horaToma = 14;
int minutoToma = 30;

void setup() {
  // Inicializa el LCD
  lcd.begin(16, 2);

  // Configura el pin del buzzer y el LED como salida
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Configura el pin del botón como entrada
  pinMode(botonPin, INPUT_PULLUP); // Usamos PULL-UP para evitar resistencia externa

  // Muestra el mensaje inicial en el LCD
  lcd.setCursor(0, 0);
  lcd.print("Hora de tomar:");
  lcd.setCursor(0, 1);
  lcd.print("Pastillas");

  // Espera a que el botón sea presionado para activar la alarma
  while (digitalRead(botonPin) == HIGH) {
    // Espera
  }

  // Activa la alarma
  activarAlarma();
}

void loop() {
  // Obtiene la hora actual
  int horaActual = hour();
  int minutoActual = minute();

  // Comprueba si es la hora de la toma
  if (horaActual == horaToma && minutoActual == minutoToma && alarmaActivada) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hora de tomar:");
    lcd.setCursor(0, 1);
    lcd.print("Pastillas");
    activarAlarma();
  }
}

void activarAlarma() {
  // Activa la alarma (enciende el buzzer y el LED)
  alarmaActivada = true;
  tone(buzzerPin, 1000); // Tono de alarma
  digitalWrite(ledPin, HIGH);

  // Muestra el mensaje en el LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hora de tomar:");
  lcd.setCursor(0, 1);
  lcd.print("Pastillas");

  // Espera a que el botón sea presionado para apagar la alarma
  while (digitalRead(botonPin) == HIGH) {
    // Espera
  }

  // Apaga la alarma (detiene el buzzer y apaga el LED)
  alarmaActivada = false;
  noTone(buzzerPin);
  digitalWrite(ledPin, LOW);
}
