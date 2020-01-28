#include <bits/stdc++.h>
using namespace std;
int dis(string a, string b)
{   
    if(a==b)
    return 0;
    int k = 0;
    for (int i = 0; i < min(a.size(), b.size()); i++)
    {
        if (a[i] != b[i])
        {
            k = i;
            break;
        }
    }
   // cout<<k<<endl;
    int ans = 0;
    ans += b.size() - k ;
    ans += a.size() - k ;
    return ans;
}
int main()
{
  freopen("in.txt", "r", stdin);
    vector<string> work;
    int n;
    string tmp;
    while (cin >> n)
    {
        work.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            work.push_back(tmp);
        }
        sort(work.begin(), work.end());
        int ans = 0;
        ans += work[0].size();
        for (int i = 0; i < n - 1; i++)
        {
            ans += dis(work[i], work[i + 1]);
        }
        ans+=n;
        cout << ans<<endl;
    }
    return 0;
}