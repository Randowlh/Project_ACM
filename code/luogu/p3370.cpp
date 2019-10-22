#include<cstdio>
#include<algorithm>
#include<iostream>
#include<map>
#include<string>
using namespace std;
int mod1=101051;
int mod2=101009;
int mod3=101063;
int d=233;
int book3[110000];
int book1[110001];
int book2[110010];
bool check(string a){
    int res1=1;
    int res2=1;
    int res3=1;
    for(int i=0;i<a.size();i++){
        res1=(res1*d+a[i])%mod1;
        res2=(res2*d+a[i])%mod2;
        res3=(res3*d+a[i])%mod3;
    }
    if(book1[res1]==1&&book2[res2]==1&&book3[res3]==1){
        return false;
    }else
    {
        book1[res1]=1;
        book2[res2]=1;
        book3[res3]=1;
        return true;
    }
}
int main(){
    int n;
    int ans=0;
    string tmp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(check(tmp)){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}