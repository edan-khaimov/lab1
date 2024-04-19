#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "matrix.h"

int isSizeEqual(Matrix *firstMat, Matrix *secondMat)
{
    return (firstMat->rows == secondMat->rows && firstMat->columns == secondMat->columns);
}

int areMatricesMul(Matrix *firstMat, Matrix *secondMat)
{
    return (firstMat->columns == secondMat->rows);
}

int isTypeEqual(Matrix *firstMat, Matrix *secondMat)
{
    if (firstMat == NULL || secondMat == NULL) {
        return 0;
    }
    return (firstMat->typeInfo == secondMat->typeInfo);
}

void freeMatrix(Matrix *mat)
{
    if (mat != NULL)
    {
        free(mat->elems);
        mat->rows = 0;
        mat->columns = 0;
        free(mat);
    }
    else
    {
        printf("Already free pointer\n");
    }
}

Matrix *createMatrix(size_t rows, size_t columns, FieldInfo *typeInfo, void *data)
{
    Matrix *mat = (Matrix *)malloc(sizeof(Matrix));
    if (mat == NULL)
    {
        fprintf(stderr, "Problems with memory\n");
        exit(1);
    }
    mat->columns = columns;
    mat->rows = rows;
    mat->typeInfo = typeInfo;
    size_t elemSize = typeInfo->elemSize;
    mat->elems = malloc(rows * columns * mat->typeInfo->elemSize);
    if (mat->elems == NULL)
    {
        fprintf(stderr, "Error. Problems with memory\n");
        exit(1);
    }
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            memcpy((char *)mat->elems + i * columns * elemSize + j * elemSize, (char *)data + i * columns * elemSize + j * elemSize, elemSize);
        }
    }
    return mat;
}


void setToMatrix(Matrix *mat, size_t i, size_t j, void *scan)
{
    size_t elemSize = mat->typeInfo->elemSize;
    memcpy((char *)mat->elems + i * mat->columns * elemSize + j * elemSize, scan, elemSize);
}

Matrix *sumMat(Matrix *firstMat, Matrix *secondMat)
{
    if (isSizeEqual(firstMat, secondMat) && isTypeEqual(firstMat, secondMat))
    {
        size_t rows = firstMat->rows;
        size_t columns = firstMat->columns;
        size_t elemSize = firstMat->typeInfo->elemSize;
        Matrix *resMat = createZeroMatrix(rows, columns, firstMat->typeInfo);
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                void *resElem = resMat->elems + i * columns * elemSize + j * elemSize;
                void *firstElem = firstMat->elems + i * columns * elemSize + j * elemSize;
                void *secondElem = secondMat->elems + i * columns * elemSize + j * elemSize;
                resMat->typeInfo->Sum(resElem, firstElem, secondElem);
            }
        }
        return resMat;
    }
    else if (!isSizeEqual(firstMat, secondMat))
    {
        fprintf(stderr, "Error. The number of rows and columns must be equal!\n");
        exit(1);
    }
    else if (!isTypeEqual(firstMat, secondMat))
    {
        fprintf(stderr, "Error. Types of elements must be equal!\n");
        exit(1);
    }
    fprintf(stderr, "Unknown error");
    exit(1);
}

Matrix *mulMat(Matrix *firstMat, Matrix *secondMat)
{
    if (areMatricesMul(firstMat, secondMat) && isTypeEqual(firstMat, secondMat))
    {
        size_t rows = firstMat->rows;
        size_t columns = secondMat->columns;
        size_t elemSize = firstMat->typeInfo->elemSize;
        void *intermediateRes = malloc(elemSize);
        Matrix *resMat = createZeroMatrix(rows, columns, firstMat->typeInfo);
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < columns; j++)
            {
                for (size_t l = 0; l < firstMat->columns; l++)
                {
                    void *resElem = resMat->elems + i * columns * elemSize + j * elemSize;
                    void *firstElem = firstMat->elems + i * firstMat->columns * elemSize + l * elemSize;
                    void *secondElem = secondMat->elems + l * columns * elemSize + j * elemSize;
                    resMat->typeInfo->Mul(intermediateRes, firstElem, secondElem);
                    resMat->typeInfo->Sum(resElem, resElem, intermediateRes);
                }
            }
        }
        free(intermediateRes);
        return resMat;
    }
    else if (!areMatricesMul(firstMat, secondMat))
    {
        fprintf(stderr, "Error. Number of columns in the first Matrix must be equal to the number of rows in the second Matrix\n");
        exit(1);
    }
    else if (!isTypeEqual(firstMat, secondMat))
    {
        fprintf(stderr, "Error. Types of elements must be equal!\n");
        exit(1);
    }
    fprintf(stderr, "Unknown error");
    exit(1);
}

Matrix *transposeMat(Matrix *mat)
{
    size_t columns = mat->rows;
    size_t rows = mat->columns;
    size_t elemSize = mat->typeInfo->elemSize;
    Matrix *transMat = createZeroMatrix(rows, columns, mat->typeInfo);
    for (size_t i = 0; i < mat->columns; i++)
    {
        for (size_t j = 0; j < mat->rows; j++)
        {
            void *transElem = (char *)mat->elems + j * rows * elemSize + i * elemSize;
            setToMatrix(transMat, i, j, transElem);
        }
    }
    return transMat;
}

Matrix *createZeroMatrix(size_t rows, size_t columns, FieldInfo *typeInfo)
{
    void *zero = malloc(typeInfo->elemSize);
    typeInfo->ZeroElem(zero);
    void *data = malloc(rows * columns * typeInfo->elemSize);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            memcpy((char *)data + i * columns * typeInfo->elemSize + j * typeInfo->elemSize, zero, typeInfo->elemSize);
        }
    }
    Matrix *res = createMatrix(rows, columns, typeInfo, data);
    free(zero);
    return res;
}
