#include<bits/stdc++.h>
using namespace std;
int tong[110000];
int date[110000];
pair<pair<int,int>,int> qst[110000];
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>date[i];
    for(int i=1;i<=q;i++){
        cin>>qst[i].first.first>>qst[i].first.second;
        qst[i].second=i;
    }
    sort(qst+1, qst+q+1);
}