#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

void menu()
{
    printf("Enter number to do some action from following list\n");
    printf("0. Stop the program\n");
    printf("1. Sum 2 matrices with <int> elements\n");
    printf("2. Sum 2 matrices with <complex> elements\n");
    printf("3. Multiply 2 matrices with <int> elements\n");
    printf("4. Multiply 2 matrices with <complex> elements\n");
    printf("5. Transpose matrix with <int> elements\n");
    printf("6. Transpose matrix with <complex> elements\n");
}

void setRows(size_t *rows)
{
    printf("Enter the number of rows in the matrix: \n");
    scanf("%zu", rows);
}

void setColumns(size_t *columns)
{
    printf("Enter the number of columns in the matrix: \n");
    scanf("%zu", columns);
}

void enterIntElements(int **elems, size_t rows, size_t columns)
{
    *(elems) = (int *)malloc(rows * columns * sizeof(int));

    if(*(elems) == NULL)
    {
        fprintf(stderr, "Error! Problem with memory!\n");
        exit(1);
    }
    printf("Enter integer numbers to create the matrix\n");
    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
        {
            scanf("%d", (*(elems) + i * columns + j));
        }
    }
}

void enterComplexElements(Complex **elems, size_t rows, size_t columns)
{
    *(elems) = (Complex *)malloc(rows * columns * sizeof(Complex));

    if(*(elems) == NULL)
    {
        fprintf(stderr, "Error! Problem with memory!\n");
        exit(1);
    }
    printf("Enter 2 integer numbers (Real and Imaginary parts) to create the matrix\n");
    for(size_t i = 0; i < rows; i++)
    {
        for(size_t j = 0; j < columns; j++)
        {
            scanf("%d %d", &((*(elems) + i * columns + j)->Real), &((*(elems) + i * columns + j)->Im));
        }
    }
}

void printMatrix(Matrix *mat)
{
    size_t elemSize = mat->typeInfo->elemSize;
    for (size_t i = 0; i < mat->rows; i++)
    {
        for (size_t j = 0; j < mat->columns; j++)
        {
            void *elem = mat->elems + i * mat->columns * elemSize + j * elemSize;
            mat->typeInfo->Print(elem);
        }
        putchar('\n');
    }
    putchar('\n');
}