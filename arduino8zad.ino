#define nadajnik 2
#define odbiornik 3
int odleglosc;
long czas_bodzca = 0;

void setup()
{
 Serial.begin (9600);
 pinMode(nadajnik, OUTPUT);
 pinMode(odbiornik, INPUT);
}

void loop()
{
 digitalWrite(nadajnik, HIGH);
 delayMicroseconds(10);
 digitalWrite(nadajnik, LOW);

 czas_bodzca = pulseIn(odbiornik, HIGH);
 odleglosc = czas_bodzca/58;

//Zakres pomiaru odległości
  if ( odleglosc < 5 || odleglosc> 200 )
   Serial.println("Przedmiot znajduje się za daleko");
  else
  {
   Serial.print("Przedmiot znajduje się w zakresie: ");
   Serial.print(odleglosc);
   Serial.println("cm");
  }
 delay(500);
}
