#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int solve(int l,int r,int h){
    if(l>r)
        return 0;
    if(l==r)    
        return min(v[l]-h,1);
    int mi=0x7FFFFFFF;
    int mix=l;
    for(int i=l;i<=r;i++){
        if(v[i]<mi){
            mi=v[i];
            mix=i;
        }
    }
    //cout<<"l="<<l<<' '<<"r="<<r<<' '<<"mix="<<mix<<endl;
    int lv=solve(l,mix-1,mi);
    int lr=solve(mix+1,r,mi);
    int v=mi-h;
    return min(lr+lv+v,r-l+1);
}
int main(){
    int n,tmp;
    cin>>n;
    for(int i=0; i<n;i++)
        cin>>tmp,v.push_back(tmp);
    cout<<solve(0,v.size()-1,0)<<endl;
}