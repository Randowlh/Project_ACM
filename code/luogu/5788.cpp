#include<bits/stdc++.h>
using namespace std;
stack<pair<int,int>> s;
int tmp,n;
int ans[3100000];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
        while(!s.empty()&&tmp>s.top().first){
            ans[s.top().second]=i;
            s.pop();
        }
        s.push(make_pair(tmp,i));
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    puts("");
}