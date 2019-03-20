int TempoBuzzer;
int TempoLed;
int pinLed;
int Buzzer;

//stati dei bottoni

int StatoBottoneBuzzer = LOW; // stato bottone buzzer
int StatoBottoneStart = LOW; // stato bottone Start
int StatoBottoneLed = LOW; // stato bottone led 
int StatoBuzzer = LOW; // stato buzzer 

//variabili che danno il tempo (random) che accendano il led ed il buzzer

int CreazioneTempoAccensioneLed; 
int CreazioneTempoAccensioneBuzzer;

//pin a cui sarà collegato i pulsanti, buzzer ed i led 
int buttonInizio = 1;
int btn_primoRiflesso = 2 ;
int btn_secondoRiflesso = 3;
int buzzer = 4;
int VERDE = 5;
int BLU = 6;
int ROSSO = 7;



void setup(){
  
  // assegnamento valori del tempo
  
  TempoBuzzer = 0; // tempo iniziale parte da 0
  TempoLed = 0; // tempo iniziale parte da 0
  
  // assegnamento valori random
  
  CreazioneTempoAccensioneLed = random (1000,4000); // do un valore random che sarà il delay prima dell'accensione
  CreazioneTempoAccensioneBuzzer = random (1000,4000); // do un valore random che sarà il delay prima dell'accensione
  
  //Imposto gli input
  
  pinMode(buttonInizio,INPUT);
  pinMode(btn_primoRiflesso,INPUT);
  pinMode(btn_secondoRiflesso,INPUT);
  pinMode(buttonInizio,INPUT);

  //Imposto gli output 
  
  pinMode(VERDE, OUTPUT);
  pinMode(BLU, OUTPUT);
  pinMode(ROSSO, OUTPUT);
  pinMode(buzzer,OUTPUT);
  
  
}
void loop(){
  if (StatoBottoneStart == HIGH) // se il bottone è premuto parte il gioco
  {
    digitalWrite(VERDE,LOW);
    digitalWrite(ROSSO,LOW);
    digitalWrite(BLU,LOW);

    delay (CreazioneTempoAccensioneLed); //delay random
    digitalWrite(pinLed,HIGH); // accendo il led 
    
    while(pinLed == HIGH) //finchè il led è attivo sta nel ciclo
    {
      
      if (StatoBottoneLed == HIGH)// se il giocatore ha premuto il bottone
      {
        
        digitalWrite(pinLed,LOW); // faccio terminare il ciclo
        return TempoLed; // restituisco in output il tempo
        
      }
    
    else // se invece non è premuto 
    {
      
      while(StatoBottoneLed == LOW) // bottone non è premuto
      {
        TempoLed++; // incremento il tempo fino alla premuta del pulsante
      }
    }
  }
  delay (CreazioneTempoAccensioneBuzzer); //delay random
    
    digitalWrite(Buzzer, HIGH);// attivo il buzzer
    tone(Buzzer,1000,100); // assegno l'intensità del suono
    
    while(Buzzer == HIGH)//finchè il buzzer è attivo sta nel ciclo
    {
      
      if (StatoBuzzer == HIGH)// se il giocatore ha premuto il bottone
      {
        
        digitalWrite(Buzzer,LOW);// faccio terminare il ciclo
        return TempoBuzzer;// restituisco in output il tempo
        
      }
    
    else// se invece non è premuto 
    {
     
      while(StatoBuzzer == LOW)// bottone non è premuto
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




