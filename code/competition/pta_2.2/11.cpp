#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int n,k,m;
double j(vector<double> s){
    double mx=-1;
    double mi=10000000;
    double tol=0;
    for(int i=0;i<s.size();i++){
        tol+=s[i];
        if(s[i]>mx){
            mx=s[i];
        }
        if(s[i]<mi){
            mi=s[i];
        }
    }
    return (tol-mx-mi)/(s.size()-2);
}
void work(){
    cin>>n>>k>>m;
    vector<double> ans;
    for(int i=0;i<n;i++){
        double a;
        vector<double> v;
        for(int j=0;j<k;j++){
            cin>>a;
            v.push_back(a);
        }
        ans.push_back(j(v));
    }
    sort(ans.begin(),ans.end());
    for(int i=ans.size()-m;i<ans.size()-1;i++){
        printf("%.3f ",ans[i]);
    }
    printf("%.3f\n",ans[ans.size()-1]);
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