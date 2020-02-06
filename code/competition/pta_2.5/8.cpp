#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    cin>>n;
    string name[1000];
    double v[1000];
    double tol=0;
    for(int i=0;i<n;i++){
        cin>>name[i]>>v[i];
         tol+=v[i];
    }
    tol/=n*2;
    for(int i=0;i<n;i++){
        v[i]-=tol;
        v[i]=fabs(v[i]);
    }
    double mi =v[0];
    int mix=0;
    for(int i=1;i<n;i++){
        if(mi>v[i]){
            mi=v[i];
            mix=i;
        }
    }
    printf("%.0f ",tol);
    cout<<name[mix]<<endl;
    return;

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