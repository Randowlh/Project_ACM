#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int ck(int y){
    set<int> s;
    s.insert(y/1000%10);
    s.insert(y/100%10);
    s.insert(y/10%10);
    s.insert(y%10);
    return s.size();
}
void work(){
    int y,n;
    cin>>y>>n;
    int cnt=0;
    while(true){
        if(ck(y)==n)
        break;
        y++;
        cnt++;
    }
    cout<<cnt<<' '<<y/1000%10<<y/100%10<<y/10%10<<y%10<<endl;
}
int main(){
 //   freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}