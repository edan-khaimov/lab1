#include <stdio.h>
#include <stdlib.h>
#include "complex.h"
#include "fieldinfo.h"

void complexZero(void *elem)
{
    ((Complex *)elem)->Real = 0;
    ((Complex *)elem)->Im = 0;
}

void complexSum(void *res, void *firstElement, void *secondElement)
{
    ((Complex *)res)->Real = ((Complex *)firstElement)->Real + ((Complex *)secondElement)->Real;
    ((Complex *)res)->Im = ((Complex *)firstElement)->Im + ((Complex *)secondElement)->Im;
}

void complexMul(void *res, void *firstElement, void *secondElement)
{
    ((Complex *)res)->Real = ((Complex *)firstElement)->Real * ((Complex *)secondElement)->Real - ((Complex *)firstElement)->Im * ((Complex *)secondElement)->Im;
    ((Complex *)res)->Im = ((Complex *)firstElement)->Real * ((Complex *)secondElement)->Im + ((Complex *)secondElement)->Real * ((Complex *)firstElement)->Im;
}

void complexPrint(void *element)
{
    printf("(%d + %di) ", ((Complex *)element)->Real, ((Complex *)element)->Im);
}

FieldInfo *COMPLEX_INFO()
{
    FieldInfo* ComplexInfo = NULL;
    ComplexInfo = (FieldInfo *)malloc(sizeof(FieldInfo));
    if (ComplexInfo == NULL)
    {
        return ComplexInfo;
    }
    ComplexInfo->elemSize = sizeof(Complex);
    ComplexInfo->ZeroElem = &complexZero;
    ComplexInfo->Sum = &complexSum;
    ComplexInfo->Mul = &complexMul;
    ComplexInfo->Print = &complexPrint;
    return ComplexInfo;
}