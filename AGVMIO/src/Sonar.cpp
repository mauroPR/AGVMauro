#include <Sonar.h>

Sonar::Sonar( int pinServo,int pinEco, int pinTrig)
{
    _pinEco = pinEco;
    _pinTrig = pinTrig;
    _pinServo = pinServo;

    pinMode(_pinEco,INPUT);
    pinMode(_pinTrig,OUTPUT);
    pinMode(_pinServo,OUTPUT);

    _servo = new Servo();
    _servo->attach(pinServo);
    //_servo->write(posIn);
    _ultra = new SR04(_pinEco, _pinTrig);

}

bool Sonar::freeF()
{
    int _angleR = 135;
    int _angleL = 45;
    int _angle = 90;
    
    bool freeR = false;
    _servo->write(_angleR);
    int distR = _ultra->Distance();
    freeR = distR > 40;
    
    bool freeC = false;
    _servo->write(_angle);
    int distC = _ultra->Distance();
    freeC = distC > 40;
    
    bool freeL = false;
    _servo->write(_angleL);
    int distL = _ultra->Distance();
    freeL = distL > 40;

    return (freeR && freeC && freeL);
}