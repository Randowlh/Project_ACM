#include<bits/stdc++.h>
using namespace std;
int ans[1110000],ansma[1110000];
deque<pair<int,int>> q,q2;
int main(){
    int n,k;
    int tmp;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
        while(!q.empty()&&q.front().second+k<=i)
            q.pop_front();
        while(!q2.empty()&&q2.front().second+k<=i)
            q2.pop_front();
        while(!q2.empty()&&q2.back().first<tmp)
            q2.pop_back();
        while(!q.empty()&&q.back().first>tmp)
            q.pop_back();
        q2.push_back(make_pair(tmp,i));
        q.push_back(make_pair(tmp,i));
        if(i>=k){
            ans[i-k]=q.front().first;
            ansma[i-k]=q2.front().first;
        } 
    }
    for(int i=0;i<=n-k;i++)
        printf("%d ",ans[i]);
    puts("");
    for(int i=0;i<=n-k;i++)
        printf("%d ",ansma[i]);
    puts("");
}