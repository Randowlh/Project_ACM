#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
ll read(string a){
    ll ans=0;
    for(int i=0;i<a.size();i++){
        ans*=10;
        if(a[i]<='9'&&a[i]>='0'){
            ans+=a[i]-'0';
        }else{
            if(a[i]=='\n')
            return ans;
            else 
            return -1;
        }
    }
    return ans;
}
void work(){
    string a,b;
    cin>>a;
    getchar();
    getline(cin,b);
    ll n=read(a);
    ll m=read(b);
    if(n>1000||n<1){
        cout<<"? + ";
    }else cout<<n<<" + ";
    if(m>1000||m<1)
    cout<<"? = ";
    else cout<<m<<" = ";
    if(m<1||m>1000||n<1||n>1000){
        cout<<"?"<<endl;
    }else cout<<m+n<<endl;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}