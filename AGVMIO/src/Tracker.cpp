#include <Tracker.h>

Tracker::Tracker(int IR1, int IR2, int IR3, int IR4, int IR5)
{
    _IR1 = IR1;
    _IR2 = IR2;
    _IR3 = IR3;
    _IR4 = IR4;
    _IR5 = IR5;
}

void Tracker::readSensor()//metodo que lee cada sensor y lo guarda en el vector sensor[]
{
    _sensor[0] = analogRead(_IR1);
    _sensor[1] = analogRead(_IR2);
    _sensor[2] = analogRead(_IR3);
    _sensor[3] = analogRead(_IR4);
    _sensor[4] = analogRead(_IR5);
}

int Tracker::correction()
{
    _errorP = -2*_sensor[0] - 1*_sensor[1] - 0*_sensor[2] - 1 *_sensor[3] - 2*_sensor[4];
    _errorI = _errorI + _errorP;
    _errorD = _lastError - _errorP;
    _lastError = _errorP;
    _calCorrection = _errorP*_kp + _errorI*_ki + _errorD*_kd;
    return _calCorrection;
}