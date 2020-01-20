#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int mp[2][100010];
int flag[100010];
int book[2][100010];
struct node
{
    int x;
    int y;
    /* data */
};

void work(){
    set<int> s;
    int q,n;
    cin>>n>>q;
    for(int i=0;i<=n;i++){
        scanf("%d%d",&mp[0][i],&mp[1][i]);
    }
    memset(book,0,sizeof(book));
    for(int k=0;k<q;k++){
        
    }
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}