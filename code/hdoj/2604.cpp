#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
int mod;
int b[5]={0,2,4,6,9};
struct node
{
    ll date[4][4];
    node operator*(node a)
    {
        node x;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
            {
                ll ans = 0;
                for (int k = 0; k < 4; k++)
                {
                    ans = (date[i][k] * a.date[k][j]+ans)%mod;
                }
                x.date[i][j] = ans;
            }
        return x;
    }
    node operator=(node a)
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
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
        if(l<=4){
            cout<<b[l]%mod<<endl;
        }else{
            node x=pows(l-4);
            x=x*s;
            cout<<x.date[0][0]<<endl;
        }
    }
    return ;
}
int main(){
    freopen("in.txt","r",stdin);
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
        cst.date[i][j]=0;
        s.date[i][j]=0;
        e.date[i][j]=0;
    }
    for(int i=0;i<4;i++)
    e.date[i][i]=1;
    cst.date[0][0]=cst.date[0][2]=cst.date[0][3]=cst.date[1][0]=cst.date[2][1]=cst.date[3][2]=1;
    s.date[0][0] = 9;
	s.date[1][0] = 6;
	s.date[2][0] = 4;
	s.date[3][0] = 2;
    work();
    return 0;
}