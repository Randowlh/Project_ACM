#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int date[100100];
int flag[100100];
int book[100100];
struct node
{
    int l;
    int t;
    /* data */
};
vector<int> rd[100010];
void work(){
    int n;
    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&date[i]);
        if(date[i]==-1)
        s=i;
    }
    for(int i=1;i<=n;i++){
        if(flag[i]==0&&date[i]!=-1){
            int now=date[i];
            int pr=i;
            while(now!=-1){
                rd[now].push_back(pr);
                if(flag[now]==1){
                    break;
                }
                flag[now]=1;
                pr=now;
                now=date[now];
            }
        }
    }
    queue<node> q;
    node x;
    x.l=s;
    x.t=1;
    q.push(x);
    book[s]=1;
    while(!q.empty()){
        for(int i=0;i<rd[q.front().l].size();i++){
            if(book[rd[q.front().l][i]]==0){
                book[rd[q.front().l][i]]=q.front().t+1;
                node x;
                x.l=rd[q.front().l][i];
                x.t=q.front().t+1;
                q.push(x);
            }
        }
        q.pop();
    }
    int mx=-1;
    vector<int> md;
    for(int i=1;i<=n;i++){
        if(book[i]==mx){
            md.push_back(i);
        }
        if(book[i]>mx){
            mx=book[i];
            md.clear();
            md.push_back(i);
        }
    }
    cout<<mx<<endl;
    for(int i=0;i<md.size()-1;i++){
        cout<<md[i]<<' ';
    }
    cout<<md[md.size()-1]<<endl;
    return;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}