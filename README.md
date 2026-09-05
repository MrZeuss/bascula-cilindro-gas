# Báscula inteligente para cilindro de gas

## Descripción
Plataforma de pesaje permanente con cuatro celdas, HX711, ESP32-C3, Wi-Fi y dashboard histórico.

## Arquitectura / decisiones
Lecturas 09:00 y 21:00. HX711 DT→GPIO4, SCK→GPIO5. Dashboard detecta salto de peso y pregunta Confirmar/Ignorar posible cambio de cilindro.

## Estructura
- `docs/`: descripción, mejoras y notas.
- `hardware/`: conexiones y notas de montaje.
- `images/`: diagramas generados durante el desarrollo.
- `code/`: firmware o plantillas disponibles.
- `bom/`: lista de materiales.

## Estado
Repositorio de documentación consolidado desde el hilo de diseño. Los esquemas gráficos son guías de montaje; antes de fabricar una PCB definitiva conviene verificar pinouts y datasheets de los módulos concretos.
