#include <bits/stdc++.h>
using namespace std;
int maxn, q;
vector<int> primes;
bool is_prime[100000100];
void euler()
{
    is_prime[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!is_prime[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] < maxn; j++)
        {
            is_prime[i * primes[j]] = 1;
            if ((i % primes[j]) == 0)
                break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> maxn >> q;
    maxn += 100;
    euler();
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        cout << primes[t - 1] << endl;
    }
}