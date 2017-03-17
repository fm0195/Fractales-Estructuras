#ifndef SNode_H
#define SNode_H
#include <cstdlib>

using namespace std;

template <typename E>

class SNode{
    public:
        SNode<E> *next;
        E element;

        SNode(E pElement, SNode<E>* pNext=NULL){ //CONSTRUCTOR NORMAL
            next=pNext;
            element=pElement;
        }

        SNode(SNode<E>* pNext=NULL){ //CONSTRUCTOR PARA EL NODO ESPECIAL
            next=pNext;
        }
};
#endif

