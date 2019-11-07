#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,m,d;
    cin>>n>>m>>d;
    int date[100000];
    int ans=0;
    ans+=d;
    for(int i=0;i<m;i++){
        scanf("%d",&date[i]);
        ans+=d+date[i]-1;
    }
    long long fr[100000];
    fr[m]=0;
    for(int i=m-1;i>=0;i--){
        fr[i]=date[i]+fr[i+1];
    }
    if(ans<n){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        int now=0;
        int tmp=0;
        int cnt=0;
        while(now<n){
            tmp++;
            if(tmp<d){
                //tmp++;
                now++;
                cout<<'0'<<' ';
            }else
            {
                for(int i=0;i<date[cnt];i++){
                    cout<<cnt+1<<' ';
                    now++;
                }
                tmp=0;
                cnt++;
            }
            if(n-now+1<=d+fr[cnt]-tmp){
                for(int i=n-now-fr[cnt];i>0;i--){
                    cout<<"0 ";
                }
                for(int i=cnt;i<m;i++){
                    for(int j=0;j<date[i];j++)
                    cout<<i+1<<' ';
                }
                break;
            }
        }
        cout<<endl;
    }
    return 0;
}