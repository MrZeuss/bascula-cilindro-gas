// Plantilla inicial - báscula de cilindro de gas
// Ajustar factor de calibración después de montar la plataforma.
#include "HX711.h"

constexpr int PIN_DT  = 4;
constexpr int PIN_SCK = 5;

HX711 scale;
float factorCalibracion = 1.0f; // REEMPLAZAR tras calibrar

float leerPesoFiltrado() {
  const int N = 30;
  double suma = 0;
  for (int i=0; i<N; ++i) {
    if (scale.is_ready()) suma += scale.get_units(1);
    delay(20);
  }
  return suma / N;
}

void setup() {
  Serial.begin(115200);
  scale.begin(PIN_DT, PIN_SCK);
  scale.set_scale(factorCalibracion);
  // NO hacer tare() automáticamente con el cilindro instalado.
}

void loop() {
  float peso = leerPesoFiltrado();
  Serial.printf("Peso: %.2f kg\n", peso);
  scale.power_down();
  delay(1000); // En producción: despertar a las 09:00 y 21:00.
  scale.power_up();
}
