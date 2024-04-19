#include <assert.h>
#include "testIntOperations.h"
#include "int.h"

void testIntSum()
{
    int a = 46;
    int b = 37;
    int ans = a + b;
    int testAns;
    intSum((void *)&testAns, (void *)&a, (void *)&b);
    assert(testAns == ans);
}

void testIntMul()
{
    int a = 46;
    int b = -268;
    int ans = a * b;
    int testAns;
    intMul((void *)&testAns, (void *)&a, (void *)&b);
    assert(testAns == ans);
}