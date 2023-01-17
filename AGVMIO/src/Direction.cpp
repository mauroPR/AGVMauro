#include <Direction.h>

Direction::Direction(int pinServo) //Constructor de la clase
{
    pinMode(pinServo,OUTPUT);

    _servo = new Servo();
    _servo->attach(pinServo);
    _servo->write(posIn);

}

void Direction::turnR(int angle)
{
    _servo->write(angle);
}

void Direction::turnL(int angle)
{
    _servo->write(angle);
}

void Direction::goS(int posIn)//funcion para que vaya recto
{
    _servo->write(posIn);
}