#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define int long long
int _,n,m,tot,w[101005],que[101005];
int book[101005];
ll ans;
vector<int> e[101005];
struct record{
    int x,d;
    bool operator<(const record a) const{
        return x>a.x;
    }
}a[110005];
void bfs(int x){
    int i,Max=0,head=0,tail=1;
    tot++;
    book[x]=tot; que[1]=x;
    while (head^tail){
        x=que[++head];
        for (i=0;i<e[x].size();i++)
        if (book[e[x][i]]<tot&&w[e[x][i]]<=w[x])
        if (book[e[x][i]]) Max=max(Max,w[e[x][i]]);
        else{
            book[e[x][i]]=tot;
            que[++tail]=e[x][i]; 
        }
    }
    ans+=w[que[1]]-Max;
}
signed main(){
    int i,x,y;
    freopen("in.txt", "r", stdin);
    for (scanf("%lld",&_);_;_--){
        scanf("%lld%lld",&n,&m);
        for (i=1;i<=n;i++){
            scanf("%lld",&w[i]);
            a[i].d=i;
            a[i].x=w[i];
            e[i].clear();
            book[i] = 0;
        }
        sort(a+1,a+n+1);
        while (m--)
        {
            scanf("%lld%lld", &x, &y); 
            e[x].push_back(y);
            e[y].push_back(x);
        }
        for (int i = 1; i <= n;i++){
            cout << a[i].x << ' ' << a[i].d << endl;
        }
            //memset(book,0,sizeof(book));
            ans = tot = 0;
        for (i=1;i<=n;i++)
        if (!book[a[i].d]) bfs(a[i].d);
        printf("%lld\n",ans);
    }
    return 0;
}