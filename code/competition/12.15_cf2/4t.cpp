#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
using namespace std;
struct node
{   int fr;
    int po;
    int a, b, c;
    int num;
    bool operator<(node a){
        return this->c>a.c;
    }
} date[6000];
struct cmp
{
    bool operator()(node a,node b){
        return a.c>b.c;
    }
};

priority_queue<node,vector<node>,cmp> qe;
int bl[6000];
int dp[6000];
int n, m, k;
//int  loos[6000];
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &date[i].a, &date[i].b, &date[i].c);
        date[i].po = -1;
        date[i].fr = -1;
        date[i].num=i;
    }
    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        date[u - 1].po = v - 1;
        date[v-1].fr=u-1;
    }
    bl[0] = k;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (bl[i] < date[i].a)
        {
            flag = 1;
            break;
        }
        bl[i + 1] = bl[i] + date[i].b;
    }
    if (flag == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = max(date[i].a, dp[i] - date[i].b);
        bl[i]-=dp[i];
    }
    for(int i=0;i<n;i++){
        qe.push(date[i]);
    }
    long long tol=0;
    for(int i=0;i<n;i++){
        int tmp=qe.top().num;
        if(date[tmp].fr!=-1&&bl[date[tmp].fr]>0){
            bl[date[i].fr]--;
            tol+=date[tmp].c;
            qe.pop();
            continue;
        }
        //int flag=0;
        for(int i=tmp;i>=0;i--){
            if(bl[i]>0){
                bl[i]--;
                tol+=date[tmp].c;
                qe.pop();
                //flag=1;
                break; 
            }
        }
    }
    cout<<tol<<endl;
    return 0;
}