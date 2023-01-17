#ifndef Sonar_h
#define Sonar_h

#include <Arduino.h>
#include <SR04.h>
#include <Servo.h>

class Sonar //clase Sonar 
{
    public: //Metodos de la clase
        Sonar(int pinServo, int pinEco, int pinTrig); //Constructor de la clase sonar
        bool freeF();
        bool freeR(); //Para la inclusion de un sonar trasero para la marcha atras

    private: //Atributos de la clase
        Servo *_servo;
        SR04 *_ultra; //Ultrasonidos
        int _pinEco;  //pin del pulso (Salida)
        int _pinTrig; //pin del Eco (Entrada)
        int _pinServo; //pin para el servo del sonar para que pueda detectar obstaculos en 45°, 90° y 135°
        //const int posIn = 90;
};
#endif
