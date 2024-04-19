#include "tests.h"
#include "testComplexMatrixOperations.h"
#include "testComplexOperations.h"
#include "testIntMatrixOperations.h"
#include "testIntOperations.h"

void testIntMatrix()
{
    testIntSum();
    testIntMul();
    testIntMatrixSum();
    testIntMatrixMul();
    testIntMatrixTranspose();
}

void testComplexMatrix()
{
    testComplexSum();
    testComplexMul();
    testComplexMatrixSum();
    testComplexMatrixMul();
    testComplexMatrixTranspose();
}