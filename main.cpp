#include <iostream>
#include <winbgim.h>
#include <Trazos.h>
#include <Fractales.h>
#include <string>
#include <winbgim.h>

using namespace std;

int main()
{
    int tipo, cantidad;
    cout<<"Bienvenido, escoja el fractal a realizar:\n1)Dragon\n2)Sierpinski\n3)Curva"<<endl;
    cout<<"Digite la opcion:"<<endl;
    cin>>tipo;
    cout<<"Digite el numero de iteraciones:"<<endl;
    cin>>cantidad;
    //codigo para el grafico
    Fractales fractal;//variable para generar un fractal
    initwindow (1000,600);
    setcolor(4);
    SLinkedList<Trazo>* lista;
    int x1,y1,x2,y2;//variable
    char dir;//variable para la direccion de la s lineas
    int rumbo;//variable para obtener el rumbo siguiente
    Trazo t;
    if (tipo==1){
        lista= fractal.generarDragon(cantidad);//genera una lista con los elementos de direccion de dragon
        x1=700;
        y1=200;
        x2=701;
        y2=200;
        line(x1,y1,x2,y2);
        rumbo=1;//variable para saber el rumbo segun el entero
        //derecha=1
        //izquierda=2
        //Arriba=3
        //abajo=4
    } else if (tipo==2){
        lista= fractal.generarSierpinski(cantidad);//genera una lista con los elementos de direccion de dragon
        x1=250;
        y1=550;
        x2=252;
        y2=550;
        line(x1,y1,x2,y2);
        rumbo=1;
    }
    else if (tipo==3){
        lista=fractal.generarCurva(cantidad);
        x1=300;
        y1=150;
        x2=301;
        y2=150;
        line(x1,y1,x2,y2);
        rumbo=1;
    }
    lista->goToStart();
    //genreacion de las iteraciones para dibujar en pantalla
    int n = lista->getSize() / 3;//variable para llevar el color
    setcolor(2);//primero el verde
    for (int i=0;i<(lista->getSize());i++){
        if(i<n){//cuando llegue a 1/3 de la iteracion cambia a amarillo
            setcolor(2);
        }
        else if(i>=n && i<2*n){//y cuando llega a 2/3 a rojo
            setcolor(14);
        }
        else setcolor(4);
        t=lista->getElement();
        lista->next();
        dir=t.getDireccion();
        switch(tipo){
            case 1:
                switch(rumbo){
                    case 1:
                        if (dir=='d'){
                            y2=y2+1;
                            rumbo=4;
                        }else if (dir=='i'){
                            y2=y2-1;
                            rumbo=3;
                        }
                        line(x1,y1,x2,y2);
                        x1=x2;
                        y1=y2;
                        break;
                    case 3:
                        if (dir=='d'){
                            x2=x2+1;
                            rumbo=1;
                        }else if (dir=='i'){
                            x2=x2-1;
                            rumbo=2;
                        }
                        line(x1,y1,x2,y2);
                        x1=x2;
                        y1=y2;
                        break;
                    case 2:
                        if (dir=='d'){
                            y2=y2-1;
                            rumbo=3;
                        }else if (dir=='i'){
                            y2=y2+1;
                            rumbo=4;
                        }
                        line(x1,y1,x2,y2);
                        x1=x2;
                        y1=y2;
                        break;
                    case 4:
                        if (dir=='d'){
                            x2=x2-1;
                            rumbo=2;
                        }else if (dir=='i'){
                            x2=x2+1;
                            rumbo=1;
                        }
                        line(x1,y1,x2,y2);
                        x1=x2;
                        y1=y2;
                        break;
                }
                break;
            case 2:
                switch(rumbo){
                    case 1:
                        if (dir=='d'){
                            x2=x1+1;
                            y2=y1+2;
                            rumbo=6;
                        }else if (dir=='i'){
                            x2=x1+1;
                            y2=y1-2;
                            rumbo=4;
                        }
                        line(x1,y1,x2,y2);
                        x1=x2;
                        y1=y2;
                        break;
                    case 2:
                        if (dir=='d'){
                            x2=x1-1;
                            y2=y1-2;
                            rumbo=5;
                        }else if (dir=='i'){
                            x2=x1-1;
                            y2=y1+2;
                            rumbo=3;
                        }
                        line(x1,y1,x2,y2);
                        x1=x2;
                        y1=y2;
                        break;
                    case 3:
                        if (dir=='d'){
                            x2=x1-2;
                            rumbo=2;
                        }else if (dir=='i'){
                            x2=x1+1;
                            y2=y1+2;
                            rumbo=6;
                        }
                        line(x1,y1,x2,y2);
                        x1=x2;
                        y1=y2;
                        break;
                    case 4:
                        if (dir=='d'){
                            x2=x1+2;
                            rumbo=1;
                        }else if (dir=='i'){
                            x2=x1-1;
                            y2=y1-2;
                            rumbo=5;
                        }
                        line(x1,y1,x2,y2);
                        x1=x2;
                        y1=y2;
                        break;
                    case 5:
                        if (dir=='d'){
                            x2=x1+1;
                            y2=y1-2;
                            rumbo=4;
                        }else if (dir=='i'){
                            x2=x1-2;
                            rumbo=2;
                        }
                        line(x1,y1,x2,y2);
                        x1=x2;
                        y1=y2;
                        break;
                    case 6:
                        if (dir=='d'){
                            x2=x1-1;
                            y2=y1+2;
                            rumbo=3;
                        }else if (dir=='i'){
                            x2=x1+2;
                            rumbo=1;
                        }
                        line(x1,y1,x2,y2);
                        x1=x2;
                        y1=y2;
                        break;
                }
                break;
            case 3:
                switch(rumbo){
                    case 1:
                        if (dir=='d'){
                            rumbo=6;
                        }else if (dir=='i'){
                            rumbo=4;
                        }else if(dir=='a'){
                            x2=x1+3;
                            line(x1,y1,x2,y2);
                        }
                        x1=x2;
                        y1=y2;
                        break;
                    case 2:
                        if (dir=='d'){
                            rumbo=5;
                        }else if (dir=='i'){
                            rumbo=3;
                        } else if(dir=='a'){
                            x2=x1-3;
                            line(x1,y1,x2,y2);
                        }
                        x1=x2;
                        y1=y2;
                        break;
                    case 3:
                        if (dir=='d'){
                            rumbo=2;
                        }else if (dir=='i'){
                            rumbo=8;
                        }else if(dir=='a'){
                            x2=x1-3;
                            y2=y1+3;
                            line(x1,y1,x2,y2);
                        }
                        x1=x2;
                        y1=y2;
                        break;
                    case 4:
                        if (dir=='d'){
                            rumbo=1;
                        }else if (dir=='i'){
                            rumbo=7;
                        }else if(dir=='a'){
                            x2=x1+3;
                            y2=y1-3;
                            line(x1,y1,x2,y2);
                        }
                        x1=x2;
                        y1=y2;
                        break;
                    case 5:
                        if (dir=='d'){
                            rumbo=7;
                        }else if (dir=='i'){
                            rumbo=2;
                        } else if(dir=='a'){
                            x2=x1-3;
                            y2=y1-3;
                            line(x1,y1,x2,y2);
                        }
                        x1=x2;
                        y1=y2;
                        break;
                    case 6:
                        if (dir=='d'){
                            rumbo=8;
                        }else if (dir=='i'){
                            rumbo=1;
                        }else if(dir=='a'){
                            x2=x1+3;
                            y2=y1+3;
                            line(x1,y1,x2,y2);
                        }
                        x1=x2;
                        y1=y2;
                        break;
                    case 7:
                        if (dir=='d'){
                            rumbo=4;
                        }else if (dir=='i'){
                            rumbo=5;
                        }else if(dir=='a'){
                            y2=y1-3;
                            line(x1,y1,x2,y2);
                        }
                        x1=x2;
                        y1=y2;
                        break;
                    case 8:
                        if (dir=='d'){
                            rumbo=3;
                        }else if (dir=='i'){
                            rumbo=6;
                        }else if(dir=='a'){
                            y2=y1+3;
                            line(x1,y1,x2,y2);
                        }
                        x1=x2;
                        y1=y2;
                        break;
                }
                break;

        }
    }
    getch();
    closegraph();
    getch();
    return 0;
}

