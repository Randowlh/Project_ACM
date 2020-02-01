#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
#define each(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define reach(i, n) for (int(i) = n - 1; (i) >= 0; (i)--)
#define range(i, st, en) for (int(i) = (st); (i) <= (en); (i)++)
#define rrange(i, st, en) for (int(i) = (en); (i) >= (st); (i)--)
#define fill(ary, num) memset((ary), (num), sizeof(ary))
string biao="10X98765432";
int b[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
void work(){
    string tmp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        int tol=0;
        for(int j=0;j<tmp.size()-1;j++){
            tol+=(tmp[j]-'0')*b[j];
        }
        tol%=11;
        int fl=1;
        if(biao[tol]!=tmp[tmp.size()-1]){
            cout<<tmp<<endl;
            fl=0;
        }
        if(fl)
        cout<<"All passed"<<endl;
    }
}
int main(){
   // freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}