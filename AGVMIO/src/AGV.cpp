#include <AGV.h>
#include <Servo.h>
#include <Direction.h>
#include <Sonar.h>
#include <Tracker.h>

AGV::AGV(int pInOut[]) //Constructor de la clase AGV
{
    _vel = 2; //velocidad del AGV

    _engineFR = new Engine(pInOut[0], pInOut[1], pInOut[2]);
    _engineFL = new Engine(pInOut[3], pInOut[4], pInOut[5]);
    _engineRR = new Engine(pInOut[6], pInOut[7], pInOut[8]);
    _engineRL = new Engine(pInOut[9], pInOut[10], pInOut[11]);

    _directionF = new Direction(pInOut[12]);
    _directionR = new Direction(pInOut[13]);
    
    _sonarF = new Sonar(pInOut[14], pInOut[15], pInOut[16]);
    _sonarR = new Sonar(pInOut[17], pInOut[18], pInOut[19]);

    _trackerF = new Tracker(pInOut[20], pInOut[21], pInOut[22], pInOut[23], pInOut[24]);
}

void AGV::avanza()
{
    if (_sonarF->freeF())
    {
    _engineFR->ahead(_vel);
    _engineFL->ahead(_vel);
    _engineRR->ahead(_vel);
    _engineRL->ahead(_vel);
    }
    else
    {
    _engineFR->stop();
    _engineFL->stop();
    _engineRR->stop();
    _engineRL->stop();
    }
}

void AGV::retrocede()
{
    _engineFR->back(_vel);
    _engineFL->back(_vel);
    _engineRR->back(_vel);
    _engineRL->back(_vel);
}

void AGV::para()
{
    _engineFR->stop();
    _engineFL->stop();
    _engineRR->stop();
    _engineRL->stop();
}

void AGV::giraDerecha()
{
    int _angle = 135;
    _directionF->turnR(_angle);
    _directionR->turnR(_angle);
}

void AGV::giraIzquierda()
{
   int _angle = 45;
    _directionF->turnL(_angle);
    _directionR->turnL(_angle);
}

void AGV::recto()
{
    _directionF->goS(posIn);
    _directionR->goS(posIn);

}

void AGV::siguelineas()
{
    this->avanza();
    _trackerF->readSensor();
    _trackerF->correction();
}