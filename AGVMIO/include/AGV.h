#ifndef AGV_h
#define AGV_h

#include <Arduino.h>
#include <Engine.h>
#include <Servo.h>
#include <Direction.h>
#include <Sonar.h>
#include <Tracker.h>

class AGV //Clase AGV
{
    public: //Metodos del AGV
        AGV(int pInOut[]); //Constructor de la clase
        void avanza();
        void retrocede();
        void para();
        void giraDerecha();
        void giraIzquierda();
        void recto();
        void siguelineas();

    private: //Atributos del AGV, que vienen a ser los motores,servos de la direccion y etc
        byte _vel; //variable velocidad de avance del 
        int _angle;//angulo de giro del servo
        const int posIn = 90;

        Engine *_engineFR;//Motor delantero derecho
        Engine *_engineFL;//Motor delantero izquierdo
        Engine *_engineRR;//Motor trasero derecho
        Engine *_engineRL;//Motor trasero izquierdo

        Direction *_directionR;//Direccion derecha 
        Direction *_directionF;//Direccion izquierda

        Sonar *_sonarF;//Sonar delantero
        Sonar *_sonarR;//Sonar trasero
        
        Tracker *_trackerF;//Siguelineas delantero

};

#endif