#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
#define each(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define reach(i, n) for (int(i) = n - 1; (i) >= 0; (i)--)
#define range(i, st, en) for (int(i) = (st); (i) <= (en); (i)++)
#define rrange(i, st, en) for (int(i) = (en); (i) >= (st); (i)--)
#define fill(ary, num) memset((ary), (num), sizeof(ary))
void work(){
    int n;
    char a;
    cin>>n>>a;
    int k;
    if(n%2==0){
        k=n/2;
    }else k=n/2+1;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++)
        cout<<a;
        cout<<endl;
    }
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