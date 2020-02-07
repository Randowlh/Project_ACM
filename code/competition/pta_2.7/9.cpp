#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int mp[110][110];
void work(){
    int n,m,k;
    cin>>n>>m>>k;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        mp[a][b]=c;
        mp[b][a]=c;
    }
    for(int i=0;i<k;i++){
        cin>>a>>b;
        if(mp[a][b]==1){
            set<int> t;
            for(int i=1;i<=n;i++){
                if(mp[a][i]==-1)
                t.insert(i);
            }
            int fl=1;
            for(int i=1;i<=n;i++){
                if(mp[b][i]==-1&&t.count(i)!=0){
                    cout<<"OK"<<endl;
                    fl=0;
                    break;
                }
            }
            if(fl)
            cout<<"No problem"<<endl;
        }else if(mp[a][b]==0){
            cout<<"OK"<<endl;
        }else {
            set<int> t;
            for(int i=1;i<=n;i++){
                if(mp[a][i]==1)
                t.insert(i);
            }
            int fl=1;
            for(int i=1;i<=n;i++){
                if(mp[b][i]==1&&t.count(i)!=0){
                    cout<<"OK but..."<<endl;
                    fl=0;
                    break;
                }
            }
            if(fl)
            cout<<"No way"<<endl;
        }
    }
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