#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int date[100010];
void work(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&date[i]);
    }
    sort(date,date+n);
    
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
   // cin>>t;
    while(t--){
        work();
    }
    return 0;
}