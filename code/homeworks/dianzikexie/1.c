#include <stdio.h>
int main()
{
    int r, g, b;
    char s[100];
    scanf("%02x%02x%02x", &r, &g, &b);
    r >>= 3;
    r <<= 3;
    int tmp = g >> 5;
    tmp <<= 5;
    g -= tmp;
    g >>= 2;
    tmp >>= 5;
    r += tmp;
    g <<= 5;
    b >>= 3;
    b += g;
    printf("%02x%02x\n", r, b);
    return 0;
}