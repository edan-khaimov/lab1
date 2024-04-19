#ifndef UI_H
#define UI_H
#include "matrix.h"
#include "complex.h"

void menu();

void setRows(size_t *rows);

void setColumns(size_t *columns);

void enterIntElements(int **elems, size_t rows, size_t columns);

void enterComplexElements(Complex **elems, size_t rows, size_t columns);

void printMatrix(Matrix *mat);

#endif
