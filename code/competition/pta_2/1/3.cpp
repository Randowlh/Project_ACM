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
    string a;
    string b;
    getline(cin,a);
    getline(cin,b);
    int mp[1000];
    int book[20000];
    memset(book,1,sizeof(book));
    memset(mp,0,sizeof(mp));
    for(int i=0;i<b.size();i++){
        mp[b[i]]=1;
    }
    for(int i=0;i<a.size();i++){
        if(mp[a[i]]==0){
            printf("%c",a[i]);
        }
    }
    cout<<endl;
    return;
    
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}