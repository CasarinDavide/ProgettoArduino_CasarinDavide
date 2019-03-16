int TempoBuzzer;
int TempoLed;
int pinLed;
int Buzzer;
int StatoBottoneBuzzer = LOW;
int StatoBottoneStart = LOW;
int StatoBottoneLed = LOW;
int StatoBuzzer = LOW;
int CreazioneTempoAccensioneLed;
int CreazioneTempoAccensioneBuzzer;



void setup(){
  TempoBuzzer = 0;
  TempoLed = 0;
  CreazioneTempoAccensioneLed = random (1000,4000);
  CreazioneTempoAccensioneBuzzer = random (1000,4000);
  
  
  
  
}
void loop(){
  if (StatoBottoneStart == HIGH){
    delay (CreazioneTempoAccensioneLed);
    digitalWrite(pinLed,HIGH);
    while(pinLed == HIGH){
      
      if (StatoBottoneLed == HIGH){
        digitalWrite(pinLed,LOW);
        return TempoLed;
        
      }
    else{
      while(StatoBottoneLed == LOW)
      {
        TempoLed++;
      }
    }
  }
  delay (CreazioneTempoAccensioneBuzzer);
    digitalWrite(Buzzer, HIGH);
    tone(Buzzer,1000,100);
    while(Buzzer == HIGH){
      
      if (StatoBuzzer == HIGH){
        digitalWrite(Buzzer,LOW);
        return TempoBuzzer;
        
      }
    else{
      while(StatoBuzzer == LOW){
        TempoBuzzer++;
        }
        }
        }
  }  
 }




