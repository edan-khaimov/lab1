#ifndef FIELDINFO_H
#define FIELDINFO_H
#include <stddef.h>

typedef struct
{
    size_t elemSize;
    void (*ZeroElem)(void *elem);
    void (*Sum)(void *result, void *firstElem, void *secondElem);
    void (*Mul)(void *result, void *firstElem, void *secondElem);
    void (*Print)(void *elem);
} FieldInfo;
#endif
