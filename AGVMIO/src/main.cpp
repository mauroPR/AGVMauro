#include <Arduino.h>
#include <AGV.h>

int pInOut[] = 
{
    37, 35, 5,  //in11,in21,enA1 (Motor delantero derecho)
    33, 31, 11, //in31,in41,enB1 (Motor trasero derecho)
    23, 25, 13, //in12,in22,enA2 (Motor delantero izquierdo)
    27, 29, 12, //in32,in42,enB2 (Motor trasero izquierdo)
    10,         //pin servo direccion delantera
    3,          //pin servo direccion trasera
    4, 48, 46,  //SV8-1,SV7-3,SV7-2 (pinServo,Eco,Trigger delanteros)
    2, 44, 42,   //SV15-1,SV17-3,SV17-2(pinServo,Eco,Trigger traseros)
    A0, A1, A2, A3, A4 //SV10-5, SV10-4, SV10-3, SV10-2, SV10-1 
};

AGV *agvMauro;

void setup() 
{
   agvMauro = new AGV(pInOut);
}

void loop() 
{
    agvMauro->avanza();
    /*delay(5000);
    agvMauro->giraDerecha();
    delay(500);
    agvMauro->giraIzquierda();
    delay(500);
    agvMauro->recto();
    delay(100);//Pequeño delay para que le de tiempo a los servos a llegar a 90 antes de que salte a la siguiente orden
    agvMauro->retrocede();
    delay(5000);
    agvMauro->para();
    delay(1000);
    //exit(-1);*/
}