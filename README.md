# Pastillero Automático

Este proyecto implementa un sistema automático de pastillero utilizando Arduino. El sistema incluye un LCD para mostrar la hora, una alarma con LED y zumbador, y un motor que gira una rueda para dispensar pastillas en horarios predefinidos.

## Características
- **Despliegue de hora:** Muestra la hora actual en una pantalla LCD de 16x2.
- **Alarma:** Activa un zumbador y un LED cuando es hora de tomar las pastillas.
- **Dispensador automático:** Maneja un motor para girar la rueda del pastillero.
- **Control manual:** Botón para apagar la alarma.

## Requisitos de hardware
- Arduino (cualquier modelo compatible con las librerías y pines descritos).
- Pantalla LCD (16x2).
- Zumbador.
- LED.
- Motor (controlado por pines PWM).
- Interruptor.
- Botón.

## Configuración de pines
- **LCD:**
  - RS: Pin 12
  - E: Pin 11
  - D4: Pin 5
  - D5: Pin 4
  - D6: Pin 3
  - D7: Pin 2
  - R/W: Conectado a tierra
- **Interruptor:** Pin 13
- **Botón:** Pin 9
- **Zumbador:** Pin 15
- **LED:** Pin 16
- **Motor:**
  - Dirección: Pin 7 (PWM)
  - Activación: Pin 8

## Instalación
1. Conecta los componentes al Arduino según la configuración de pines indicada.
2. Carga el código del archivo `Pastillero.ino` en el Arduino utilizando el IDE de Arduino.
3. Alimenta el Arduino y verifica que el LCD muestra la hora correctamente.

## Uso
1. **Hora inicial:** La hora inicial está configurada en el código como las 2:30 AM. Puedes cambiarla modificando las variables `horaInicio` y `minutoInicio` en la función `setup`.
2. **Alarma:**
   - La alarma se activa automáticamente cuando el interruptor está presionado.
   - El LCD muestra un mensaje indicando que es hora de tomar la pastilla.
   - El zumbador y el LED también se encienden.
3. **Apagar alarma:** Presiona el botón para apagar la alarma y detener el zumbador y el LED.

## Cómo funciona
1. **Pantalla LCD:** Actualiza cada medio segundo (`tiempoRet = 500 ms`) mostrando la hora actual.
2. **Alarma:**
   - Se activa al presionar el interruptor.
   - El mensaje "Hora de tomar pastilla" aparece en la segunda línea del LCD.
   - Se desactiva al presionar el botón.
3. **Motor:**
   - Puedes agregar funciones adicionales como `ActivarMotor` y `DetenerMotor` para dispensar pastillas automáticamente cuando la alarma se activa.

## Personalización
- Cambia la hora inicial en la función `setup` según tus necesidades.
- Modifica los mensajes del LCD en las funciones `MostrarMensaje` y `Despliegue`.
- Ajusta el tiempo de actualización cambiando el valor de `tiempoRet`.

## Créditos
Este proyecto fue diseñado para automatizar la dispensación de medicamentos, mejorando la puntualidad en la toma de pastillas.

