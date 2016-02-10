int motortransporte = 6;
int motorcepillos = 7;
int ventiladorhorno = 41;
int reabastecimiento = 39;
int electrovalvulas = 43;
//int pwmtrans = A0;
//int pwmcep = A5;
int niquelinahorno = 53;
int niquelinarevelador = 51;
int recirculacion = 45;
int goma = 47;
int sensorrevelador = A0;
int sensorhorno = A1;
int muestrasrevelador[10];
int muestrashorno[10];
int valuerevelador = 0;
int valuehorno = 0;
int muestras[2];
int temperaturas[2];
float mediarevelador=0;
float mediahorno=0;
int estadoeplaca = 0;
int estadosplaca = 0;
int eplaca = 37;
int splaca = 35;
int timme=0;
int currentTime=0;
int previousTime=0;
byte byteRead;
long tiempo_inicio=0;
long tiempo_actual=0;
long previousMillis = 0;
long interval = 120000;
int var=1;
int valmotores=0;
int valcepillos=0;
int valor=0;
String mijitrin;
void setup() { 
  // put your setup code here, to run once:
//pinMode(motortransporte,OUTPUT);
pinMode(electrovalvulas,OUTPUT);
//pinMode(motorcepillos,OUTPUT);
pinMode(reabastecimiento,OUTPUT);
pinMode(ventiladorhorno,OUTPUT);
pinMode(niquelinahorno,OUTPUT);
pinMode(niquelinarevelador,OUTPUT);
pinMode(recirculacion,OUTPUT);
pinMode(goma,OUTPUT);
pinMode(eplaca,INPUT);
pinMode(splaca,INPUT);
Serial.begin(9600);
Serial1.begin(9600);
Serial1.println("9");
digitalWrite(recirculacion,LOW); 
digitalWrite(niquelinarevelador,LOW); 
valmotores=255;
     valcepillos=255;
    digitalWrite(recirculacion,LOW); 
    digitalWrite(recirculacion,LOW); 
    analogWrite(motortransporte,valmotores);
    analogWrite(motorcepillos,valcepillos);
    digitalWrite(reabastecimiento,LOW);
    digitalWrite(ventiladorhorno,LOW);
    digitalWrite(electrovalvulas,LOW);
    digitalWrite(niquelinahorno,LOW);
    digitalWrite(goma,LOW);
    digitalWrite(ventiladorhorno,LOW);
    

}

void loop(){
 if(var!=0){ 
 promedio();
    //Serial1.println(String(int(mediarevelador)));
   //Serial.println(String(int(mediarevelador))); 
    if(mediarevelador<670){
      digitalWrite(niquelinarevelador,HIGH);
    }else{
      digitalWrite(niquelinarevelador,LOW);
    } 


digitalWrite(recirculacion,HIGH);   
}
switch(var){
  case 8:
      digitalWrite(electrovalvulas,HIGH);
      
        
  break;
  case 0:
      
      detener();
      while(Serial1.available()){
        valor=Serial1.read();
        Serial1.println(valor);
        
        
        /*if(){
          var=1;
          Serial.println("mijin");
        }
        */
        //delay(1000);
      }
      
      
      
      
      if(valor==97){
          var=1;
       }
      /*if(mijitrin.length()==1){
        Serial.println(mijitrin);
        
        if(mijitrin.equals("a")){
          var=1;
        }
        mijitrin="";
      }*/

      
  break;
  case 1:
      mijitrin="";
      detener();
     
      /*if(Serial.available()){
      
      }
      /*if(mijo=31){
       var=-1;
      }*/

    
    currentTime=millis();
    if(currentTime-previousTime>500){
      impresion();
      previousTime=currentTime;
    }
    /*
    else{
      
      int mijo=Serial1.read();
      if(mijo==49){
        Serial.println("bacan");
        var=8;
      }
      
    }*/
    Serial.println(digitalRead(eplaca));
    if(digitalRead(eplaca)==LOW){
      var=2;
      impresion();
      Serial.print("Aparecio una placa");
      delay(25);
    }
    
    timme=millis();
  break;
  
  case 2:
  detener();
     valmotores=145;
     valcepillos=180;
    analogWrite(motortransporte,valmotores);
    analogWrite(motorcepillos,valcepillos);
    digitalWrite(reabastecimiento,HIGH);
    retardo(2);
    digitalWrite(reabastecimiento,LOW);
    retardo(20);
    var=3;
     
  break;
  case 3:
    detener();
    digitalWrite(goma,HIGH);
    digitalWrite(ventiladorhorno,HIGH);
    digitalWrite(electrovalvulas,HIGH);
    digitalWrite(niquelinahorno,HIGH);
    


    
    retardo(70);
    resetear();
    
  break;
  
}
}
void reseteartotal(){
      var=0;
    valmotores=255;
     valcepillos=255;
    digitalWrite(recirculacion,LOW); 
    digitalWrite(recirculacion,LOW); 
    analogWrite(motortransporte,valmotores);
    analogWrite(motorcepillos,valcepillos);
    digitalWrite(reabastecimiento,LOW);
    digitalWrite(ventiladorhorno,LOW);
    digitalWrite(electrovalvulas,LOW);
    digitalWrite(niquelinahorno,LOW);
    digitalWrite(goma,LOW);
    digitalWrite(ventiladorhorno,LOW);
    previousTime=currentTime;

}
void detener(){
  /*if(Serial1.available()){
    int orden=Serial1.read();
      Serial.println(""+orden);
      if(orden==56){
        Serial.println("Se apagó todo");
        
        asm("jmp 0x0000"); 
        reseteartotal();
      }
    }*/
    while(Serial1.available()){
        valor=Serial1.read();
        //Serial.println("bien");
        
        
        /*if(){
          var=1;
          Serial.println("mijin");
        }
        */
        //delay(1000);
      }
      
      
      
      
      
      if(mijitrin.length()==1){
        Serial.println(mijitrin);
        
        if(mijitrin.equals("8")){
          reseteartotal();
          //asm("jmp 0x0000"); 
          
        }
        mijitrin="";
      }
    
  }

void resetear(){
      var=1;
    valmotores=255;
     valcepillos=255;
    analogWrite(motortransporte,valmotores);
    analogWrite(motorcepillos,valcepillos);
    digitalWrite(reabastecimiento,LOW);
    digitalWrite(ventiladorhorno,LOW);
    digitalWrite(electrovalvulas,LOW);
    digitalWrite(niquelinahorno,LOW);
    digitalWrite(goma,LOW);
    digitalWrite(ventiladorhorno,LOW);
    previousTime=currentTime;

}

void promedio(){


for(int i=0;i<10;i++){
  
    valuerevelador=analogRead(sensorrevelador);
    //valuehorno=analogRead(sensorhorno);
     muestrasrevelador[i]= valuerevelador;
     //muestrashorno[i]= valuehorno;
     
     delay(10);
    }
    
  for(int i=0;i<10;i++){
    mediarevelador +=muestrasrevelador[i];
    //mediahorno +=muestrashorno[i];
  
  }
  mediarevelador /=10;
  //mediahorno /=10;
 
 

}
void retardo(int total){
  //for(int i=0;i<=total*2;i++){
    int tottal=2*total;
    int valoreal=tottal;
    int tiempo=valoreal;
    while(tottal!=0){
      
    //imprimir serial
    impresion();
    detener();
    delay(475);
    Serial1.println(tottal);
    int h=0;
    if(tottal==130){
      digitalWrite(reabastecimiento,HIGH);
      delay(1500);
    
      
     }else{
      digitalWrite(reabastecimiento,LOW);
      }
    if(digitalRead(eplaca)==LOW && var==3){
      tiempo=valoreal-tottal;
      if(tiempo>=0 && tiempo<14){
        tottal=tottal+10;  
      }else if(tiempo>=14 && tiempo<30){
        tottal=tottal+20;  
      }else if(tiempo>=30 && tiempo<45){
        tottal=tottal+30;  
      }else if(tiempo<=0){
        tottal=190;  
      }
      else{
        tottal=tottal+40;  
      }
      
      delay(25);
    }
    promedio();
    /*if(mediarevelador<670){
      digitalWrite(niquelinarevelador,HIGH);
    }else{
      digitalWrite(niquelinarevelador,LOW);
    }*/
    tottal=tottal-1;
  }
  
  
}

void impresion(){
  
  int rec=0;
  int gom=0;  
  int trans=0;
  int elec=0;
  int cep=0;
  int reb=0;
  int venth=0;
  int nih=0;
  int niqv=0;
  
  if(digitalRead(recirculacion)==HIGH){
    rec=1;
  }
  if(digitalRead(goma)==HIGH){
    gom=1;
  }else{
    gom=0;
  }
  
  if(valmotores==145){
    trans=1;
  }else{
    trans=0;
  }
  
  if(digitalRead(electrovalvulas)==HIGH){
    elec=1;
  }else{
    elec=0;
  }
  if(valcepillos==180){
    cep=1;
  }else{
    cep=0;
  }
  
  if(digitalRead(reabastecimiento)==HIGH){
    reb=1;
  }else{
    reb=0;
  }
  if(digitalRead(ventiladorhorno)==HIGH){
    venth=1;
  }else{
    venth=0;
  }
  if(digitalRead(niquelinahorno)==HIGH){
    nih=1;
  }else{
    nih=0;
  }
  if(digitalRead(niquelinarevelador)==HIGH){
    niqv=1;
  }else{
    niqv=0;
  }
  String dato="("+String(rec)+","+String(gom)+","+String(trans)+
  ","+String(elec)+","+String(cep)+","+String(reb)+
  ","+String(venth)+","+String(nih)+","+String(niqv)+","+String(int(mediarevelador))+")";
  Serial1.println(dato);
  Serial.println(var);
}

char Decimal_to_ASCII(int entrada){
char salida=' ';
switch(entrada){
case 32: 
salida=' '; 
break; 
case 33: 
salida='!'; 
break; 
case 34: 
salida='"'; 
break; 
case 35: 
salida='#'; 
break; 
case 36: 
salida='$'; 
break; 
case 37: 
salida='%'; 
break; 
case 38: 
salida='&amp;'; 
break; 
case 39: 
salida=' '; 
break; 
case 40: 
salida='('; 
break; 
case 41: 
salida=')'; 
break; 
case 42: 
salida='*'; 
break; 
case 43: 
salida='+'; 
break; 
case 44: 
salida=','; 
break; 
case 45: 
salida='-'; 
break; 
case 46: 
salida='.'; 
break; 
case 47: 
salida='/'; 
break; 
case 48: 
salida='0'; 
break; 
case 49: 
salida='1'; 
break; 
case 50: 
salida='2'; 
break; 
case 51: 
salida='3'; 
break; 
case 52: 
salida='4'; 
break; 
case 53: 
salida='5'; 
break; 
case 54: 
salida='6'; 
break; 
case 55: 
salida='7'; 
break; 
case 56: 
salida='8'; 
break; 
case 57: 
salida='9'; 
break; 
case 58: 
salida=':'; 
break; 
case 59: 
salida=';'; 
break; 
case 60: 
salida='&lt;'; 
break; 
case 61: 
salida='='; 
break; 
case 62: 
salida='&gt;'; 
break; 
case 63: 
salida='?'; 
break; 
case 64: 
salida='@'; 
break; 
case 65: 
salida='A'; 
break; 
case 66: 
salida='B'; 
break; 
case 67: 
salida='C'; 
break; 
case 68: 
salida='D'; 
break; 
case 69: 
salida='E'; 
break; 
case 70: 
salida='F'; 
break; 
case 71: 
salida='G'; 
break; 
case 72: 
salida='H'; 
break; 
case 73: 
salida='I'; 
break; 
case 74: 
salida='J'; 
break; 
case 75: 
salida='K'; 
break; 
case 76: 
salida='L'; 
break; 
case 77: 
salida='M'; 
break; 
case 78: 
salida='N'; 
break; 
case 79: 
salida='O'; 
break; 
case 80: 
salida='P'; 
break; 
case 81: 
salida='Q'; 
break; 
case 82: 
salida='R'; 
break; 
case 83: 
salida='S'; 
break; 
case 84: 
salida='T'; 
break; 
case 85: 
salida='U'; 
break; 
case 86: 
salida='V'; 
break; 
case 87: 
salida='W'; 
break; 
case 88: 
salida='X'; 
break; 
case 89: 
salida='Y'; 
break; 
case 90: 
salida='Z'; 
break; 
case 91: 
salida='['; 
break; 
case 92: 
salida=' '; 
break; 
case 93: 
salida=']'; 
break; 
case 94: 
salida='^'; 
break; 
case 95: 
salida='_'; 
break; 
case 96: 
salida='`'; 
break; 
case 97: 
salida='a'; 
break; 
case 98: 
salida='b'; 
break; 
case 99: 
salida='c'; 
break; 
case 100: 
salida='d'; 
break; 
case 101: 
salida='e'; 
break; 
case 102: 
salida='f'; 
break; 
case 103: 
salida='g'; 
break; 
case 104: 
salida='h'; 
break; 
case 105: 
salida='i'; 
break; 
case 106: 
salida='j'; 
break; 
case 107: 
salida='k'; 
break; 
case 108: 
salida='l'; 
break; 
case 109: 
salida='m'; 
break; 
case 110: 
salida='n'; 
break; 
case 111: 
salida='o'; 
break; 
case 112: 
salida='p'; 
break; 
case 113: 
salida='q'; 
break; 
case 114: 
salida='r'; 
break; 
case 115: 
salida='s'; 
break; 
case 116: 
salida='t'; 
break; 
case 117: 
salida='u'; 
break; 
case 118: 
salida='v'; 
break; 
case 119: 
salida='w'; 
break; 
case 120: 
salida='x'; 
break; 
case 121: 
salida='y'; 
break; 
case 122: 
salida='z'; 
break; 
case 123: 
salida='{'; 
break; 
case 124: 
salida='|'; 
break; 
case 125: 
salida='}'; 
break; 
case 126: 
salida='~'; 
break; 
}
return salida;
}

