#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    ll n;
    //ll date[100010];
    cin>>n;
    ll tmp;
    ll tol;
    ll sum=0;
    cin>>tmp;
    tol=tmp;
    sum+=tmp;
    for(int i=0;i<n-1;i++){
        scanf("%d",&tmp);
        tol=tol^tmp;
        sum+=tmp;
    }
    if(tol*2==sum){
        cout<<0<<endl;
        cout<<endl;
        return ;
    }
    vector<ll> ans;
    /*
    if(sum%2==1){
        ans.push_back(1);
        sum++;
        tol^=1;
    }*/
    sum+=tol;
    ans.push_back(tol);
    ans.push_back(sum);
    //sum/=2;
    //int t=0;
    //while(sum!=0){
      //  if(sum%2==0)
    //}
    //tol^=1;
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    //int x=tol^sum;

  //  cout<<tol<<endl;
}
int main(){
    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}