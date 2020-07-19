#include<bits/stdc++.h>
using namespace std;
#define int long long
void work(){
    int l, r, m;
    cin >> l >> r >> m;
    if(m<l){
        cout << l << ' ' << l <<' '<< l + (l - m) << endl;
        return;
    }
    for (int i = l; i <= r;i++){
        if(m%i<=(r-l)){
            cout << i << ' ' << l + (m % i) << ' ' << l << endl;
            return;
        }
        if(i-m%i<=(r-l)){
            cout << i << ' ' << l << ' ' << l + (i - m % i) << endl;
            return;
        }
    }
}
signed main(){
   //freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t;i++){ 
        work();
    }
}