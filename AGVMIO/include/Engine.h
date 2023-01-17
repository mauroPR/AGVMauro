#ifndef Engine_h
#define Engine_h

#include <Arduino.h>

class Engine //Clase Motor
{
    public: //Métodos de la clase
        Engine(int pinX, int pinY, int pinVel); //Constructor de la clase
        void ahead(byte vel);
        void back(byte vel);
        void stop();

    private: //Atributos de la clase
        int _pinX;
        int _pinY;
        int _pinVel; //pin de control velocidad  
};

#endif