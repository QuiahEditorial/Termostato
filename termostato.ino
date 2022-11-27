int Tta = 6;     //Transistor

int Ra = 9950;  // Resistencia

int Tra = A0;    //Termistor

float Aa = 0.001482484340;
float Ba = 0.000167799949;
float Ca = 0.000000406675;

float T=0;
float Ta;
float Tb;
float Tc;

float RT;

float Vsa;
float Vsb;
float Vsc;
int   Ve = 5;

float  PTa = 0;

int x ;

void setup()
{
  lcd.begin(16, 2);
  pinMode(Tta,OUTPUT);
  x=0;
}

void loop()
{

x = x+1;

T = 0;
for (int i=0; i <= 9; i++)
{
Vsa = (analogRead(Tra)/204.6);
RTa = (Ra*Vsa)/(Ve-Vsa);
dTa = Aa + Ba*log(RTa) + Ca*pow(log(RTa),3);
ta = 1/dTa;
T  = ta-273.15;
Ta = Ta + T; 
delay(200);
}

Ta = Ta / 10;
if      ( Ta < 38 )  { analogWrite (Tta,round(PTa)); PTa = PTa + 1;}
else if ( Ta == 38 ) { analogWrite (Tta,PTa); }
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
