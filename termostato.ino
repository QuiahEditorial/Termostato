// Por Roberto A.Zavala
// Breve : 
// Libro : https://www.amazon.com.mx/dp/B074TTGLL2
// 🙏🏼   : DNv7acPAeVBhTXbKv26itJecPG1SPy2o4F

int   Tr = 2;                   // puerto del transistor
int   PT;                       // PWM aplicado al transistor
int   Tm = A0;                  // puerto del termistor
float To = 50;                  // temperatura objetivo

float A  = 0.001482484340;      // Coefientes de Steinhart-Hart
float B  = 0.000167799949;
float C  = 0.000000406675;
int   R  = 9950;                // resistencia de divisor de voltaje
float RT;                       // resistencia del termistor
float t;                        // temperatura

float Vs;                       // voltaje de salida 
int   Ve = 5;                   // voltaje de entrada

int   dl = 10000;               // periodo de la rutina

void setup()
  {
  Serial.begin(9600);
  pinMode( Tr,OUTPUT );
  Serial.println("Termostato :)");
  }

void loop()
{
  t = 0;
  for (int i=0; i <= 9; i++)    // se mide 10 veces la temperatura
    {
    Vs = (analogRead(Tra)/204.6);
    RT = (Ra*Vsa)/(Ve-Vsa);
    dT = Aa + Ba * log( RT ) + Ca * pow( log(RT) , 3 );
    T  = 1/dT;
    T  = T - 273.15;
    t = t + T; 
    delay(200);
    }
  t = t/10;                     // obtiene la temperatura

  if      ( t <  To ) { analogWrite ( Tr , PT ); PT = PT + 1; }  // si t < To aumenta la potencia
  else if ( t == To ) { analogWrite ( Tr , PT ); }               // si t = To se mantiene la potencia
  else                { analogWrite ( Tr, 0 );  PT = PT - 1; }   // si t > To se apaga y reduce en 1 la potencia
  
  delay(dl);
}
