int TempoBuzzer;
int TempoLed;

//variabili che danno il tempo (random) che accendano il led ed il buzzer

int CreazioneTempoAccensioneLed = random (1000,4000); // do un valore random che sarà il delay prima dell'accensione
int CreazioneTempoAccensioneBuzzer = random (1000,4000); // do un valore random che sarà il delay prima dell'accensione
int StatoBottoneStart = 13;
int StatoBottoneLed = 2;
int StatoBottoneBuzzer = 5;
int buzzer = 7;
int VERDE = 11;
int BLU = 0;
int ROSSO = 9;
int ledblu = 3;


void setup(){
  //Imposto gli input
  
  pinMode(StatoBottoneStart,INPUT);
  pinMode(StatoBottoneLed,INPUT);
  pinMode(StatoBottoneBuzzer,INPUT);

  //Imposto gli output 
  
  pinMode(VERDE, OUTPUT);
  pinMode(BLU, OUTPUT);
  pinMode(ROSSO, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(ledblu,OUTPUT);

  //seriale 
  Serial.begin(9600);
}

void loop(){
  if (digitalRead(StatoBottoneStart) == HIGH) // se il bottone è premuto parte il gioco
  {
    digitalWrite(VERDE,LOW);
    digitalWrite(ROSSO,LOW);
    digitalWrite(BLU,LOW);

    delay (CreazioneTempoAccensioneLed); //delay random
    digitalWrite(ledblu,HIGH); // accendo il led 
    
    while(digitalRead(ledblu) == HIGH) //finchè il led è attivo sta nel ciclo
    {
      Serial.println("entarto");
      if (digitalRead(StatoBottoneLed) == HIGH)// se il giocatore ha premuto il bottone
      {
        
        digitalWrite(ledblu,LOW); // faccio terminare il ciclo
        Serial.println (TempoLed); // restituisco in output il tempo
        
      }
    else // se invece non è premuto 
    {
      
      while(digitalRead(StatoBottoneLed) == LOW) // bottone non è premuto
      {
        TempoLed++; // incremento il tempo fino alla premuta del pulsante
      }
      
    }
    delay(100);
    }
  delay (CreazioneTempoAccensioneBuzzer); //delay random
    
    digitalWrite(buzzer, HIGH);// attivo il buzzer
    tone(buzzer,1000,100); // assegno l'intensità del suono
    
    while(digitalRead(buzzer) == HIGH)//finchè il buzzer è attivo sta nel ciclo
    {
      Serial.println("entarto");
      if (digitalRead(StatoBottoneBuzzer) == HIGH)// se il giocatore ha premuto il bottone
      {
        
        digitalWrite(buzzer,LOW);// faccio terminare il ciclo
        Serial.println (TempoBuzzer);// restituisco in output il tempo
        
      }
    
    else// se invece non è premuto 
    {
     
      while(digitalRead(StatoBottoneBuzzer) == LOW)// bottone non è premuto
      {
        
        TempoBuzzer++; // incremento il tempo fino alla premuta del pulsante
        }
        }
        }
        
        if (TempoBuzzer < 500 && TempoLed < 500)
        {
          
          digitalWrite(VERDE,HIGH);
        }
        
        else{
          
          digitalWrite(ROSSO,HIGH);
        }
  }  
 }





 




