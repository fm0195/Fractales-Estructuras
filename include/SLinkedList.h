#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "SNode.h"

using namespace std;

template <typename E>

class SLinkedList
{
private:
    SNode<E> *head;
    SNode<E> *tail;
    SNode<E> *current;
    int size;

    SNode<E>* searchPrevious(SNode<E>* pNode){
        if(current==head)
        {
            return NULL;
        }
        SNode<E>* result=head;
        while(result->next != pNode && result!=NULL)
        {
            result=result->next;
        }
        return  result;
    }
public:
    SLinkedList(){
        head=tail=current=new SNode<E>();
        size=0;
    }

        ~SLinkedList(){
            clear();
            delete head;
        }

    void insert(E pElement){
        current->next=new SNode<E>(pElement, current->next);
        if (current==tail)
        {
            tail=tail->next;
        }
        size++;
    }

    void append(E pElement)
    {
        tail->next=new SNode<E>(pElement);
        tail=tail->next;
        size++;
    }

    E remove() throw(runtime_error)
    {
        if(size==0)
        {
            throw runtime_error("Empty list");
        }
        if(current->next==NULL)
        {
            throw runtime_error("No element to remove");
        }
        E result=current->next->element;
        SNode<E>* temp=current->next;
        current->next=current->next->next;
        if(tail==temp)
        {
            tail=current;
        }
        delete temp;
        size--;
        return result;
    }

    void clear()
    {
        current=head;
        while(head!=NULL)
        {
            head=head->next;
            delete current;
            current=head;
        }
        head=current=tail=new SNode<E>();
        size=0;
    }

    E getElement()throw(runtime_error)
    {
        if (current->next == NULL)
        {
            throw runtime_error("No element to get");
        }
        return current->next->element;
    }

    void goToStart()
    {
        current=head;
    }

    void goToEnd()
    {
        current=tail;
    }

    void goToPos(int pos) throw (runtime_error)
    {
        if(pos<0 || pos>=size)
        {
            throw runtime_error("Index out of bounds");
        }
        current=head;
        for (int i = 0; i < pos; i++)
        {
            current = current->next;
        }
    }

    void previous()
    {
        if (current!=head)
        {
            current=searchPrevious(current);
        }
    }

    void next()
    {
        if (current!=tail)
        {
            current=current->next;
        }
    }

    int getPos()
    {
        int pos = 0;
        SNode<E>* temp = head;
        while (temp != current)
        {
            pos++;
            temp = temp->next;
        }
        return pos;
    }

    int getSize()
    {
        return size;
    }

    void printList(){
        if(size==0){
            cout<<endl<<"No elements to print"<<endl;
        }
        else{
            SNode<E>* t=head->next;
            while(t != NULL){
                cout<<t->element.getDireccion()<<"|";
                t=t->next;
            }
            cout<<endl;
        }
    }


};
#endif

