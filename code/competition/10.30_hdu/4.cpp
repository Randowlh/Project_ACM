#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
    int bl;
    int at;
    bool operator<(const node a){
        return (this->bl-this->at)>(a.bl-a.at);
    }
} date[1010];
int main(){
    int t;
    int n,m;
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>date[i].at>>date[i].bl;
        }
        sort(date,date+n);
        long long  ans=0;
        for(int i=0;i<n;i++){
            if(m>0&&date[i].bl-date[i].at>0){
                ans+=date[i].bl;
                m--;
            }else{
                ans+=date[i].at;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}