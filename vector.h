#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned int info;
typedef struct Node
{
    info data;
    struct Node *next;
} *node;

typedef struct Vector
{
    struct Node *first;
} *vector;

vector createVector(); // sukuria vektoriu
//Jei nepavyksta isskirti atminties, grazinamas NULL

int emptyVector(vector v); //patikrina, ar tuscias
//Jei vektorius tuscias, grazina 1, jei ne, grazina 0

int insertLast(vector *v, info input); // iterpti i gala
//Jei viskas geri, grazina 0, kitu atveju 1

int clearVector(vector *v); //isvalo vektoriu
//Jei viskas geri, grazina 0, kitu atveju 1

int newElement(vector *v, int number, info data); //iterpia reiksme i pasirinkta pozicija
//Jei viskas geri, grazina 0, kitu atveju 1

int changeElementValue(vector *v, int number, info data); //pakeicia elemento reiksme
//Jei viskas geri, grazina 0, kitu atveju 1

int deleteElement(vector *v, int number); //isimti elementà
//Jei viskas geri, grazina 0, kitu atveju 1

int sizeOfList(vector v); //pateikia vektoriaus dydi
//Jei vektorius tuscias, grazina 0, kitu atveju grazina elementu skaiciu

info findValue(vector v, int number); //elemento reiksme
//Jei viskas gerai, pateikiamas elementas, jei ne, pateikiama -1 reiksme

void printVector (vector *v); //pateiki vektoriaus elementus

#endif // VECTOR_H_INCLUDED
