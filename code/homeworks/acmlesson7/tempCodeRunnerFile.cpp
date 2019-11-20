int main()
{
    int a, b, c;
    while ((cin >> a >> b >> c) && (a || b || c))
    {
        a /= gcd(b, c);
        printddd(a);
    }
}