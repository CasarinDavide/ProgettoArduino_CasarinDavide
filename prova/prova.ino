int TempoBuzzer;
int TempoLed;

//variabili che danno il tempo (random) che accendano il led ed il buzzer

int CreazioneTempoAccensioneLed; 
int CreazioneTempoAccensioneBuzzer;
int StatoBottoneStart;
int StatoBottoneLed;
int StatoBottoneBuzzer;
int buzzer;
int VERDE;
int BLU;
int ROSSO;
int ledblu;




void setup(){

  //pin a cui sarà collegato i pulsanti, buzzer ed i led 
int StatoBottoneStart = 4;
int StatoBottoneLed = 6 ;
int StatoBottoneBuzzer = 7;
int buzzer = 2;
int VERDE = 5;
int BLU = 0;
int ROSSO = 3;
int ledblu = 1;
  // assegnamento valori del tempo
  
  TempoBuzzer = 0; // tempo iniziale parte da 0
  TempoLed = 0; // tempo iniziale parte da 0
  
  // assegnamento valori random
  
  CreazioneTempoAccensioneLed = random (1000,4000); // do un valore random che sarà il delay prima dell'accensione
  CreazioneTempoAccensioneBuzzer = random (1000,4000); // do un valore random che sarà il delay prima dell'accensione
  
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
    
    while(ledblu == HIGH) //finchè il led è attivo sta nel ciclo
    {
      
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
  }
  delay (CreazioneTempoAccensioneBuzzer); //delay random
    
    digitalWrite(buzzer, HIGH);// attivo il buzzer
    tone(buzzer,1000,100); // assegno l'intensità del suono
    
    while(buzzer == HIGH)//finchè il buzzer è attivo sta nel ciclo
    {
      
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




