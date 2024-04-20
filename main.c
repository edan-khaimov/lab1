#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "fieldinfo.h"
#include "complex.h"
#include "int.h"
#include "matrix.h"
#include "ui.h"
#include "tests.h"

int main()
{
    testIntMatrix();
    testComplexMatrix();
    int userChoice = 0, flag = 1;
    FieldInfo *IntField = INT_INFO();
    if (IntField == NULL)
    {
        fprintf(stderr, "Error. Problem with memory");
        exit(1);
    }
    FieldInfo *ComplexField = COMPLEX_INFO();
    if (ComplexField == NULL)
    {
        fprintf(stderr, "Error. Problem with memory");
        exit(1);
    }
    size_t firstMatRows, firstMatColumns, secondMatRows, secondMatColumns;
    void *firstMatElems, *secondMatElems;
    Matrix *firstMat, *secondMat, *resMat;
    menu();

    while (flag && scanf("%d", &userChoice))
    {
        switch (userChoice)
        {
            case 0:
                flag = 0;
                printf("Program completed\n");
                break;
            case 1:
                printf("Create the first Matrix\n");
                setRows(&firstMatRows);
                setColumns(&firstMatColumns);
                enterIntElements((int **) &firstMatElems, firstMatRows, firstMatColumns);
                firstMat = createMatrix(firstMatRows, firstMatColumns, IntField, firstMatElems);
                printf("Create the second Matrix\n");
                setRows(&secondMatRows);
                setColumns(&secondMatColumns);
                enterIntElements((int **) &secondMatElems, secondMatRows, secondMatColumns);
                secondMat = createMatrix(secondMatRows, secondMatColumns, IntField, secondMatElems);
                resMat = sumMat(firstMat, secondMat);
                printf("Result of sum: \n");
                printMatrix(resMat);
                free(firstMat);
                free(secondMat);
                free(resMat);
                free(firstMatElems);
                free(secondMatElems);
                break;
            case 2:
                printf("Create the first Matrix\n");
                setRows(&firstMatRows);
                setColumns(&firstMatColumns);
                enterComplexElements((Complex **) &firstMatElems, firstMatRows, firstMatColumns);
                firstMat = createMatrix(firstMatRows, firstMatColumns, ComplexField, firstMatElems);
                printf("Create the second Matrix\n");
                setRows(&secondMatRows);
                setColumns(&secondMatColumns);
                enterComplexElements((Complex **) &secondMatElems, secondMatRows, secondMatColumns);
                secondMat = createMatrix(secondMatRows, secondMatColumns, ComplexField, secondMatElems);
                resMat = sumMat(firstMat, secondMat);
                printf("Result of sum: \n");
                printMatrix(resMat);
                free(firstMat);
                free(secondMat);
                free(resMat);
                free(firstMatElems);
                free(secondMatElems);
                break;
            case 3:
                printf("Create the first Matrix\n");
                setRows(&firstMatRows);
                setColumns(&firstMatColumns);
                enterIntElements((int **) &firstMatElems, firstMatRows, firstMatColumns);
                firstMat = createMatrix(firstMatRows, firstMatColumns, IntField, firstMatElems);
                printf("Create the second Matrix\n");
                setRows(&secondMatRows);
                setColumns(&secondMatColumns);
                enterIntElements((int **) &secondMatElems, secondMatRows, secondMatColumns);
                secondMat = createMatrix(secondMatRows, secondMatColumns, IntField, secondMatElems);
                resMat = mulMat(firstMat, secondMat);
                printf("Result of multiplication: \n");
                printMatrix(resMat);
                free(firstMat);
                free(secondMat);
                free(resMat);
                free(firstMatElems);
                free(secondMatElems);
                break;
            case 4:
                printf("Create the first Matrix\n");
                setRows(&firstMatRows);
                setColumns(&firstMatColumns);
                enterComplexElements((Complex **) &firstMatElems, firstMatRows, firstMatColumns);
                firstMat = createMatrix(firstMatRows, firstMatColumns, ComplexField, firstMatElems);
                printf("Create the second Matrix\n");
                setRows(&secondMatRows);
                setColumns(&secondMatColumns);
                enterComplexElements((Complex **) &secondMatElems, secondMatRows, secondMatColumns);
                secondMat = createMatrix(secondMatRows, secondMatColumns, ComplexField, secondMatElems);
                resMat = mulMat(firstMat, secondMat);
                printf("Result of multiplication: \n");
                printMatrix(resMat);
                free(firstMat);
                free(secondMat);
                free(resMat);
                free(firstMatElems);
                free(secondMatElems);
                break;
            case 5:
                printf("Create the Matrix\n");
                setRows(&firstMatRows);
                setColumns(&firstMatColumns);
                enterIntElements((int **) &firstMatElems, firstMatRows, firstMatColumns);
                firstMat = createMatrix(firstMatRows, firstMatColumns, IntField, firstMatElems);
                resMat = transposeMat(firstMat);
                printf("The transposed input Matrix: \n");
                printMatrix(resMat);
                freeMatrix(firstMat);
                freeMatrix(resMat);
                free(firstMatElems);
                break;
            case 6:
                printf("Create the Matrix\n");
                setRows(&firstMatRows);
                setColumns(&firstMatColumns);
                enterComplexElements((Complex **) &firstMatElems, firstMatRows, firstMatColumns);
                firstMat = createMatrix(firstMatRows, firstMatColumns, IntField, firstMatElems);
                resMat = transposeMat(firstMat);
                printf("The transposed input Matrix: \n");
                printMatrix(resMat);
                freeMatrix(firstMat);
                freeMatrix(resMat);
                free(firstMatElems);
                break;
            default:
                fprintf(stderr, "Unknown command\n");
                break;
        }
        if (userChoice != 0)
        {
            menu();
        }
    }
    free(IntField);
    free(ComplexField);
    return 0;
}
