#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    vector<int> v;
    int tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    if(n%2==0){
        int tol=0;
        for(int i=n/2;i<n;i++){
            tol+=v[i];
        }
        for(int i=0;i<n/2;i++){
            tol-=v[i];
        }
        cout<<"Outgoing #: "<<n/2<<endl;
        cout<<"Introverted #: "<<n/2<<endl;
        cout<<"Diff = "<<tol<<endl;
    }else{
        cout<<"Outgoing #: "<<n/2+1<<endl;
        cout<<"Introverted #: "<<n/2<<endl;
        int tol=0;
        for(int i=n/2;i<n;i++){
            tol+=v[i];
        }
        for(int i=0;i<n/2;i++){
            tol-=v[i];
        }
        cout<<"Diff = "<<tol<<endl;
    }
}
int main(){
   // freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}
/*
Outgoing #: 5
Introverted #: 5
Diff = 3611


*/