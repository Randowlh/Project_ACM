#include<map>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
map<int,int> pp1,pp2,pp3;
int date1[200020];
int date2[200020];
int main(){
    int n;
    cin>>n;
    //int date[100000]
    for(int i=0;i<n;i++){
        scanf("%d",&date1[i]);
        date2[i]=date1[i];
    }
    sort(date2,date2+n);
    int max=-9999;
    int div=-1;
    int cnt=0;
    int tmp=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(tmp==3){
            cnt++;
            tmp=0;
            ans+=
        }
        pp1[date2[i]]=cnt;
    }
}