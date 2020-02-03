#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
struct node
{
    int date[110][110];
    node operator*(node a)
    {
        node x;
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
            {
                int ans = 0;
                for (int k = 0; k < 100; k++)
                {
                    ans = (date[i][k] * a.date[k][j]+ans);
                }
                x.date[i][j] = ans;
            }
        return x;
    }
    node operator=(node a)
    {
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                date[i][j] = a.date[i][j];
                return *this;
    }
}a,b;
void work(){
    memset(a.date,0,sizeof(a.date));
    memset(b.date,0,sizeof(b.date));
    int ra,la;
    cin>>ra>>la;
    int tmp;
    for(int i=0;i<ra;i++)
    for(int j=0;j<la;j++){
        cin>>tmp;
        a.date[i][j]=tmp;
    }
    int rb,lb;
    cin>>rb>>lb;
    for(int i=0;i<rb;i++)
    for(int j=0;j<lb;j++){
        cin>>tmp;
        b.date[i][j]=tmp;
    }
    if(la!=rb){
        cout<<"Error: "<<la<<" != "<<rb;
        return;
    }
    node x=a*b;
    cout<<ra<<' '<<lb<<endl;
    for(int i=0;i<ra;i++){
    for(int j=0;j<lb-1;j++){
     cout<<x.date[i][j]<<' ';   
    }
    cout<<x.date[i][lb-1]<<endl;
    }
    return;
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