#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int l;
    int r;
    int id;
}num[500005];
bool cmp(node x,node y)
{
    return x.l<y.l;
}
int f[500005];
int find(int x)
{
    if(x!=f[x]){
        return f[x]=find(f[x]);
    }
    return f[x];
}
void uni(int x,int y)
{
    int x1=find(x);
    int y1=find(y);
    if(x1!=y1){
        f[x1]=y1;
    }
}
void work()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&num[i].l,&num[i].r);
        num[i].id=i;
        f[i]=i;
    }
    sort(num+1,num+n+1,cmp);
    set<pair<int,int> >s;
    set<pair<int,int> >::iterator it;
    int sum=0;
    for(int i=1;i<=n;i++){
        if(sum>n-1){
            printf("NO\n");return;
        }
        pair<int,int> k;
        k.first=num[i].l;
        k.second=num[i].id;
        it=s.lower_bound(k);
        while(it!=s.end()){
            //printf("%d %d\n",(*it).first,num[i].r);
            if((*it).first>num[i].r){
                break;
            }
           // printf("???%d %d\n",(*it).second,num[i].id);
            if(find(num[i].id)==find((*it).second)){
                printf("NO\n");return;
            }else{
                uni(num[i].id,(*it).second);
                sum++;
            }
            it++;
        }
        k.first=num[i].r;
        s.insert(k);
    }
    //printf("%d\n",sum);
    if(sum!=n-1){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    //scanf("%d",&T);
    //cin>>T;
    T=1;
    while(T--){
        work();
    }
}
