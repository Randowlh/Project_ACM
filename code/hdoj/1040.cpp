#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n;
    int date[1010];
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&date[i]);
    }
    sort(date,date+n);
    for(int i=0;i<n-1;i++){
        printf("%d ",date[i]);
    }
    printf("%d\n",date[n-1]);
    return ;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}