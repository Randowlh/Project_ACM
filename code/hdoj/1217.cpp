#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int cnt,n;
double mp[40][40];
int book[40];
int flag=0;
void dfs(int start, double mon, int now)
{   
    if(flag==1){
        return;
    }
    for(int i=1;i<cnt;i++){
        if(mp[now][i]!=-1){
            if(i==start){
                if(mon*mp[now][i]>1000){
                flag=1;
                return;
                }
                //return;
                continue;
            }else{
                if(book[i]==0){
                book[i]=1;
                dfs(start,mon*mp[now][i],i);
                book[i]=0;
                }
            }
        }
    }
    return ;
}
int main()
{   int k=0;
    while (true)
    {   k++;
        cin >> n;
        if (n == 0)
            break;
        map<string, int> m;
        m.clear();
        cnt = 1;
        string tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            m[tmp] = cnt;
            cnt++;
        }
     //   int map[40][40];
        for (int i = 0; i < 40; i++)
            for (int j = 0; j < 40; j++)
                mp[i][j] = -1;
        cin >> n;
        string tmp2;
        double v;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp >> v >> tmp2;
            mp[m[tmp]][m[tmp2]] = v;
        }  
        for(int i=0;i<40;i++){
            book[i]=0;
        }
        flag=0;
        /*
        for(int i=0;i<cnt;i++){
            for(int j=0;j<cnt;j++)
            cout<<mp[i][j]<<' ';
            cout<<endl;
        }*/
        for (int i = 1; i < cnt; i++)
        {   
            book[i]==1;
            dfs(i, 1000, i);
            book[i]==0;
        }
        if(flag==1){
            cout<<"Case "<<k<<": Yes"<<endl;
        }else{
            cout<<"Case "<<k<<": No"<<endl;
        }
    }
    return 0;
}