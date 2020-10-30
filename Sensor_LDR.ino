float valor_sensor = 0,R1, IL;

void setup() {      //Configuracion de los pin como entrada o salida 
  Serial.begin(9600);    
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT);
}

void loop ()  //Configuracion de los valores del LDR
{
  valor_sensor = analogRead(A0); 
  valor_sensor = valor_sensor*(5.0/1023.0);
  R1=613*((5/valor_sensor)-1);
  IL=pow((R1/126951),-1.1655);

  
  Serial.println("Voltaje = ");
  Serial.print(valor_sensor);
  Serial.println(" Volts");
  Serial.println("Resistencia = ");
  Serial.print(R1);
  Serial.println(" ohms");
  Serial.println("Intensidad luminosa:");
  Serial.print(IL);
  Serial.print(" LUX");   
  Serial.println("");
  Serial.println("");    
  delay(1000);                       
  
  if (IL >= 2000)   //Si el valor de luz es menor o igual que el valor limite
  {
    digitalWrite (13, LOW);  //El relevador enciende
  }
  if (IL < 2000)   //Si es mayor que el valor limite
  {
    digitalWrite (13, HIGH);  //El relevador apaga
  }
}
