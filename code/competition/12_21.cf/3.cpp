#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
string jie,s,ans;
void pls(){
    int now=jie.size()-1;
    while(true){
        if(jie[now]<'9'&&jie[now]>=0){
            jie[now]++;
            return;
        }
        if(jie[now]=='9'){
            jie[now]='0';
            now--;
        }
    }
    return;
}
int main(){
    ll n,m;
    cin>>n>>m;
   
    cin>>s;
   
    for(int i=0;i<m;i++){
        jie.push_back(s[i]);
    }
    int flag=0;
    for(int i=0;i<m;i++){
        if(jie[i%m]<s[i]){
            flag=1;
        }
    }
    for(int i=0;i<n;i++){
        ans.push_back(jie[i%m]);
    }
    if(ans<s){
        pls();
    }
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        printf("%c",jie[i%m]);
    }
    cout<<endl;
    return 0;
}