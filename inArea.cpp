#include "inArea.h"
int inArea::inarea(int num, int p)
{
    while (num > p)
    {
        num -= p;
    }
    while (num < 0)
    {
        num += p;
    }
    return num;
}
