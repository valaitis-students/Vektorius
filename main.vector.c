#include "vector.h"

int main ()
{
    vector v;
    v = createVector(); //testuoje createVector funkcija

    printf("%d\n\n",emptyVector(v)); //testuoje emptyVector funkcija

    info x = 5;
    int y = newElement(&v, 1, x); //testuoje createNode ir newNode funkcijas

    y = insertLast(&v, 6); //testuoja insertLast, sizeOfList ir newNode funkcija
    y = insertLast(&v, 7);
    printVector(&v);
    printf("\n");

    y = changeElementValue(&v, 2, 3); //testuoja changeNodeValue funkcija
    printVector(&v);

    printf("\nSize is %d\n",sizeOfList(v)); //testuoja sizeOfList funkcija

    printf("\nThird element is %d\n\n", findValue(v, 3)); //patekia elemento reiksme

    y = deleteElement(&v, 2); // isimti elementà
    printVector(&v);

    y = clearVector(&v); // istirna vektoriaus visus elemntus
    printf("\n%d\n",emptyVector(v)); //testuoje emptyVector funkcija

    return 0;
}
