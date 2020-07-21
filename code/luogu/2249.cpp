#include <bits/stdc++.h>
using namespace std;
int main(){
    int tmp;
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m;i++){
        int q = 0;
        cin >> q;
        int b = 0;
        int e = n;
        while(b<e){
            int mid = (b + e) / 2;
            if(!(v[mid]>=q))
                b = mid + 1;
                else
                    e = mid;
        }
        if(v[e]==q){
            cout << e + 1 <<' ';
        }else
            cout << -1 << ' ';
    }
}