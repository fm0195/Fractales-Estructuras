#ifndef TRAZO_H
#define TRAZO_H
#include <string>
#include <iostream>

using namespace std;

class Trazo
{
    private:
        char direccion;
        int angulo;
        bool avanzar;
    public:
        Trazo(char pDireccion, int pAngulo, bool pAvanzar=true){
            direccion=pDireccion;
            angulo=pAngulo;
            avanzar=pAvanzar;
        }
        Trazo(){
        }

        //set y gets de las dirrecciones
        char getDireccion (){
            return direccion;
        }
        void setDireccion (char pDireccion){
            direccion=pDireccion;
        }

        int getAngulo (){
            return angulo;
        }
        void setAngulo (int pAngulo){
            angulo=pAngulo;
        }

        bool getAvanzar (){
            return avanzar;
        }
        void setAvanzar (bool pAvanzar){
            avanzar=pAvanzar;
        }


};

#endif // TRAZO_H
