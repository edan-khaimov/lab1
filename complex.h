#ifndef COMPLEX_H
#define COMPLEX_H
#include "fieldinfo.h"

typedef struct
{
    int Real;
    int Im;
} Complex;

void complexZero(void *elem);

void complexSum(void *res, void *firstElement, void *secondElement);

void complexMul(void *res, void *firstElement, void *secondElement);

void complexPrint(void *element);

FieldInfo *COMPLEX_INFO();
#endif
