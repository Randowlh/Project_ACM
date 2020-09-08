#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int tmp;
    vector<int> v;
    for(int i=0; i<=n; i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    for(int i=0;i<=n;i++){
        if(!v[i])
            continue;
        if(n-i==1){
            if(v[i]>0&&i)
                cout<<"+";
            else if(v[i]<0)
                cout<<'-';
            if(abs(v[i])!=1)
            cout<<abs(v[i]);
            cout<<"x";
        }else if(i==n){
            if(v[i]>0&&i)
            cout<<"+";
            cout<<v[i]<<endl;
        }else {
            if(v[i]>0&&i)
                cout<<"+";
            else if(v[i]<0)
                cout<<'-';
            if(abs(v[i])!=1)
            cout<<abs(v[i]);
            cout<<"x^";
            cout<<n-i;
        }
    }
    cout<<endl;
}