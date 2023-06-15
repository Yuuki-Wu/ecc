#include <iostream>
#include <vector>
#include <string>
#include "CommFactor.h"
#include "Algorithm_getKey.h"
#include "inArea.h"
#include "Algorithm_getPoint.h"
using namespace std;
vector<int> Algorithm_getKey::algorithm_getKey(int p, int a, double G1x, double G1y, double Gnx, double Gny, int times)
{
    vector<int> returnkey;
    int fa;
    int fb;
    double namda;
    int n = 1;
    inArea inA;
    CommFactor cf;
    Algorithm_getPoint agp;
    if (time == 0)
    {
    }
    else if (times == 1)
    {
        Gnx = G1x;
        Gny = G1y;
    }
    else if(times > 1)
    {
        while ( n < times) {
            if (G1x == Gnx && G1y == Gny) {
                namda = (3 * pow(G1x, 2) + a) / (2 * G1y);
                if (namda != int(namda))
                {
                    fa = 3 * pow(G1x, 2) + a;
                    fb = 2 * G1y;
                    int gcd = cf.commfactor(fa, fb);
                    fa = fa / gcd;
                    fb = fb / gcd;
                    fa = inA.inarea(fa, p);
                    fb = inA.inarea(fb, p);
                    for (int i = 0; i < p; i++)
                    {
                        if (i * fb % p == fa)
                        {
                            namda = i;
                        }
                    }
                }
                Gnx = int(pow(namda, 2) - G1x - Gnx) % p;
                Gny = int(namda * (G1x - Gnx) - G1y) % p;
                n++;
            }
            else if (G1x != Gnx) {
                namda = (Gny - G1y) / (Gnx - G1x);
                if (namda != int(namda))
                {
                    fa = Gny - G1y;
                    fb = Gnx - G1x;
                    fa = inA.inarea(fa, p);
                    fb = inA.inarea(fb, p);
                    for (int i = 0; i < p; i++)
                    {
                        if (i * fb % p == fa)
                        {
                            namda = i;
                        }
                    }
                }
                Gnx = int(pow(namda, 2) - G1x - Gnx) % p;
                Gny = int(namda * (G1x - Gnx) - G1y) % p;
                n++;
            }      
        }
        
    }
    Gnx = inA.inarea(Gnx, p);
    Gny = inA.inarea(Gny, p);
    returnkey.push_back(Gnx);
    returnkey.push_back(Gny);
    return returnkey;
}
