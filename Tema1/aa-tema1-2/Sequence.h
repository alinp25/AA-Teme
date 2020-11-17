#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <stdlib.h>
#include <stdio.h>

typedef int Type;
typedef struct sequence {
    Type data;
    struct sequence *left;
    struct sequence *right;
    int height;
} *Sequence;

/**
 * Returneaza structura vida
 * */
Sequence init();

/**
 * Insereaza un element în structura pe pozitia index*
 * */
Sequence insert(Sequence v, Type item, int index);

/**
 * Sterge elementul de pe pozitia index din structura
 * */
Sequence removeItem(Sequence v, int index);

/**
 * Returneaza valoarea elementului de pe pozitia index
 * */
Type lookup(Sequence v, int index);

/**
 * Înlocuieste valoarea elementului de pe pozitia index
 * */
Sequence set(Sequence v, Type item, int index);

/**
 * Returneaza dimensiunea structurii
 * */
int size(Sequence v);

/**
 * Returneaza cele doua structuri rezultate în urma divizarii (rezultatul este retiinut într-un Sequence* cu 2 elemente)
 * */

Sequence split(Sequence v,int index);

/**
 * Returneaza structura rezultata dupa concatenare
 * */
Sequence concat(Sequence struct1, Sequence struct2);

Sequence displaySequence(Sequence v);

#endif