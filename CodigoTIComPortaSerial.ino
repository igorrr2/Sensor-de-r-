  #define echo 3 //Pino que recebe o pulso do echo   
  #define trig 2 //Pino que envia o pulso para gerar o echo   

int ledVermelho=13;
int ledVerde=11;
const int buzzer = 4;
int tempo, dist;
int receptor;

  
  
  // Executado na inicialização do Arduino   
  void setup(){   
  Serial.begin(9600); // inicializa a comunicação serial   
  pinMode(buzzer,OUTPUT);
  pinMode(echo, INPUT);  // define o pino echo como entrada.
  pinMode(trig, OUTPUT); // define o pino triger como saída. 
  
  pinMode(ledVermelho, OUTPUT); 
  pinMode(ledVerde, OUTPUT);
  
  }   
 
  void loop(){   
  
  if(Serial.available()>0){
      receptor=Serial.read();
        Serial.println(receptor);
      
    if(receptor==49 || receptor==53){
          digitalWrite(ledVerde,HIGH);
          digitalWrite(ledVermelho,LOW);
      }
    if(receptor==48 || receptor==52){
          digitalWrite(ledVerde,LOW);
          digitalWrite(ledVermelho,LOW);
      }  
  }
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);

  tempo=pulseIn(echo,HIGH);
  
  dist=(tempo/2)/29.1;
    if(dist<150){
      if(receptor==48){
        digitalWrite(ledVerde,LOW);
        digitalWrite(ledVermelho,LOW);
        noTone(buzzer);
        }
      else if(receptor==49){
        digitalWrite(ledVermelho,HIGH);
        digitalWrite(ledVerde,LOW);
        noTone(buzzer);
      }
      else if(receptor==50){
        digitalWrite(ledVerde,LOW);
        digitalWrite(ledVermelho,LOW);
        noTone(buzzer);
      }
      else if(receptor==51){
        digitalWrite(ledVerde,LOW);
        digitalWrite(ledVermelho,LOW);
        tone(buzzer,1000);
      }
      else if(receptor==52){
        digitalWrite(ledVerde,LOW);
        digitalWrite(ledVermelho,LOW);
        noTone(buzzer);
      }
      else if(receptor==53){
    digitalWrite(ledVermelho,HIGH);
        digitalWrite(ledVerde,LOW);
        tone(buzzer,1000);  
      }
    }
    if(dist>150){
      if(receptor==48){
        digitalWrite(ledVerde,LOW);
        digitalWrite(ledVermelho,LOW);
        noTone(buzzer);
        }
      else if(receptor==49){
        digitalWrite(ledVermelho,LOW);
        digitalWrite(ledVerde,HIGH);
        noTone(buzzer);
      }
      else if(receptor==50){
        digitalWrite(ledVerde,LOW);
        digitalWrite(ledVermelho,LOW);
        noTone(buzzer);
      }
      else if(receptor==51){
        digitalWrite(ledVerde,LOW);
        digitalWrite(ledVermelho,LOW);
        noTone(buzzer);
      }
      else if(receptor==52){
        digitalWrite(ledVerde,LOW);
        digitalWrite(ledVermelho,LOW);
        noTone(buzzer);
      }
      else if(receptor==53){
    digitalWrite(ledVermelho,LOW);
        digitalWrite(ledVerde,HIGH);
        noTone(buzzer); 
      }
    }
  delay(100);
  } 
