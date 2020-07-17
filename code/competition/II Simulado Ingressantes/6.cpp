#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v,sum;
    int tmp;
    for (int i = 0; i < n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sum.resize(100100);
    sum[0] = 0;
    sum[1] = v[0];
    for (int i = 2; i <= n;i++){
        sum[i] = sum[i - 1] + v[i - 1];
    }
    int a, b;
    for (int i = 0; i < m;i++){
        cin >> a >> b;
        if((sum[b]-sum[a-1])%2==0){
            cout << "Sim" << endl;
        }else
            cout << "Nao" << endl;
    }
}