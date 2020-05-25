# INTELLIGENT TIG
### Proyecto creado por Manuel Pesantez y Ander Irizabal.

## 1 INTRODUCCIÓN 
La empresa intelligentTig tiene un proyecto de una herramienta para el departamento de soldadura, cubriendo la necesidad de un simulador como alternativa. La herramienta ofrece la posibilidad de hacer pruebas de mecanizado de soldadura sin utilizar gas ni distintos materiales necesarios para soldar, y sin exponer alumnos a riesgos.  
  
## 2 REQUERIMIENTOS
El objetivo principal es que los alumnos de soldadura dispongan de una herramienta alternativa que no disponían. Para uso de aprendizaje sin riesgos, con una forma y peso similar a una tig real para aprender con esta herramienta antes de iniciarse con una real y así dominar varios aspectos y técnicas de que mecanizado de soldadura sin riesgo alguno. 

## 3 ESPECIFICACIONES 
### Esquema de bloques  

![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/esquema2.jpg)


### Arduino Nano
La placa Arduino Nano es una placa de prueba pequeña y completa basada en ATmega328.Solo carece de jack de alimentación DC y funciona con un cable Mini-B USB en lugar de uno estándar.
En nuestro proyecto es el que controla nuestra herramienta. El cual está situado dentro de una caja para protegerlo y ocultarlo.

![](https://raw.githubusercontent.com/IntelligentTig/IntelligentTig/master/imagenes/arduino.jpg)

**Caracteristicas:**

![](https://raw.githubusercontent.com/IntelligentTig/IntelligentTig/master/imagenes/nano.jpg)

### Giroscopio
EL MPU6050 es una unidad de medición inercial o IMU de 6 grados de libertad pues combina un acelerómetro de 3 ejes y un giroscopio de 3 ejes. Nosotros lo utilizaremos para saber en qué grados se mueve nuestra herramienta, para ello añadiremos una pantalla Oled. 

![](https://raw.githubusercontent.com/IntelligentTig/IntelligentTig/master/imagenes/giroescopio.jpg)

CONEXIONES ENTRE ARDUINO Y MPU6050

![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/conexion%20giroscopio.jpg)


### Sensor de distancia
VL53LOX:Es un sensor de distancia infrarrojo láser, que podemos emplear junto con un procesador como Arduino para medir distancias milimétricas muy precisas.

El integrado incorpora un emisor laser 940nm VCSEL (Vertical Cavity Surface-Emitting Laser), un detector SPAD (Single Photon Avalanche Diodes) y la electrónica interna (denominada FlightSenseTM) que realiza los cálculos necesarios.

![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/distancia-2.jpg)

CONEXIONES ENTRE ARDUINO Y VL53LOX 


![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/distanciaconexion.jpg)


### Pantalla Oled
Pantalla LCD OLED de 0.96 pulgadas que será la encargada de displayar los datos de nuestro giroscopio al instante para que
podamos visualizarlo.

CONEXIONES ENTRE ARDUINO Y PANTALLA OLED 

![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/oledconexion.jpg)

### WRGB
El led RGB (Red, Green, Blue) es un led que combina estos tres colores para formar más de 16 millones de tonos de luz. De esta forma, dependiendo de la tonalidad pasada como parámetro, podemos emitir un color de luz u otro.

Los colores del Led RGB vienen representados con números comprendidos entre el valor 0 y el valor 255. De esta forma, para componer el color rojo pondríamos el valor máximo del rojo y el valor mínimo de los otros colores, es decir, el rojo equivale a "R=255; G=0; B=0".

![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/RGB.jpg)

CONEXIONES ARDUINO Y WRGB

![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/DATARGB.jpg) 

### Chasis
El chasis seria una réplica exacta de la herramienta original para simular que estamos cogiendo la misma herramienta. Nuestra réplica es de PLA hecha en la impresora 3D.


![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/chasis.jpg)

### CONSTRUCCIÓN PASO A PASO CHASIS  
El material que hemos utilizado para el chasis de la Tig tanto para la caja que guarda la batería y arduino es de PLA, impresos en una impresora 3D. Hemos hecho el chasis de la Tig en 2 piezas para poder introducir los componentes en su interior. 
Además de hacer varios soportes adicionales añadidos al chasis de Tig varios componentes, para pantalla, giroscopio y sensor distancia. Dichos soportes también fueron impresos en PLA en una impresora 3D.  

1.- Primeramente vemos como funciona el giroscopio, como poder juntarlo a la pantalla y como programarlo para que nos displaye los grados en la pantalla. Además del sensor de distancia también como funciona y su calibración.

El giroscopio detecta los grados en base a la fuerza gravitacional y en base a una calibración previa. Después la pantalla nos proporciona los datos del giroscopio de forma digital, en la cual podremos dividir los datos en ella para reflejar los grados de más de un eje(X, Y o Z). El arduino seria el controlador del sensor giroscopio y de la pantalla. La programación será en arduino lenguaje C++.

2.- Ahora una vez puesto en funcionamiento el giroscopio, pantalla y arduino, con una librería calibraremos nuestro sensor giroscopio. Una vez haya hecho sus lecturas correspondientes y calibremos con la ayuda del monitor serial, añadiremos un nuevo programa para que displaye los datos del giroscopio nuestra pantalla.

![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/protoboard.jpg)

3.- Una vez puesto en marcha también nuestro sensor de distancia, lo calibramos con ayuda del monitor serial y como salida le pusimos 3 led delimitando la distancia en 3 partes, Muy cerca,
Distancia correcta y Fuera de rango. Todo ello conectado también con arduino y sus propias librerías y partes de programación.

![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/protoboard%20DISTANCIA.jpg)

4.- Hemos hecho un gran avance pero ahora toca unir todo los programas a uno, y además le añadimos un led más RGBW y su parte de programación correspondiente.
El led RGBW es una salida del giroscopio para hacer referencia a los grados mediante la rueda de colores de Newton.

![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/rueda%20newton.jpg)

5.- Ahora colocamos los componentes en sus correspondientes soportes y pasando el cableado por el interior del chasis de la Tig procedemos a pegar las dos piezas con pegamento. Una vez seco y con el cableado pasado por la tig lo forramos con tubo termorretráctil hasta la caja, impresa en PLA, donde tenemos ubicado el arduino y la bateria.

6.- Para finalizar ajustamos nuestra herramienta Tig para realizar pruebas de mecanizado con ellas de forma correcta sin errores y de forma precisa en la pantalla y leds.

### PLANOS
 Esquema general 

![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/esquemageneral.jpg)

## 4 PUESTO A PUNTO Y TESTEO

Para la puesta a punto lo dividiremos en dos fases. La primera pensar y buscar información de aquello que deseas hacer, para después programarlo que sería el trabajo más complejo para nosotros ya que es la que nos ha llevado más tiempo, esfuerzo y aprendizaje. Para así poder ajustarlo de la forma deseada y que el programa fuera lo más preciso y sin errores.

La segunda fase es la parte mecánica y electrónica de nuestro reto. Todo lo que lo completa desde el chasis, sensores, cableado. Para ello hemos dividido el trabajo en pequeños bloques  y al final uniendo todas esas partes hemos conseguido finalizar nuestro proyecto de la forma en la que nos lo propusimos. Una de las mayores dificultades aparte de la programación fue reducir todo para que formaran una pieza a escala original y que todas las partes cerraron y  así  conseguir los resultados deseados en el conjunto.

## 5 PRESUPUESTO
Para nuestro proyecto hemos utilizado los recursos que teníamos a nuestro alcance pero haremos el presupuesto del hipotético caso de que hubiésemos comprado todos los componentes para hacer nuestro proyecto.

![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/tabla%20presupuesto.jpg)

 
 
## 6 CONCLUSIONES
Ha sido un reto complicado debido a la escasa información de un simulador de aprendizaje de TIG. Prácticamente casi todo el proyecto ha sido búsqueda de información y programación en Arduino. Añadir que utilizamos una plataforma llamada Trello y que gracias a ella hemos llevado bastante al día el proyecto con una buena organización y control del tiempo que disponíamos.

## 7 REFERENCIAS 
Las librerías con los programas de ejemplo, los hemos obtenido de los siguientes enlaces:

https://www.luisllamas.es/conectar-arduino-a-una-pantalla-oled-de-0-96/

https://github.com/ElektronikaDonBosco/Inclinometro

https://teslabem.com/arduino/tutorial-de-neopixel-con-arduino/

https://naylampmechatronics.com/blog/45_Tutorial-MPU6050-Aceler%C3%B3metro-y-Giroscopio.html


**3D**

Esta página hemos buscado partes para completar el chasis

https://www.thingiverse.com/

**Tinkercad**

Esta página la hemos utilizado para simular las partes de los montajes de nuestro proyecto.    
https://www.tinkercad.com/
 




