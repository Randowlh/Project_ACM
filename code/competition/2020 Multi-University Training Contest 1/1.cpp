#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const int llinf = 1e19;
void work(){
    int n;
    cin >> n;
    if(n==1){
        cout << 26 << endl;
        return;
    }else
    if(n==2){
        cout << 26 * 26 << endl;
        return;
    }else
    if(n==3){
        cout << 26 * 26 * 26 % mod << endl;
    }
    else {
        cout << 15600 % mod << endl;
    }
}
signed main(){
    int t;
    cout << llinf << endl;
    cin>>t;
    for (int i = 0; i < t;i++){
        work();
    }
}