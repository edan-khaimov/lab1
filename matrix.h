#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>
#include "fieldinfo.h"

typedef struct
{
    size_t rows;
    size_t columns;
    void *elems;
    FieldInfo *typeInfo;
} Matrix;

int isSizeEqual(Matrix *firstMat, Matrix *secondMat);

int areMatricesMul(Matrix *firstMat, Matrix *secondMat);

int isTypeEqual(Matrix *firstMat, Matrix *secondMat);

void freeMatrix(Matrix *mat);

Matrix *createMatrix(size_t rows, size_t columns, FieldInfo *typeInfo, void *data);

Matrix *createZeroMatrix(size_t rows, size_t columns, FieldInfo *typeInfo);

void setToMatrix(Matrix *mat, size_t i, size_t j, void *scan);

Matrix *sumMat(Matrix *firstMat, Matrix *secondMat);

Matrix *mulMat(Matrix *firstMat, Matrix *secondMat);

Matrix *transposeMat(Matrix *mat);

#endif
