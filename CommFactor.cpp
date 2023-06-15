#include "CommFactor.h"
int CommFactor::commfactor(int m, int n)
{
    int z = n;
    while (m % n != 0)
    {
        z = m % n;
        m = n;
        n = z;
    }
    return z;
}
