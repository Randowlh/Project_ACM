#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
struct node
{   int cnt;
    int num;
    int date;
    /* data */
    bool operator<(node a){
        if(date==a.date&&cnt==a.cnt)
        return num<a.num;
        if(date==a.date)
        return cnt>a.cnt;
        return date>a.date;
    }
}mp[10100];
void work(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        mp[i].num=i;
        int k;
        cin>>k;
        int a,b;
        for(int j=0;j<k;j++){
            cin>>a>>b;
            mp[a].cnt++;
            mp[a].date+=b;
            mp[i].date-=b;
        }
    }
    sort(mp+1,mp+n+1);
    for(int i=1;i<=n;i++){
        cout<<mp[i].num<<' ';
        double tmp=(double)mp[i].date/100.0;
        printf("%.2f\n",tmp);
    }
    return;
}
int main(){
 //  freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}