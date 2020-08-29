#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[1100][10];
char sx[]={'B','E','S','I','G','O','M'};
vector<int> now;
int calc(){
    return ((now[0]+2*now[1]+2*now[2]+now[3])*(now[4]+now[5]+now[1]+now[2])*(now[6]+2*now[5]))%7;
}
int ans=0;
void dfs(int step){
    if(step==7){
        if(!calc()){
            int cnt=1;
            for(int i=0;i<7;i++)
                cnt*=arr[sx[i]][now[i]];
            ans+=cnt;
        }
        return;
    }
    for(int i=0;i<7;i++){
        if(arr[sx[step]][i]){
            now.push_back(i);
            dfs(step+1);
            now.pop_back();
        }
    }
}
signed main(){
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    char opt;
    int tmp;
    for(int i=1;i<=n;i++){
        cin>>opt>>tmp;
        arr[opt][(tmp%7+7)%7]++;
    }
    dfs(0);
    cout<<ans<<endl;
}