#ifndef INT_H
#define INT_H
#include "fieldinfo.h"

void intZero(void *elem);

void intSum(void *res, void *firstElement, void *secondElement);

void intMul(void *res, void *firstElement, void *secondElement);

void intPrint(void *elem);

FieldInfo *INT_INFO();

#endif
