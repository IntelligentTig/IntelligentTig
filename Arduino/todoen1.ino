//LIBRERIAS
#include <MPU6050_tockn.h>                              //Sensor MPU6050
#include <Wire.h>                                       //Comunicaión I2c entre pantalla, sensor y arduino nano
#include <Adafruit_SSD1306.h>                           //Pantalla
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>  
#define PIN   6 // Designamos nuestro pin de datos.
#define NUMPIXELS 1 // Designamos cuantos pixeles tenemos

#include <VL53L0X.h>
VL53L0X sensor;
int LED_1 = 11;//ROJO
int LED_2 = 10; //VERDE
int LED = 9; // rojo 
int n_Samples = 3; // numero de muestras para promediar

//#define LONG_RANGE // Aumenta sensibilidad, +rango, -precision
//#define HIGH_SPEED // Mayor velocidad, menor precision
#define HIGH_ACCURACY // Alta precision, menor velocidad


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//Pines
/*MPU6050
 * VCC 5v
 * GND GND
 * SDA A4
 * SCL A5
 * AD0 GND
 * INT 2
 */
 /*OLED
  * GND GND
  * VCC 5V
  * SDA A4
  * SCL A5
  */

//DECLARACIONES
#define SCREEN_WIDTH 128                        // Anchura pantalla OLED, en pixels
#define SCREEN_HEIGHT 32                        // Altura pantalla OLED, en pixels
// Declaración para la pantalla SSD1306 conectada a I2C (SDA, SCL pins)
#define OLED_RESET     4                        // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, & Wire, OLED_RESET);
#define PinPulsador  3                  //Asignamos el pin numero 3 a PinPulsador
int Pulsador = 0;                     //Creamos la variable Pulsador para que almacene el valor de PinPulsador
int AnguloX = 0;                        //Creamos la variable AnguloX para que almacene el valor del angulo en el eje X
int AnguloY = 0;                        //Creamos la variable AnguloY para que almacene el valor del angulo en el eje Y

MPU6050 mpu6050(Wire);


void setup() {
   Serial.begin(9600);
 Wire.begin();

 sensor.init();
 sensor.setTimeout(500);

//###### Parametros Medida simple ##########
#if defined LONG_RANGE
// Limite de la tasa de retorno (por defecto 0.25 MCPS)
 sensor.setSignalRateLimit(0.1);
// Periodo de pulso laser (por defecto 14 y 10 PCLKs)
 sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
 sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
#endif

#if defined HIGH_SPEED
// reduce tiempo estimado a 20 ms (por defecto 33 ms)
 sensor.setMeasurementTimingBudget(20);
#elif defined HIGH_ACCURACY
// incrementa tiempo estimado a 200 ms
 sensor.setMeasurementTimingBudget(200);
#endif


  Wire.begin();                                 //Iniciamos la comunicación Wire
  mpu6050.begin();                              //Iniciamos la comunicación con el sensor
  mpu6050.setGyroOffsets(-3.05, 1.17, -0.56);   //X : -3.05; Y : 1.17; Z : -0.56; Offsets conseguidos por serie con el prorama GetAllData
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);    // Address 0x3C for 128x32
  // Clear the buffer
  display.clearDisplay();
  // Mostrar el buffer de pantalla en la pantalla. ¡DEBES llamar a display() después de dibujar comandos para hacerlos visibles en la pantalla!
   
  display.setTextSize(3);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 3);     // Start at top-left corner
  display.print ("I.TIG");   // Texto inicial al encender la tig
  display.display();
  delay(2000);                  //Tiempo que esta mostrando el texto inicial

  display.clearDisplay();
  // Mostrar el buffer de pantalla en la pantalla. ¡DEBES llamar a display() después de dibujar comandos para hacerlos visibles en la pantalla!
   
  display.setTextSize(3);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 3);     // Start at top-left corner
  display.print ("EJE X 1");   // Texto inicial al encender la tig eje x en posicion 1 de boton
  display.display();
      pixels.begin(); // Inicializamos el led rgb

  Serial.begin (9600);
  delay(2000);  
  pinMode(PinPulsador,INPUT);                 //Declaramos que PinPulsador va a ser entrada digital
  
}

void loop() {    //eje X
  mpu6050.update();
  display.clearDisplay();

      ///////////////////Grados de inclinacion\\\\\\\\\\\\\\\\\\\\\\\\ > <
      
    AnguloX = mpu6050.getAngleX();        //Obtenemos el valor de angulo de inclinación y lo metemos en la variable AnguloX

  if(AnguloX > 90){AnguloX = 90;}         //Si la variable AnguloX es mayor que 90º lo igualamos a 90º
  if(AnguloX < -90){AnguloX = -90;}       //Si la variable AnguloX es menor que -90º lo igualamos a -90º


///manu
 float DISTANCIA = sensor.readRangeSingleMillimeters();
 
 
 if (sensor.timeoutOccurred()) {
 //Serial.println(" TIME OUT");
 }else {
 if (DISTANCIA< 0) Serial.println("Fuera de Rango (d < 50 mm)");
 else if (DISTANCIA>220) Serial.println("Fuera de Rango (d > 220 mm)");
 else { 
 Serial.print(DISTANCIA, 1); // distancia en cm y 1 decimal
 Serial.println(" mm"); 
 }
 }
// delay (100);
  if(DISTANCIA <=70){ // PIN 11
  analogWrite(11,255);
  analogWrite(10,0);
  analogWrite(9,0);
  }
 // if(DISTANCIA <=61){ // PIN 11
 // analogWrite(11,0);
  //analogWrite(10,255);
  //analogWrite(9,0);
 // }
 if (DISTANCIA >=71){ // PIN 10
  analogWrite(11,0);
  analogWrite(10,255); 
  analogWrite(9,0);
  }
  if(DISTANCIA >76 ){ //PIN 9
  analogWrite(11,0);
  analogWrite(10,0);
  analogWrite(9,255);
}
 
///manu
////////////////////////////PANTALLA\\\\\\\\\\\\\\\\\\\\\\\

    Pulsador = digitalRead(PinPulsador);    //Leemos el estado del Pulsador
    if(Pulsador == LOW){                    //Si esta en High mostramos en pantalla la inclinacion en grados
      if(AnguloX > 0 ){                      //Si el angulo es mayor a 0 colocamos una flecha en el lado derecho de la pantalla
        display.setTextSize(4);
        display.setCursor(102,3);
        display.print ((char) 16);
      }
      if(AnguloX < 0){                        //Si el angulo es menor a 0 colocamos una flecha en el lado izquierdo de la pantalla
        display.setTextSize(4);
        display.setCursor(0,3);
        display.print ((char) 17);
      }
      display.setTextSize(4);                       // Tamaño de fuente
      display.setTextColor(WHITE);                  // Draw white text
      if(AnguloX < 10 && AnguloX > -10){            // De 10 a -10 grados de inclinadion al ser un digito lo ubicamos centrado
          display.setCursor(55, 3);
      }
      else{                                           // 10 o mayor centramos los dos digitos en la pantalla
          display.setCursor(38, 3);                     // Start at top-left corner
      }
      display.print (abs(AnguloX));                      //Añadimos ",0" para que muestre el valor en la pantalla sin decimales
      // Para el simbolo de Grado "º"
      display.setTextSize(2);                       // Normal 1:1 pixel scale
      display.setTextColor(WHITE);                  // Draw white text
      //display.setCursor(110,0);                   // Start at top-left corner
      display.print("o");                           //Para mostrar el simbolo de grados "º" en la pantalla
      display.display();
    }
 //eje Y
 mpu6050.update();
  display.clearDisplay();

      ///////////////////Grados de inclinacion\\\\\\\\\\\\\\\\\\\\\\\\ > <
      
    AnguloY = mpu6050.getAngleY();        //Obtenemos el valor de angulo de inclinación y lo metemos en la variable AnguloY

  if(AnguloY > 90){AnguloY = 90;}         //Si la variable AnguloY es mayor que 90º lo igualamos a 90º
  if(AnguloY < -90){AnguloY = -90;}       //Si la variable AnguloY es menor que -90º lo igualamos a -90º



////////////////////////////PANTALLA\\\\\\\\\\\\\\\\\\\\\\\

    Pulsador = digitalRead(PinPulsador);    //Leemos el estado del Pulsador
    if(Pulsador == HIGH){                    //Si esta en High mostramos en pantalla la inclinacion en grados
      if(AnguloY > 0 ){                      //Si el angulo es mayor a 0 colocamos una flecha en el lado derecho de la pantalla
        display.setTextSize(4);
        display.setCursor(102,3);
        display.print ((char) 24);
      }
      if(AnguloY < 0){                        //Si el angulo es menor a 0 colocamos una flecha en el lado izquierdo de la pantalla
        display.setTextSize(4);
        display.setCursor(0,3);
        display.print ((char) 25);
      }
      display.setTextSize(4);                       // Tamaño de fuente
      display.setTextColor(WHITE);                  // Draw white text
      if(AnguloY < 10 && AnguloY > -10){            // De 10 a -10 grados de inclinadion al ser un digito lo ubicamos centrado
          display.setCursor(55, 3);
      }
      else{                                           // 10 o mayor centramos los dos digitos en la pantalla
          display.setCursor(38, 3);                     // Start at top-left corner
      }
      display.print (abs(AnguloY));                      //Añadimos ",0" para que muestre el valor en la pantalla sin decimales
      // Para el simbolo de Grado "º"
      display.setTextSize(2);                       // Normal 1:1 pixel scale
      display.setTextColor(WHITE);                  // Draw white text
      //display.setCursor(110,0);                   // Start at top-left corner
      display.print("o");                           //Para mostrar el simbolo de grados "º" en la pantalla
      display.display();
    }

int red = 0;
int green = 0;
int blue = 0;




if (AnguloX >= 0){

    if (AnguloX >= 30){
      AnguloX = 30;
    }
        Serial.println (AnguloX);
red = map(AnguloX,0,30,0,255);
        Serial.println (red);
}

if (AnguloX <= 0){

AnguloX = - AnguloX;

    if (AnguloX >= 30){
      AnguloX = 30;
    }
        Serial.println (AnguloX);
blue = map(AnguloX,0,30,0,255);
green = blue;
}

   
if (AnguloY >= 0){

    if (AnguloY >= 30){
      AnguloY = 30;
    }
        Serial.println (AnguloY);
green = map(AnguloY,0,30,0,255);
        Serial.println (red);
}

if (AnguloY <= 0){

AnguloY = - AnguloY;

    if (AnguloY >= 30){
      AnguloY = 30;
    }
        Serial.println (AnguloY);
blue = map(AnguloY,0,30,0,255);
red = blue;
}
    uint32_t color = pixels.Color(red,green,blue);
  for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i,color);
    pixels.show(); 
      
}
}
