#include <stdlib.h>
#include <assert.h>
#include "testIntMatrixOperations.h"
#include "matrix.h"
#include "int.h"

void testIntMatrixSum()
{
    FieldInfo *IntField = INT_INFO();
    int elem1[] = {12, 54, 32, 46};
    int elem2[] = {33, 22, 0, 48};
    Matrix *Mat1 = createMatrix(2, 2, IntField, elem1);
    Matrix *Mat2 = createMatrix(2, 2, IntField, elem2);
    Matrix *res = sumMat(Mat1, Mat2);
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            assert(*((int *)(res->elems) + i * 2 + j) == (elem1[i * 2 + j] + elem2[i * 2 + j]));
        }
    }
    freeMatrix(Mat1);
    freeMatrix(Mat2);
    freeMatrix(res);
    free(IntField);
}

void testIntMatrixMul()
{
    FieldInfo *IntField = INT_INFO();
    int elem1[] = {1, 42, 111111, 16};
    int elem2[] = {22, 0, 0, 38};
    Matrix *Mat1 = createMatrix(2, 2, IntField, elem1);
    Matrix *Mat2 = createMatrix(2, 2, IntField, elem2);
    Matrix *res = mulMat(Mat1, Mat2);
    assert(*((int *)(res->elems)) == (elem1[0] * elem2[0] + elem1[1] * elem2[2]));
    assert(*((int *)(res->elems) + 1) == (elem1[0] * elem2[1] + elem1[1] * elem2[3]));
    assert(*((int *)(res->elems) + 2) == (elem1[2] * elem2[0] + elem1[3] * elem2[2]));
    assert(*((int *)(res->elems) + 3) == (elem1[2] * elem2[1] + elem1[3] * elem2[3]));
    freeMatrix(Mat1);
    freeMatrix(Mat2);
    freeMatrix(res);
    free(IntField);
}

void testIntMatrixTranspose()
{
    FieldInfo *IntField = INT_INFO();
    int elem[] = {1, 2, 3, 32, 14, 18};
    Matrix *Mat = createMatrix(3, 2, IntField, elem);
    Matrix *res = transposeMat(Mat);
    assert(*((int *)(res->elems)) == elem[0]);
    assert(*((int *)(res->elems) + 1) == elem[2]);
    assert(*((int *)(res->elems) + 2) == elem[4]);
    assert(*((int *)(res->elems) + 3) == elem[1]);
    assert(*((int *)(res->elems) + 4) == elem[3]);
    assert(*((int *)(res->elems) + 5) == elem[5]);
    freeMatrix(Mat);
    freeMatrix(res);
    free(IntField);
}