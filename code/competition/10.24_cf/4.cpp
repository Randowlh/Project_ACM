#include<cstdio>
#include<iostream>
#include<stack>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int> pq;
int date[10010];
int ans[10010];
int tail;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>date[i];
    }
    sort(date,date+n,greater<int>());
    int m;
    cin>>m;
    int k,a;
    for(int i=0;i<m;i++){
        cin>>k>>a;
        for(int i=0;i<k;i++){
            pq.push(date[i]);
        }
        tail=0;
        while(!pq.empty()){
            ans[tail]=pq.top();
            pq.pop();
            tail++;
        }
        cout<<ans[k-a]<<endl;
    }
}