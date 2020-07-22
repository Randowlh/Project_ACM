#include<bits/stdc++.h>
using namespace std;
int mp[1110][1110];
int book[110][1110];
int sx, sy;
int biao[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
typedef long long ll;
bool ck(int a,int b,int t){
    if(a<0 ||a>1010)
        return false;
    if(b<0||b>1010)
        return false;
    if(book[a][b]==t)
        return false;
    return true;
}
int bfs(int t){
    priority_queue<pair<int,pair<int, int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
    book[sx][sy] = t;
    q.push(make_pair(0,make_pair(sx, sy)));
    while(!q.empty()){
        pair<int,int> tt=q.top().second;
        int tms=q.top().first;
        if (!tt.first && !tt.second)
            return tms;
        q.pop();
        for (int i = 0; i < 4;i++){
            if(ck(tt.first+biao[i][0],tt.second+biao[i][1],t)){
                    if(mp[tt.first+biao[i][0]][tt.second+biao[i][1]]){
                            book[tt.first + biao[i][0]][tt.second + biao[i][1]] = t;
                            q.push(make_pair(tms+1,make_pair(tt.first+ biao[i][0],tt.second+ biao[i][1])));
                    }else{
                        book[tt.first + biao[i][0]][tt.second + biao[i][1]] = t;
                        q.push(make_pair(tms,make_pair(tt.first + biao[i][0], tt.second + biao[i][1])));
                    }
            }
        }
    }
}
inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int main(){
    int n;
    n = read(), sx = read(), sy = read();
    int a, b;
    for (int i = 0; i < n;i++){
        a=read(),b=read();
        mp[a][b] = 1;
    }
    printf("%d\n", bfs(114514));
}