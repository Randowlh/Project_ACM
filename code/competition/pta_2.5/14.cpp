#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int dp[1000100][4];
void work(){
    string tmp;
    cin>>tmp;
    dp[0][0]=1;
   // cout<<123123<<endl;
    for(int i=1;i<=tmp.size();i++){
        for(int j=0;j<4;j++){
            if(j<3){
                dp[i][j+1]+=dp[i-1][j];
            }
            dp[i][j]+=dp[i-1][j];
            //cout<<"sd"<<endl;
            for(int k=i-1;k>=max(0,i-j);k--){
				if(tmp[i-1] == tmp[k-1])
				{
				dp[i][j]-=dp[k-1][j-i+k];
				break;
				}
            }
        }
    }
    int ans=0;
    for(int i=0;i<4;i++){
        ans+=dp[tmp.size()][i];
    }
    cout<<ans<<endl;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}