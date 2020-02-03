#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    vector<int> v;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    if (n % 2 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] < min(i, n - 1 - i))
            {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
        return;
    }
    else
    {
       for (int i = 0; i < n; i++)
        {
            if (v[i] < min(i, n - 1 - i))
            {
                cout << "No" << endl;
                return;
            }
        }
        if(v[n/2]==v[n/2-1]&&v[n/2]==n/2-1){
            cout<<"No"<<endl;
            return;
        }
        cout<<"Yes"<<endl;
        return;
    }
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}