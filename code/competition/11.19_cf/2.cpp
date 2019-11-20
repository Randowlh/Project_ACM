#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct  node
{
    int w;
    int n;
    bool operator<(node a){
        if(this->w==a.w){
            return this->n<a.n;
        }else
        return this->w<a.w;
    }
    }date[10000];

//int date[10000];
int a[10000][2];
int main(){
    int t;
    cin>>t;
    int n,m;
    for(int q=0;q<t;q++){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>date[i].w;
            date[i].n=i+1;
        }
        if(n<=2){
            printf("-1\n");
            continue;
        }
        if(m<n){
           printf("-1\n");
            continue;
        }
        int ans=0;
        sort(date,date+n);
        int tail=0;
        int flag=0;
        while(m>0){
            for(int i=0;i<n;i++){
                if(m==0){
                    break;
                }
                   // cout<<i<<' '<<j<<' '<<tail<<endl;
                   if(i==n-1){
                        ans+=date[i].w+date[0].w;
                    m--;
                    a[tail][0]=date[i].n;
                    a[tail][1]=date[0].n;
                    tail++;
                    continue;
                   }
                    ans+=date[i].w+date[i+1].w;
                    m--;
                    a[tail][0]=date[i].n;
                    a[tail][1]=date[i+1].n;
                    tail++;
                }
            }
        printf("%d\n",ans);
        for(int i=0;i<tail;i++){
            cout<<a[i][0]<<' '<<a[i][1]<<endl;
        }
    }
    return 0;
}