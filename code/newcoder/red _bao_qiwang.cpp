#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{ std::ios::sync_with_stdio(false);
    int n, m, t;
    cin >> m >> n >> t;
    int tmp;
    for (int i = 0; i < t; i++)
    {
    	cin>>tmp;
    	if(tmp>m)
    	cout<<0<<endl;
    	else if(tmp==m)
    	cout<<n/m+n%m<<endl;
    	else cout<<n/m<<endl;
    }
    return 0;
}
