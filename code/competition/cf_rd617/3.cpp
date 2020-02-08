#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
struct node
{
    int x, y;
    bool operator<(node a)const
    {   
        if(x==a.x)
        return y<a.y;
        return x < a.x;
    }
};
void work()
{   
    int ans=inf;
    int a=-1;
    int b=-1;
    int n;
    cin >> n;
    string tmp;
    cin >> tmp;
    node now;
    now.x = 0;
    now.y = 0; 
    map<node,int> M;
    M.clear();
    M[now]=0;
    for(int i=0;i<tmp.size();i++){
        if(tmp[i]=='R'){
            now.x++;
        }
        if(tmp[i]=='L'){
            now.x--;
        }
        if(tmp[i]=='U'){
            now.y++;
        }
        if(tmp[i]=='D'){
            now.y--;
        }
        if(M.count(now)==0){
            M[now]=i+1;
        }else{
            if(ans>i-M[now]){
                ans=i-M[now];
                a=M[now];
                b=i;
               
            }
             M[now]=i+1;
        }
    }
    if(a==-1&&a==b){
        cout<<-1<<endl;
    }else{
        cout<<a+1<<' '<<b+1<<endl;
    }
    return;
}
int main()
{
  // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}