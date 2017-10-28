  
unsigned long lastDebounceTime[4] = {0}; 
unsigned long debounceDelay = 500;    
const int buttonPin[4]= {2,3,4,5}; 
const int ledPin[4]= {6,7,8,9}; 

            int ledState[4] = {HIGH,HIGH,HIGH,HIGH};  
            int buttonState[4]= {LOW,LOW,LOW,LOW};             
            int lastButtonState[4] = {LOW,LOW,LOW,LOW};
            int reading[4];
            char alpha[] = {'a','b','c','d'};

void setup() 
{
  Serial.begin(9600);
  int i;
  for(i=0;i<4;i++)
         { 
           pinMode(buttonPin[i], INPUT);
           pinMode(ledPin[i], OUTPUT);
           digitalWrite(ledPin[i], ledState[i]);
         }
}



void loop()

{
int k;
  for(k=0;k<4;k++)
 { 

   reading[k] = digitalRead(buttonPin[k]);
        
  
  if (reading[k] != lastButtonState[k])
              {
                  lastDebounceTime[k] = millis();
              }

  if ((millis() - lastDebounceTime[k]) > debounceDelay)
  {
          
           if (reading[k] != buttonState[k]) 
           {  
                buttonState[k] = reading[k];
                
                         if (buttonState[k] == HIGH) 
                         {
                              ledState[k] = !ledState[k];
                              if(buttonState[0]==HIGH && buttonState[1]==HIGH)
                              Serial.print('e');
                              else if(buttonState[0]==HIGH && buttonState[2]==HIGH)
                              Serial.print('f');
                              else
                              Serial.print(alpha[k]);
                             
                         }
                         
            
           }
  }

  
  digitalWrite(ledPin[k], ledState[k]);
   
                          
                            

lastButtonState[k]= reading[k];                           
 
  }

}
