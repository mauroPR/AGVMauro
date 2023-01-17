#ifndef Direction_h
#define Direction_h

#include <Arduino.h>
#include <Servo.h>

class Direction //Clase direccion
{
    public: //Metodos de la clase 
        Direction(int pinServo); //constructor de la clase
        void turnR(int angle);
        void turnL(int angle);
        void goS(int posIn); // (go straight)void para que el servo despues de girar vaya recto

    private: //Atributos de la clase
        const int posIn = 90;
        Servo *_servo; //Puntero al objeto servo delantero
        const int posMin = 45;
        const int posMax = 135;
};

#endif
/*Cambiamos la clase Direction y metemos un pinServo solo y luego creamos dos Servos
para controlarlos de la misma manera que los motores*/
