#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
double G[100000];
double p;
inline double E(double k) { return k / p; }
int main()
{
    int k;
    while (cin >> k, k)
    {
        cin >> p;
        printf("%.3f ", k / p);
        G[0] = 0;
        for (int i = 1; i <= k; i++)
        {
            G[i] = G[i - 1] + (2 * E(i) - 1) / p;
        }
        printf("%.3f\n", G[k]);
    }
    return 0;
}