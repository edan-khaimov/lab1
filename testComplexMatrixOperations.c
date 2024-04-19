#include <stdlib.h>
#include <assert.h>
#include "testComplexMatrixOperations.h"
#include "complex.h"
#include "matrix.h"

void testComplexMatrixSum()
{
    FieldInfo *ComplexField = COMPLEX_INFO();
    Complex elem1[] = {{12, 21}, {54, 45}, {32, 23}, {46, 64}};
    Complex elem2[] = {{33, 33}, {22, 22}, {0, 0}, {48, 84}};
    Matrix *Mat1 = createMatrix(2, 2, ComplexField, elem1);
    Matrix *Mat2 = createMatrix(2, 2, ComplexField, elem2);
    Matrix *res = sumMat(Mat1, Mat2);
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            assert(((Complex *)(res->elems) + i * 2 + j)->Real == (elem1[i * 2 + j].Real + elem2[i * 2 + j].Real));
            assert(((Complex *)(res->elems) + i * 2 + j)->Im == (elem1[i * 2 + j].Im + elem2[i * 2 + j].Im));
        }
    }
    freeMatrix(Mat1);
    freeMatrix(Mat2);
    freeMatrix(res);
    free(ComplexField);
}

void testComplexMatrixMul()
{
    FieldInfo *ComplexField = COMPLEX_INFO();
    Complex elem1[] = {{1, 4}, {42, 24}, {111111, 0}, {16, 61}};
    Complex elem2[] = {{22, 22}, {0, 7}, {0, 1}, {38, 83}};
    Matrix *Mat1 = createMatrix(2, 2, ComplexField, elem1);
    Matrix *Mat2 = createMatrix(2, 2, ComplexField, elem2);
    Matrix *res = mulMat(Mat1, Mat2);
    Complex ans1, ans2;
    complexMul((void *)&ans1, (void *)&elem1[0], (void *)&elem2[0]);
    complexMul((void *)&ans2, (void *)&elem1[1], (void *)&elem2[2]);
    assert(((Complex *)(res->elems))->Real == (ans1.Real + ans2.Real));
    assert(((Complex *)(res->elems))->Im == (ans1.Im + ans2.Im));
    complexMul((void *)&ans1, (void *)&elem1[0], (void *)&elem2[1]);
    complexMul((void *)&ans2, (void *)&elem1[1], (void *)&elem2[3]);
    assert(((Complex *)(res->elems) + 1)->Real == (ans1.Real + ans2.Real));
    assert(((Complex *)(res->elems) + 1)->Im == (ans1.Im + ans2.Im));
    complexMul((void *)&ans1, (void *)&elem1[2], (void *)&elem2[0]);
    complexMul((void *)&ans2, (void *)&elem1[3], (void *)&elem2[2]);
    assert(((Complex *)(res->elems) + 2)->Real == (ans1.Real + ans2.Real));
    assert(((Complex *)(res->elems) + 2)->Im == (ans1.Im + ans2.Im));
    complexMul((void *)&ans1, (void *)&elem1[2], (void *)&elem2[1]);
    complexMul((void *)&ans2, (void *)&elem1[3], (void *)&elem2[3]);
    assert(((Complex *)(res->elems) + 3)->Real == (ans1.Real + ans2.Real));
    assert(((Complex *)(res->elems) + 3)->Im == (ans1.Im + ans2.Im));
    freeMatrix(Mat1);
    freeMatrix(Mat2);
    freeMatrix(res);
    free(ComplexField);
}

void testComplexMatrixTranspose()
{
    FieldInfo *ComplexField = COMPLEX_INFO();
    Complex elem[] = {{1, 7}, {2, 4}, {0, 12}, {32, 14},
                      {18, 1}, {2, 1}};
    Matrix *Mat = createMatrix(3, 2, ComplexField, elem);
    Matrix *res = transposeMat(Mat);
    assert(((Complex *)(res->elems))->Real == elem[0].Real);
    assert(((Complex *)(res->elems))->Im == elem[0].Im);
    assert(((Complex *)(res->elems) + 1)->Real == elem[2].Real);
    assert(((Complex *)(res->elems) + 1)->Im == elem[2].Im);
    assert(((Complex *)(res->elems) + 2)->Real == elem[4].Real);
    assert(((Complex *)(res->elems) + 2)->Im == elem[4].Im);
    assert(((Complex *)(res->elems) + 3)->Real == elem[1].Real);
    assert(((Complex *)(res->elems) + 3)->Im == elem[1].Im);
    assert(((Complex *)(res->elems) + 4)->Real == elem[3].Real);
    assert(((Complex *)(res->elems) + 4)->Im == elem[3].Im);
    assert(((Complex *)(res->elems) + 5)->Real == elem[5].Real);
    assert(((Complex *)(res->elems) + 5)->Im == elem[5].Im);
}