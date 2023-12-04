# Proyecto de medición de Material Particulado con ESP32
***
El proyecto se basa en un sistema que posea sensores ambientales destinados a la toma de datos de material particulado haciendo uso del sensor de partículas SDS011. Además, desarrollar una plataforma web que permita la visualización y análisis de los datos en tiempo real obtenidos por el prototipo de sistema de material particulado.
Es esencial monitorear y evaluar la concentración de material particulado en el aire, especialmente en entornos como las universidades, donde la comunidad puede estar expuesta de manera prolongada. Estos esfuerzos ayudan a obtener datos que pueden en un futuro servir para tomar medidas preventivas, implementar controles adecuados y promover un entorno más saludable para la comunidad universitaria.


Para la elaboración del prototipo se han elegido los siguientes componentes principales:

* `Sensor de Material Particulado SDS011:` Este sensor es crucial para medir la concentración de partículas en el aire, proporcionando datos precisos sobre la calidad del aire.
* `Microchip ESP32:` Este microchip se encargará del control y la gestión de datos. Es conocido por su versatilidad y capacidad de comunicación eficiente.
* `Módulo GPS NEO 6M:` Para la recopilación de datos de ubicación geográfica, se utilizará un módulo GPS que permitirá geolocalizar cada medición de calidad del aire.
* `Indicadores LED:` Se implementaron Leds para indicar visualmente el estado operativo del prototipo, facilitando la verificación y el diagnóstico rápido.


## :hammer:Funcionalidades del proyecto
- `Dispositivo IoT`: Este dispositivo estará equipado con un sensor de material particulado, específicamente el SDS011, controlado por el microchip ESP32. El prototipo también integrará un módulo GPS para la recopilación de datos de ubicación y contará con indicadores visuales, como Leds, para verificar su funcionamiento en tiempo real.
- `Plataforma Web para Visualización `: La información recopilada por el dispositivo se transmitirá a una plataforma especializada para dispositivos IoT, en este caso, se utilizará ThingSpeak. Esta plataforma proporcionará capacidad de almacenamiento y gestión de datos en la nube. Para la visualización de datos en tiempo real, se implementará Grafana. La interfaz de Grafana permitirá la creación de gráficos dinámicos y personalizados, proporcionando una representación visual clara y comprensible de los niveles de material particulado en la página web dedicada.
- `Alertas`: La plataforma de visualización de datos estará vinculada a Grafana, una herramienta especializada en análisis que facilitará la interpretación de los datos recopilados. Se implementarán alertas directamente en la plataforma para notificar sobre situaciones de calidad del aire preocupantes. Estas alertas se configurarán para enviar notificaciones a través de Telegram y por correo a Gmail. 


## 🖥️ Tecnologías
- Arduino
- ThingSpeak 
- Grafana
- Angular


***
## Estrutura del proyecto

![MP_Estructura](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/c44aff2d-b871-4452-b852-b56fbcaeb651)

*** 
## Diagrama de conexiones

![Diagrama Proyecto](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/4692f78a-acea-4e90-8abb-af8a81baa625)

## Dispositivo
![WhatsApp Image 2023-11-13 at 19 47 31](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/b559cf11-bce8-4341-ad15-58b552a1e246)
![WhatsApp Image 2023-11-13 at 19 47 31 (1)](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/b7541bee-c064-4d1c-b36b-eca11ade68fd)


### Arduino
![Captura de pantalla (627)](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/77d75c0d-1a23-48f0-b0a5-904afed3bfde)

### ThingSpeak
![Captura de pantalla (669)](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/4101ff2f-cb69-4453-aad3-c3e26fc37863)

### Grafana
![Imagen1](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/f7176438-8b12-491f-873a-c91c48d24880)




***
## Alertas

###Telegram
![IMG_6397](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/c5e66967-6abf-491b-8908-324a1a21e5e6)
![IMG_6398](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/79b066bf-44f3-4d19-980c-c48470b1e57e)

### Gmail 
![Captura de pantalla 2023-11-30 141016](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/1ee334e7-b38b-4306-a531-3bcef70a2883)
![Captura de pantalla 2023-11-30 141035](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/79c68d37-ad2b-4591-bc6a-962568051616)
![Captura de pantalla 2023-11-30 141054](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/2d400575-2df9-402b-bd3f-d3617522d37f)

***
## Página
![Captura de pantalla (660)](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/1a49a14f-61d8-41ff-9d26-513e9886f495)
![Captura de pantalla (662)](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/9936da3d-3ad5-48be-8ebf-a65f0f4cdf10)
![Captura de pantalla (663)](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/4533bd86-e53f-4f04-b658-d56ea203925b)
![Captura de pantalla (665)](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/f101f62f-b967-465a-806d-0898876e91d8)
![Captura de pantalla (666)](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/05dabc99-41ad-4d6b-8cc7-e35f9b6f59af)
![Captura de pantalla (667)](https://github.com/AnthyS12/Sistema_MaterialParticulado_IOT/assets/50304139/764f20f1-aec4-4b57-b601-0b990b617a87)


## Autor
Anthony Moreira
