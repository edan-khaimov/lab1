#include <assert.h>
#include "testComplexOperations.h"
#include "complex.h"

void testComplexSum()
{
    Complex a = {128, 124};
    Complex b = {1, 1000};
    Complex ans = {a.Real + b.Real, a.Im + b.Im};
    Complex testAns;
    complexSum((void *)&testAns, (void *)&a, (void *)&b);
    assert(testAns.Real == ans.Real && testAns.Im == ans.Im);
}

void testComplexMul()
{
    Complex a = {4, 20};
    Complex b = {10, 1000};
    Complex ans = {a.Real * b.Real - a.Im * b.Im, a.Real * b.Im + b.Real * a.Im};
    Complex testAns;
    complexMul((void *)&testAns, (void *)&a, (void *)&b);
    assert(testAns.Real == ans.Real && testAns.Im == ans.Im);
}