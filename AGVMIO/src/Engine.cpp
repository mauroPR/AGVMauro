#include <Engine.h>
#include <Servo.h>

Engine::Engine(int pinX, int pinY, int pinVel)//Constructor de la clase, sirve para inicializar los atributos
{
    _pinX = pinX;
    _pinY = pinY;
    _pinVel = pinVel;

    pinMode(_pinX, OUTPUT);
    pinMode(_pinY, OUTPUT);
    pinMode(_pinVel, OUTPUT);
}

void Engine::ahead(byte vel)
{
    digitalWrite(_pinX,HIGH);
    digitalWrite(_pinY,LOW);
    digitalWrite(_pinVel,vel);
}

void Engine::back(byte vel)
{
    digitalWrite(_pinX,LOW);
    digitalWrite(_pinY,HIGH);
    digitalWrite(_pinVel,vel);
}

void Engine::stop()
{
    digitalWrite(_pinX,LOW);
    digitalWrite(_pinY,LOW);
    digitalWrite(_pinVel,0);
}