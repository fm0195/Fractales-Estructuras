#ifndef FRACTALES_H
#define FRACTALES_H
#include <SLinkedList.h>
#include <Trazos.h>
#include <cstdlib>
#include <iostream>

using namespace std;

class Fractales
{
    public:
        SLinkedList<Trazo>* generarDragon(int cantIteraciones){
            SLinkedList<Trazo>* lista = new SLinkedList<Trazo>();
            lista->insert(Trazo('d', 90));
            lista->insert(Trazo('d', 90));
            lista->append(Trazo('i', 90));
            int i=0;
            while(i < cantIteraciones){
                lista->goToStart();
                int j=0;
                int k=lista->getSize()*2+1;
                while(lista->getSize()<k){
                    lista->insert(Trazo('d', 90));
                    lista->next();lista->next();
                    lista->insert(Trazo('i', 90));
                    lista->next();lista->next();
                    j++;
                }
            i++;
            }
            return lista;
        }

        SLinkedList<Trazo>* generarSierpinski(int cantIteraciones){
            SLinkedList<Trazo>* lista = new SLinkedList<Trazo>();
            lista->insert(Trazo('d', 60));
            lista->insert(Trazo('d', 60));
            int i=0;
            while(i < cantIteraciones){
                lista->goToStart();
                int j=0;
                int k=lista->getSize()*3 + 2;

                if(lista->getElement().getDireccion()=='d'){
                    while(lista->getSize() < k){
                    lista->insert(Trazo('i', 60));
                    lista->insert(Trazo('i',60));

                    if(lista->getSize() == k){
                        break;
                    }

                    lista->next(); lista->next(); lista->next();
                    lista->insert(Trazo('d', 60));
                    lista->insert(Trazo('d', 60));

                    lista->next(); lista->next(); lista->next();
                    j++;
                    }
                }
                else{
                    while(lista->getSize() < k){
                    lista->insert(Trazo('d', 60));
                    lista->insert(Trazo('d',60));

                    if(lista->getSize() == k){
                        break;
                    }

                    lista->next(); lista->next(); lista->next();
                    lista->insert(Trazo('i', 60));
                    lista->insert(Trazo('i', 60));

                    lista->next(); lista->next(); lista->next();
                    j++;
                    }
                }


            i++;
            }
            return lista;
        }

        SLinkedList<Trazo>* generarCurva(int cantIteraciones){
            SLinkedList<Trazo>* lista = new SLinkedList<Trazo>();
            lista->insert(Trazo('a', 45));
            int i=0;
            while(i < cantIteraciones){
                lista->goToStart();
                while(lista->getPos() < lista->getSize()){
                    if(lista->getElement().getDireccion()=='a'){
                        lista->remove();
                        lista->insert(Trazo('d', 45));
                        lista->insert(Trazo('a', 45));
                        lista->insert(Trazo('i', 45));
                        lista->insert(Trazo('i', 45));
                        lista->insert(Trazo('a', 45));
                        lista->insert(Trazo('d', 45));
                        lista->goToPos(lista->getPos()+5);
                    }
                    else lista->next();
                }
            i++;
        }
        //lista->printList();
        return lista;
        }
};

#endif // FRACTALES_H

