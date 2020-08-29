#include <bits/stdc++.h>
using namespace std;
struct node{
    string name;
    int y,m,d,n;
    inline bool operator < (const node a){
        if(y==a.y){
            if(m==a.m){
                if(d==a.d){
                    return n>a.n;
                }
                return d<a.d;
            }
            return m<a.m;
        }
        return y<a.y;
    }
}arr[1100];
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].name>>arr[i].y>>arr[i].m>>arr[i].d;
        arr[i].n=i;
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i].name<<endl;
    }
}