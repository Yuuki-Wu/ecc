#include "inArea.h"
#include "Algorithm_getPoint.h"
#include <iostream>
#include <vector>
#include <string>
int Algorithm_getPoint::count;
using namespace std;
vector<int> Algorithm_getPoint::algorithm_getPoint(int p, int a, int b)
{
    vector<int> point;
    int x = 0;
    inArea inA;
    count = 0;
    while (x < p)
    {
        int right = int(pow(x, 3) + a * x + b) % p;
        right = inA.inarea(right, p);
        for (int y = 0; y < p; y++)
        {

            if ((int(pow(y, 2)) % p) == right)
            {
                point.push_back(x);
                point.push_back(y);
                count++;
            }
        }
        x++;
    }
    return point;
}
