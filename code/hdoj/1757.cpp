#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
int mod;
int b[5]={0,2,4,6,9};
struct node
{
    ll date[10][10];
    node operator*(node a)
    {
        node x;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
            {
                ll ans = 0;
                for (int k = 0; k < 10; k++)
                {
                    ans = (date[i][k] * a.date[k][j]+ans)%mod;
                }
                x.date[i][j] = ans;
            }
        return x;
    }
    node operator=(node a)
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                date[i][j] = a.date[i][j];
                return *this;
    }
}cst,s,e;
node pows(int n){
    node ans=e;
    node k=cst; 
    while(n!=0){
        if(n&1)
        ans=ans*k;
        k=k*k;
        n>>=1;
    }
    return ans;
}
void work(){
    int l;
    while(cin>>l>>mod){
        for(int i=0;i<10;i++){
            cin>>cst.date[0][i];
        }
        /*
        for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)
        cout<<cst.date[i][j]<<' ';
        cout<<endl;
        }
        for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)
        cout<<s.date[i][j]<<' ';
        cout<<endl;
        }
        */
        if(l<10){
            cout<<s.date[l][0]%mod<<endl;
            continue;
        }else{
            node x=pows(l-9);
        //     for(int i=0;i<10;i++){
        // for(int j=0;j<10;j++)
        // cout<<x.date[i][j]<<' ';
        // cout<<endl;
        // }
            x=x*s;
            cout<<x.date[0][0]%mod<<endl;
            continue;
        }
    }
    return ;
}
int main(){
    freopen("in.txt","r",stdin);
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++){
        cst.date[i][j]=0;
        s.date[i][j]=0;
        e.date[i][j]=0;
    }
    for(int i=0;i<10;i++)
    e.date[i][i]=1;
    for(int i=0;i<9;i++){
        cst.date[i+1][i]=1;
    }
    for(int i=0;i<10;i++){
        s.date[i][0]=10-i-1;
    }
    work();
    return 0;
}