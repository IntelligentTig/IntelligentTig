# IntelligentTig
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

### FUNCIONAMIENTO PASO A PASO
El funcionamiento se basa en las decisiones que toma el microcontrolador sobre las variables de entrada.
Para controlarlas tenemos la programación, que tiene en cuenta las variables de entrada,que en nuestro caso serian los datos recibidos del giroscopio y sensor de distancia.
El giroscopio y el sensor de distancia tienen 2 pines para la transmisión de datos, SDA SCL. Atraves de ellos enviaremos y recibiremos datos desde el microcontrolador.

En la programación tendremos una librería para calibrar el giroscopio antes de hacer mediciones con él.
Una vez tengamos el giroscopio calibrado en nuestra situación de reposo, habría que escalar en nuestra programación los datos.El sensor de distancia también necesitamos escalarlo para la programación, nosotros lo escalaremos en milímetros.
Con cada dato recibido por los sensores y por el microcontrolador, mediante la programación activara variables de salida.
En nuestro caso el giroscopio tendrá como salida una pantalla oled para displayar los grados en los que se mueve el giroscopio.Además de un led RGB que cambiara de color en base a los grados.

![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/protoboard.jpg)

En el caso del sensor de distancia en función de la distancia que mida, nosotros en la programación escalaremos en milímetros la distancia a medir, y las clasificamos en 3 tipos de grupos; Distancia-Muy cerca, Distancia-Correcta, Distancia-Fuera de rango. Para cada clasificación de los 3 grupos tendremos un led como salida de los datos de lectura del sensor de distancia. Siendo esta la clasificación; Ledrojo1: la distancia es muy cerca. Ledverde2: la distancia es correcta. Ledrojo3: la distancia fuera de rango.

Una vez hecha su programación, el sensor de distancia tomara los datos, en milímetros, los enviara al microcontrolador en el cual está la programación, para que cuando la distancia sea muy cercana o muy lejana se encienda el led rojo, y cuando la distancia de la punta de la herramienta Tig sea la correcta, a 2mm, se encenderá el led verde.

![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/protoboard%20DISTANCIA.jpg)

En el caso del giroscopio una vez lo hayamos calibrado con su librería previamente procederemos a escalarlo, en nuestro caso lo escalamos de -90º a 90º,  en la programación para poder visualizar en la pantalla los grados.
También hay que hacer la programación para que escale en la pantalla ambos grados, el Eje X y Eje Y, dividiendo la pantalla en dos para los datos de ambos ejes.
Ambos grados procederemos a añadir un RGB también para que según varíen los grados de los ejes, el color también variara.
Por ultimo hay que escalar también el led RGB, lo escalamos en base a la rueda de colores de Newton. Para que nos indique un color según en el grado en el que se encuentra la Tig.

Una vez hecha su programación, el giroscopio tomara los datos los enviara al microcontrolador en el cual está la programación. Para displayar en la pantalla los grados en los que se mueva al instante la herramienta tig,
tanto en el Eje X como en el Eje Y. Además como hemos mencionado antes del led RGB que también al instante cambia de color según se vaya moviendo la herramienta en ambos ejes.

![](https://github.com/IntelligentTig/IntelligentTig/blob/master/imagenes/rueda%20newton.jpg)

### CONSUMOS 
La primera conclusión si vas a usar un Arduino con baterías es que procures usar un Arduino Nano.
Porque parece que bate el record de eficiencia energética de los Arduinos.

El Nano tuvo un re-diseño reciente para esto precisamente y daros cuenta de que no incluye un regulador de tensión,
porque solo se puede alimentar por USB a 5V, o alimentándolo directamente con un fuente externa de 5V
y quitar ese chip libera ya unos 10 mAh de consumo.

* Arduino Nano tiene un consumo de 15mA.
* El giroscopio MPU6050 tiene un consumo de 500μA. 
* El sensor de distancia Vl53LOX tiene un consumo máximo 18mA. 
* El led neopixel RGB tiene un consumo de 1μA. 
* Nuestra herramienta Tig en todo su conjunto con todo los componentes tiene un consumo máximo de 34mA, nuestra batería 
  dispone de 1200mA de almacenamiento, dispondrá de una duración de batería nuestra Tig de (1200 mAh / 34 mA =) 35,29 
  horas.


### PLANO 
 Esquema general eléctrico  

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
 
