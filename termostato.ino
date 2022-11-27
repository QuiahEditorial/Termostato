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

  if      ( Ta <  To ) { analogWrite (Tta,round(PTa)); PTa = PTa + 1;}
  else if ( Ta == To ) { analogWrite (Tta,PTa); }
  else                 { analogWrite (Tta, 0 );  PTa = PTa - 1;}

  Tc = 0;
for (int k=0; k <= 9; k++)
  {
  Vsc = (analogRead(Trc)/204.8);
  RTc = (Rc*Vsc)/(Ve-Vsc);
  dTc = Ac + Bc*log(RTc) + Cc*pow(log(RTc),3);
  tc  = 1/dTc;
  T   = tc-273.15;
  Tc  = T + Tc;
  delay(200);
  }

if      ( Tb < 45 ) { analogWrite (Ttc,round(PTc)); PTc = PTc + 1;}
else if ( Tb = 45 ) { analogWrite (Ttc,PTc); }
else                { digitalWrite(Ttc,0 );  PTc = PTc -1;}

if ( x % 2 ) { lcd.setCursor(0,1); lcd.write("C "); lcd.print(Tc,1);}
else         { lcd.setCursor(2,1); lcd.print(int(PTc)); lcd.print("  ");}

}
