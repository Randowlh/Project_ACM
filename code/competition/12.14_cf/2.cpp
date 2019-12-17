#include<cstdio>
#include<set>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int inf = 0x7FFFFFFF;
int date[200010];
struct cmp
{   bool operator()(int a,int b){
    return a>b;
}
    /* data */
};

set<int,vector<int>,cmp > q;
int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&date[i]);
        }
        int cnt=0;
        sort(date,date+n,greater<int>());
        while(true){
            int flag=0;
            for(int i=0;i<n;i++){
                if(flag==0&&date[i]%2==0){
                    flag=date[i];
                    date[i]/=2;
                }else
                if(date[i]==flag){
                    date[i]/=2;
                }
            }
            if(flag!=0)
            cnt++;   
            else 
            break;      
        }
        printf("%d\n",cnt);
    }   
    return 0;
}