#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int main()
{
    double n, p;
    while (cin >> n >> p)
    {   
        printf("%.0lf\n", exp(log(p)/n));
    }
    return 0;
}