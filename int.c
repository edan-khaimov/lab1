#include <stdio.h>
#include <stdlib.h>
#include "int.h"
#include "fieldinfo.h"

void intZero(void *elem)
{
    *(int *)elem = 0;
}

void intSum(void *res, void *firstElement, void *secondElement)
{
    *(int *)res = *(int *)firstElement + *(int *)secondElement;
}

void intMul(void *res, void *firstElement, void *secondElement)
{
    *(int *)res = *(int *)firstElement * *(int *)secondElement;
}

void intPrint(void *elem)
{
    printf("%d ", *(int *)elem);
}

FieldInfo *INT_INFO()
{
    FieldInfo* IntInfo = NULL;
    IntInfo = (FieldInfo *)malloc(sizeof(FieldInfo));
    if (IntInfo == NULL)
    {
        return NULL;
    }
    IntInfo->elemSize = sizeof(int);
    IntInfo->ZeroElem = &intZero;
    IntInfo->Sum = &intSum;
    IntInfo->Mul = &intMul;
    IntInfo->Print = &intPrint;
    return IntInfo;
}