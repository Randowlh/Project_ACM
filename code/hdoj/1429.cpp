#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
struct node{
    int x;
    int y;
    int t;
    int s;
    bool operator<(node a)const{
        return t>a.t;
    }
};
// char tmp[1000];
int b[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int n,m,t;
char mp[30][30];
int book[30][30][1<<11];
// int bk[30][30];
int check(int x,int y,int s){
    if(x<0||x>=n)
    return false;
    if(y<0||y>=m)
    return false;
    if(mp[x][y]=='*')
    return false;
    if(mp[x][y]<='J'&&mp[x][y]>='A'){
        int tmp=mp[x][y]-'A';
        int k=s;
        k>>=tmp;
        if(k%2==0){
            return false;
        }
        else 
        return true;
    }
    return true;
}
void work(){
    node s,e;
    //int mp[30][30];
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
    cin>>mp[i][j];
    // bk[i][j]=inf;
    for(int k=0;k<(1<<11);k++){
        book[i][j][k]=inf;
    }
    if(mp[i][j]=='@'){
        s.x=i;
        s.y=j;
    }
    if(mp[i][j]=='^'){
        e.x=i;
        e.y=j;
    }
    }
    node x;
    x.x=s.x;
    x.y=s.y;    
    x.s=0;
    x.t=0;
    // bk[x.x][x.y]=0;
    book[x.x][x.y][x.s]=x.t;
    queue<node> q;
    q.push(x);
    while(!q.empty()){
       // cout<<"yea"<<endl;
        for(int i=0;i<4;i++){
            if(check(q.front().x+b[i][0],q.front().y+b[i][1],q.front().s)){
                node x;
                x.x=q.front().x+b[i][0];
                x.y=q.front().y+b[i][1];
                if(mp[x.x][x.y]>='a'&&mp[x.x][x.y]<='j'){
                    int tmp=mp[x.x][x.y]-'a';
                 //   cout<<q.front().s<<"v"<<endl;
                    if((q.front().s>>tmp)%2==1)
                    x.s=q.front().s;
                    else{
                    x.s=q.front().s+(1<<tmp);
                   // cout<<tmp<<"okk"<<endl;
                   // cout<<x.s<<"asd"<<endl;
                    }
                }else x.s=q.front().s;
                x.t=q.front().t+1;
                if(book[x.x][x.y][x.s]>x.t){
                    book[x.x][x.y][x.s]=x.t;
                    // bk[x.x][x.y]=min(bk[x.x][x.y],x.t);
                    q.push(x);
                }
                // if(x.x==0&&x.y==1){
                //      itoa(q.front().s,tmp,2);
                //     printf("%s\n",tmp);
                // }
                // if(x.x==e.x&&x.y==e.y){
                //     itoa(q.front().s,tmp,2);
                //     printf("%s\n",tmp);
                // }
            }
        }
        q.pop();
    }
    int mi=inf;
    for(int i=0;i<1<<11;i++){
        mi=min(mi,book[e.x][e.y][i]);
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(bk[i][j]==inf)
    //         printf("%4d",-1);
    //         else 
    //         printf("%4d",bk[i][j]);
    //     }
    //     cout<<endl;
    // }
    if(mi>=t)
    cout<<-1<<endl;
    else
    cout<<mi<<endl;
}
int main(){
    freopen("in.txt","r",stdin);
    //int t=1;
    while(cin>>n>>m>>t){
        
      //  cout<<"no"<<endl;
        work();
    }
    return 0;
}