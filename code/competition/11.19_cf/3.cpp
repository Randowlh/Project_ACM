#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct  node
{   int a[3]
}date[100010];
bool out[100010];
int n;
vector<int> biao[100050];
int main(){
    cin>>n;
    for(int i=0;i<n-2;i++){
        cin>>date[i].a[0]>>date[i].a[1]>>date[i].a[2];
        out[date[i].a[0]]++;
        out[date[i].a[1]]++;
        out[date[i].a[2]]++;
        biao[out[date[i].a[0]]].push_back(i);
        biao[out[date[i].a[1]]].push_back(i);
        biao[out[date[i].a[2]]].push_back(i);
    }   
}