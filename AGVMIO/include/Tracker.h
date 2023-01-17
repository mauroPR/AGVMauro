#ifndef Tracker_h
#define Tracker_h

#include <Arduino.h>

class Tracker //Clase seguidor
{
    public: //Metodos de la clase
        Tracker(int IR1, int IR2, int IR3, int IR4, int IR5); //Constructor de la clase
        void readSensor();
        int correction();

    private: //Atributos de la clase

        int _IR1; //variable de cada sensor
        int _IR2;
        int _IR3;
        int _IR4; 
        int _IR5;
        int _sensor[5]; //vector para guardar las lecturas de los sensores
        int _errorP; //variable para guardar el error proporcional
        int _errorI = 0; //variable para guardar el error acumulado (error integral) que suma errores por cada paso por el bucle. Debe empezar en 0.
        int _errorD; //variable para comparar el error en cada ciclo con el anterior y saber si está aumentando o no.(error diferencial)
        int _lastError; //variable para guardar el error del ciclo anterior.
        int _calCorrection; //variable para almacenar el resultado
        const int _kp = 1; //Ganancia proporcional          (P)
        const int _ki = 1; //Error acumulativo en el tiempo (I)
        const int _kd = 1; //Tasa de cambio del error       (D)
};

#endif