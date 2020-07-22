#include <bits/stdc++.h>
using namespace std;
int ans = 0;
pair<int, int> date[500050];
int n;
int l;
int main(){
    cin >> n >> l;
    for (int i = 0; i < n;i++){
        cin>>date[i].first>>date[i].second;
    }
    int now = 0;
    int tmp = 0;
    int lb = 0;
    while(lb<n){
        if (date[lb].second + now >l){
            ans += tmp;
            now = date[lb].second;
            tmp = date[lb].first;
        }else{
            now += date[lb].second;
            tmp=max(tmp,date[lb].first);
        }
        lb++;
    }
    cout << ans << endl;
}   