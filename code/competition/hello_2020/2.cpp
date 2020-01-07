#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
struct node
{   
    int f;
    int e;
    //int b;
    bool operator<(node a){
        return f>a.f;
    }
    bool operator>(node a){
        return e<a.e;
    }
};
bool cmp(node a,node b){
    return a.e<b.e;
}

vector<node> db;
int dt=0;
vector<int> date[100010];
//int flag[100010];
ll fac(int x){
    ll ans=1;
    for(int i=1;i<=x;i++){
        ans*=x;
    }
    return ans;
}
int check(int x)
{
    int pre = date[x][0];
    for (int i = 1; i < date[x].size(); i++)
    {      
        if (pre < date[x][i])
        {
            return 1;
        }
        pre = date[x][i];
    }
    return 0;
}
void work()
{
    int n;
    cin >> n;
    int  dt=0;
    for (int i = 0; i < n; i++)
    {
       // flag[i] = 0;
      // db[i].b=0;
        int k;
        cin >> k;
        int tmp;
        for (int j = 0; j < k; j++)
        {
            cin >> tmp;
            date[i].push_back(tmp);
        }
        if(check(i)==1){
          dt++;  
        }else {
            node a;
            a.f=date[i][0];
            a.e=date[i][date[i].size()+1];
            db.push_back(a);
        }
      //  db[i].b=check(i);
    }
    ll cnt=0;
    sort(db.begin(),db.end());
    int l=db.size();
    for(int i=0;i<l-1;i++){
        //if(db[i].b==1)
        int b=i+1;
        int e=l-1;
        while(b!=e){
            if(b+1==e){
                if(db[i].e<db[e].f){
                    break;
                }else{
                    e=b;
                    break;
                }
            }
            int mid=(b+e)/2;
            if(db[i].e<db[mid].f){
                b=mid;
                continue;
            }else {
                e=mid;
                continue;
            }
        }
        cnt+=e-i;
    }
  //  cout<<"yes"<<endl;
    sort(db.begin(),db.end(),cmp );
    for(int i=0;i<l-1;i++){
        int b=i+1;
        int e=l-1;
        while(b!=e){
            if(b+1==e){
                if(db[i].f>db[e].e){
                    break;
                }else{
                    e=b;
                    break;
                }
            }
            int mid=(b+e)/2;
            if(db[i].f>db[mid].e){
                b=mid;
            }else
            {
                e=mid;
            }
        }
        cnt+=e-i;
    }
    cnt+=dt*(dt-1);
    cnt+=dt*l;
    /*
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(flag[i]||flag[j]||date[i][date[i].size()-1]<date[j][0]){
                cnt++;
            }
        }
    }
    for(int i=n-1;i>=0;i--)
        for(int j=i-1;j>=0;j--){
            if(flag[i]||flag[j]||date[i][date[i].size()-1]<date[j][0]){
                cnt++;
            }
        }
    for(int i=0;i<n;i++){
         if(flag[i]||date[i][date[i].size()-1]<date[i][0]){
                cnt++;
            }
    }*/
    cout<<cnt<<endl;;
    return ;
}
int main()
{
    // int a=1;
    // printf("%f",a);
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}   