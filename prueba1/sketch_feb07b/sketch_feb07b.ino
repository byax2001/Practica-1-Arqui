//importamos librerias
#include <LedControl.h>
#include "letras.h"


//Declaracion de variables
unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;
unsigned long tiempo3 = 0;

//salidas de arduino MEGA 51, 52, 53 video
//DNI, CLK, LOAD
//salidas de arduino UNO 11, 13, 10 video 

//manejo de matriz
int filas[] = {22, 23, 24, 25, 26, 27, 28, 29};
//int columnas[] = {53, 52, 51, 50, 49, 48, 47, 46};
int columnas[] = {46, 47, 48, 49, 50, 51, 52, 53};

int letra[][8]={
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

LedControl lc = LedControl(11,13,10,1); //1 dispositivo

void setup() {
  Serial.begin(9600);
  //inicializamos driver
    lc.shutdown(0, false); //inicia apagado - dispositivo 1
    lc.setIntensity(0, 4);
    lc.clearDisplay(0);
  
  for(int i = 0; i < 8; i++){
      pinMode(filas[i], OUTPUT);
      pinMode(columnas[i], OUTPUT);
    }
    LimpiarMatriz();
    tiempo1 = millis();
}

void loop() {
    tiempo2 = millis();
    tiempo3 = millis();
    
    //probamos la matriz
    for(int fila = 0; fila < 8; fila++){
      digitalWrite(filas[fila], HIGH);
      for(int columna = 0; columna < 8; columna++)
      {
        
        if(tiempo2 > (tiempo1)){
          letra[columna][fila] = P[columna][fila];
        }
       if (tiempo3 > (tiempo1+1000)){
          letra[columna][fila] = R[columna][fila];
          lc.setLed(0, columna, fila, P[fila][columna]);
          delay(1);
          //Serial.println(tiempo3);
        }
        
        if (tiempo3 > (tiempo1+2000)){
          letra[columna][fila] = A[columna][fila];
          lc.setLed(0, columna, fila, R[fila][columna]);
          delay(1);
        }


        if (tiempo3 > (tiempo1+3000)){
          letra[columna][fila] = C[columna][fila];
          lc.setLed(0, columna, fila, A[fila][columna]);
          delay(1);
        }

       
      }
    Encender();
    LimpiarMatriz();
    }
}

void LimpiarMatriz(){
  for(int i = 0; i < 8; i++){
    digitalWrite(filas[i], LOW);
    digitalWrite(columnas[i], HIGH);
  }
}

void Encender(){

 for(int columna = 0; columna < 8; columna++){
      digitalWrite(filas[columna],HIGH);
      for(int fila=0; fila < 8; fila++){
        if(letra[columna][fila] == 1){
          digitalWrite(columnas[fila],LOW);
        }
      }
      delay(1);
      digitalWrite(filas[columna],LOW);
      for(int j = 0; j < 8;j++){
        digitalWrite(columnas[j],HIGH);
      }
    }

 


    
    //delay(2);
    //LimpiarMatriz();

    //}


   








    
}
