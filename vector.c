#include "vector.h"

vector createVector() // sukuria vektoriu
{
    vector start = (vector)malloc(sizeof(struct Vector));
    if (start == NULL)
        return NULL;

    start->first = NULL;
    return start;
}

node createNode() // sukuria node
{
    node emptyElement = (node)malloc(sizeof(struct Node));
    if(emptyElement == NULL)
        return NULL;

    emptyElement->data = 0;
    emptyElement->next = NULL;
    return emptyElement;
}

int emptyVector(vector v) //patikrina, ar tuscias
{
    if(v->first == NULL){
        return 1;
    }
    return 0;
}

int insertLast(vector *v, info input) //ideda i galine vieta
{
    int number = sizeOfList(*v)+1;
    return newElement(v, number, input);
}

int clearVector(vector *v) //isvalyti vektoriu
{
    int number = sizeOfList(*v);
    for(int i = 0; i < number; ++i)
    {
        if (deleteElement(v, 1) == 1)
            return 1;
    }
    return 0;
}

int newElement(vector *v, int number, info data) //iterpia reiksme i pasirinkta pozicija
{
    node current = (*v)->first;
    node previous;
    for(int i = 1; i < number; ++i)
    {
        if(current == NULL)
        {
            return 1;
        }
        previous = current;
        current = current->next;
    }
    node newElement = createNode();
    if(newElement == NULL)
        return 1;
        newElement->data = data;
    if(number == 1)
    {
        if((*v)->first != NULL)
            newElement->next = current;
        else
            newElement->next = NULL;
        (*v)->first = newElement;
    }
    else
    {
        previous->next = newElement;
        newElement->next = current;
    }
    return 0;
}

int changeElementValue (vector *v, int number, info data) //pakeicia elemento reiksme
{
    node current = (*v)->first;
    node previous;
    for(int i = 1; i < number; ++i)
    {
        if(current == NULL)
        {
            return 1;
        }
        previous = current;
        current = current->next;
    }
    current->data = data;
    return 0;
}

int deleteElement(vector *v, int number) //isimti elementà
{
    node current = (*v)->first;
    node previous;
    for(int i = 1; i < number; ++i)
    {
        if(current == NULL)
        {
            return 1;
        }
        previous = current;
        current = current->next;
    }
    if(number == 1)
        (*v)->first = current->next;
    else
        previous->next = current->next;
    free(current);
    return 0;
}

int sizeOfList(vector v) //pateikia vektoriaus dydi
{
    if(emptyVector(v) == 1)
        return 0;
    else
    {
        int counter = 0;
        node holder = v->first;
        while(holder != NULL)
        {
            ++counter;
            holder = holder->next;
        }
        return counter;
    }
}

info findValue(vector v, int number) //elemento reiksme
{
    if(emptyVector(v) == 1)
        return -1;
    node current = v->first;
    for(int i = 1; i < number; ++i)
        current = current->next;
    return current->data;
}

void printVector (vector *v) //atspauzdina vektoriaus elementus
{
    if (emptyVector(*v) == 1)
        return;
    node current = (*v)->first;
    node next;

    while (current->next != NULL)
    {
        printf("%d \n", current->data);
        current = current->next;
        next = current->next;
    }
    printf("%d \n", current->data);
}
