#include<bits/stdc++.h>
#define int long long
using namespace std;
pair<int,int> date[500050];
bool eab[500050];
void work(){
    int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n;i++){
        scanf("%lld%lld", &date[i].first, &date[i].second);
        eab[i] = 1;
    }
    sort(date + 1, date + n + 1);
    for (int i = 0; i < n;i++){
        
    }
}
signed main(){
    int t;
    scanf("%lld", &t);
    for (int i = 0; i < t;i++){
        work();
    }
}