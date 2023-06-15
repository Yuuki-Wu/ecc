#include <cmath>
bool isPrime(int p)
{
    int i;
    for (i = 2; i <= sqrt(p); i++) {
        if ((p % i) == 0) // 如果能被除了1和它本身的数整除，就不是素数 
            return false;
    }
    return true;
}