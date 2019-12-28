#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int m,n;
    cin>>n>>m;
    int date[100010];
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        scanf("%d",&date[i]);
        mp[date[i]]=i;
    }
    int tmp;
    ll bottom=1;
    ll top=1;
    ll tol=0;
    for(int i=1;i<=m;i++){
        scanf("%d",&tmp);
        if(bottom<mp[tmp]){
            tol+=(mp[tmp]-top)*2+1;
            bottom=mp[tmp];
            top++;
        //    cout<<bottom<<"m"<<top<<' '<<tol<<endl;
        }else
        {
            tol++;
            top++;
            //bottom++;
        }
    }
    cout<<tol<<endl;
    return ;

}
int main(){
   //
   
    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}