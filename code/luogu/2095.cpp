#include <bits/stdc++.h>
using namespace std;
#define int long long
int M[100000];
signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    int tmp;
    for (int i = 1; i <= k;i++){
        cin >> tmp;
        M[i]=tmp;
    }
    vector<pair<int, int> > v;
    pair<int, int> tt;
    for (int i = 0; i < n;i++){
        cin >> tt.first >> tt.second;
        v.push_back(tt);
    }
    sort(v.begin(), v.end(), greater<pair<int,int> >());
    int ans = 0;
    int cnt=0;
    for (int i = 0; i < n;i++){
        if(cnt>=m)
            break;
        if(M[v[i].second]){
            cnt++;
            ans += v[i].first;
            M[v[i].second]--;
        }
    }
    cout << ans << endl;
}