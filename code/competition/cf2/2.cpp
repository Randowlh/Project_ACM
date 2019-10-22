#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int date[100000];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&date[i]);
    }
    sort(date,date+n);
    long long ans1=0;
    long long ans2=0;
    for(int i=0;i<n/2;i++){
        ans1+=date[i];
    }
    for(int i=n/2;i<n;i++){
        ans2+=date[i];
    }
    ans1=ans1*ans1;
    ans2=ans2*ans2;
    cout<<ans1+ans2<<endl;
    return 0;
}