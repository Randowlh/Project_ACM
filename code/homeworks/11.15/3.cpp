#include<cstdio>
#include<iostream>
using namespace std;
int abs(int a){
    if(a<0)return -a;
    else return a;
}
int main(){
    int n;
    int maxs=-1;
    int tmpx=-1;
    int tmpy=-1;
    int tmps=-1;
    int m;
    cin>>n>>m;
    int tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>tmp;
            if(abs(tmp)>maxs){
                maxs=abs(tmp);
                tmps=tmp;
                tmpx=i+1;
                tmpy=j+1;
            }
        }
    }
    cout<<tmpx<<' '<<tmpy<<' '<<tmps<<endl;
    return 0;
}