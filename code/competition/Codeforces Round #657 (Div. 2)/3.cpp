#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int, int> a[100010];
int af[100010];
int qz[100010];
void work(){
    qz[0] = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1, a + 1+m,greater<pair<int,int>>());
    for (int i = 1; i <= m;i++)
        qz[i] = qz[i - 1] + a[i].first;
    int ans = 0;
    if(n==1){
        cout << a[1].first << endl;
        return;
    }
    for (int i = 1; i <= m;i++){
        af[m-i+1] = a[i].first;
    }
        for (int i = 1; i <= m; i++)
        {
            int b = 1;
            int e = m+1;
            while (b < e)
            {
                int mid = (b + e) >> 1;
                if (a[mid].first < a[i].second)
                    e = mid;
                else
                    b = mid + 1;
            }
            //; cout << "e=" << e << endl;
            // int e = lower_bound(af + 1, af + m + 1, a[i].second) - (af);
            e = m - e + 1;
           // cout << "e=" << e <<' '<<af[e]<<' '<<a[i].second <<endl;
            if (e >= n)
            {
                ans = max(ans, qz[e]);
                continue;
            }
            else if (a[i].first < a[i].second)
            {
                int tt = qz[e];
                int last = n - e - 1;
                tt += a[i].first;
                tt += a[i].second * last;
                ans = max(ans, tt);
            }
            else
            {
                int tt = qz[e];
                int last = n - e;
                tt += a[i].second * last;
                ans = max(ans, tt);
            }
        }
    cout <<ans << endl;
}   
signed main(){
    int t;
  freopen("in.txt", "r", stdin);
    cin >> t;
    while(t--){
        work();
    }
}