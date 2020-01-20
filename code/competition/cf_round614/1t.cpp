#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n,k,s;
    cin>>n>>s>>k;
    vector<int> d;
    int tmp;
    for(int i=0;i<k;i++){
        scanf("%d",&tmp);
        d.push_back(tmp);
    }
    int cnt=0;
    while(true){
        if(s+cnt<=n){
            int flag=0;
            for(int i=0;i<k;i++){
                if(d[i]==s+cnt){
                    flag=1;
                }
            }
            if(flag==0){
                break;
            }
        }
        if(s-cnt>0){
            int flag=0;
            for(int i=0;i<k;i++){
                if(d[i]==s-cnt){
                    flag=1;
                }
            }
            if(flag==0)
            break;
        }
        cnt++;
        if(cnt>n)
        break;
    }
    cout<<cnt<<endl;
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}