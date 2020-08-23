#include <bits/stdc++.h>
using namespace std;
int date[1010][1010];
int main(){
    int n,k;
    cin>>n>>k;
    int a,b,c,d;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c>>d;
        a++,b++,c++,d++;
        date[a][b]++;
        date[c][d]++;
        date[a][d]--;
        date[c][b]--;   
    }
    int ans=0;
    for(int i=1;i<=1000;i++)
        for(int j=1;j<=1000;j++){
            date[i][j]+=date[i-1][j]+date[i][j-1]-date[i-1][j-1];
            if(date[i][j]==k)
            ans++;
        }
    cout<<ans<<endl;
}