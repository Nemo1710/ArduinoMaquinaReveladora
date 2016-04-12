#include <DueFlashStorage.h>
#include <efc.h>
#include <flash_efc.h>

//objeto para el uso de memoria flash
DueFlashStorage dueFlashStorage;
byte motorvalores = 118;
int motortransporte = 6;
int motorcepillos = 7;
float ret=22;
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
int valcepillos=0;
int valmotores=0;

int valor=0;
String mijitrin;
void setup() { 
  dueFlashStorage.write(0,motorvalores);
  dueFlashStorage.write(1,ret);
  
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
Serial.println("estamos viendo todo desde el computador");
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

    
    



/*      
      detener();
  */    
      
      
      
      
      /*if(valor==97){
          var=1;
       }*/
      /*if(mijitrin.length()==1){
        Serial.println(mijitrin);
        
        if(mijitrin.equals("a")){
          var=1;
        }
        mijitrin="";
      }*/

      
  break;
  case 1:


      if(Serial1.available()){
      int orden=Serial1.read();
      Serial.println(dueFlashStorage.read(0));
      Serial.println(orden);
      
      if(orden>=48 && orden <=63){
        //Serial.println(recepcionmotor(orden));
        
        dueFlashStorage.write(0,recepcionmotor(orden+3));
        dueFlashStorage.write(1,orden-38);
        Serial.println("Exito se recibio el dato");
      }
     }

     ret=ret/22;
     ret=ret*dueFlashStorage.read(1);
     Serial.println(dueFlashStorage.read(1));
     Serial.println(dueFlashStorage.read(0));
     Serial.println(analogRead(sensorrevelador));
    
    //Serial.println(int(ret));
    ret=22;
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
    //Serial.println(digitalRead(eplaca));
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
    ret=22;
     valmotores=dueFlashStorage.read(0);
     valcepillos=180;
    analogWrite(motortransporte,valmotores);
    analogWrite(motorcepillos,valcepillos);
    digitalWrite(reabastecimiento,HIGH);
    retardo(1);
    digitalWrite(reabastecimiento,LOW);
    
    ret=ret/22;
    ret=ret*dueFlashStorage.read(1);
    retardo(int(ret));
    
    Serial.println(ret);
    
    var=3;
     
  break;
  case 3:
    detener();
    digitalWrite(niquelinahorno,HIGH);
    digitalWrite(ventiladorhorno,HIGH);
    digitalWrite(electrovalvulas,HIGH);

    digitalWrite(goma,HIGH);

    
    
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
    while(Serial.available()){
        valor=Serial.read();
        //Serial.println("bien");
        
        
        /*if(){
          var=1;
          Serial.println("mijin");
        }
        */
        //delay(1000);
      }
      Serial.println(""+valor);
      Serial.println(""+recepcionmotor(valor));
      
      
      /*
      
      if(mijitrin.length()==1){
        Serial.println(mijitrin);
        
        if(mijitrin.equals("8")){
          reseteartotal();
          //asm("jmp 0x0000"); 
          
        }
        mijitrin="";
      }*/
    
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
    Serial.println(dueFlashStorage.read(0));
    delay(475);
    Serial1.println(tottal);
    int h=0;
    if(tottal==130){
      digitalWrite(reabastecimiento,HIGH);
      delay(250);
      digitalWrite(reabastecimiento,LOW);    
      
     }else{
      digitalWrite(reabastecimiento,LOW);
      }
    if(digitalRead(eplaca)==LOW && var==3){
      tiempo=valoreal-tottal;
      if(tiempo>=0 && tiempo<14){
        tottal=tottal+17;  
      }else if(tiempo>=14 && tiempo<30){
        tottal=tottal+27;  
      }else if(tiempo>=30 && tiempo<45){
        tottal=tottal+37;  
      }else if(tiempo<=0){
        tottal=210;  
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
  
  if(valmotores==dueFlashStorage.read(0)){
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

int recepcionmotor(int a){
    a=a-41;
    
    int y=-0.1948*a*a;
    y=y+13.032*a;
    y=y-77.268;
    
    return y;
  }

