#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int k;
    cin>>k;
    map<string,string> p;
    map<string,string> w;
    p["ChuiZi"]="ChuiZi";
    p["Bu"]="Bu";
    p["JianDao"]="JianDao";
    w["JianDao"]="ChuiZi";
    w["Bu"]="JianDao";
    w["ChuiZi"]="Bu";
    string tmp;
    int cnt=1;
    while(cin>>tmp){
        if(tmp=="End")
        break;
        if(cnt%(k+1)==0){
            cout<<p[tmp]<<endl;
        }else{
            cout<<w[tmp]<<endl;
        }
        cnt++;
    }
    return;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
   // cin>>t;
    while(t--){
        work();
    }
    return 0;
}
/*JianDao
2
ChuiZi
JianDao
Bu
JianDao
Bu
ChuiZi
ChuiZi
End
*/