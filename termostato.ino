int Tr = 2;                   // puerto del transistor
int Ra = 9950;                // resistencia de divisor de voltaje
int Tm = A0;                  // puerto del termistor

float Aa = 0.001482484340;    // Coefientes de Steinhart-Hart
float Ba = 0.000167799949;
float Ca = 0.000000406675;

float T=0;
float Ta;
float Tb;
float Tc;

float RT;                     // resistencia del transistor

float Vsa;                    // voltaje de salida 
int   Ve = 5;                 // voltaje de entrada

int   PT;                     // PWM aplicado al transistor
float To;                     // temperatura objetivo


void setup()
  {
  pinMode( Tr,OUTPUT );
  }

void loop()
  {
  t = 0;                                           // Temperatura
  for (int i=0; i <= 9; i++)
    {
    Vs = (analogRead(Tra)/204.6);
    RT = (Ra*Vsa)/(Ve-Vsa);
    dT = Aa + Ba*log(RTa) + Ca*pow(log(RTa),3);
    T  = 1/dT;
    T  = T - 273.15;
    t = t + T; 
    delay(200);
    }
  t = t/10;

  if      ( t <  To ) { analogWrite ( Tr , PT ); PT = PT + 1; }  // si t < To aumenta la potencia
  else if ( t == To ) { analogWrite ( Tr , PT ); }               // si t = To se mantiene la potenica
  else                { analogWrite ( Tr, 0 );  PT = PT - 1; }   // si t > To se apaga y reduce en 1 la potencia
}
