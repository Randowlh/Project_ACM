#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int n,m;
    cin>>n>>m;
    string date1[100];
    string date2[100];
    for(int i=0;i<n;i++){
        cin>>date1[i];
    }
    for(int i=0;i<m;i++){
        cin>>date2[i];
    }
    int t=0;
    cin>>t;
    for(int q=0;q<t;q++){
        int tmp;
        cin>>tmp;
        tmp--;
        cout<<date1[tmp%n]<<date2[tmp%m]<<endl;
    }
    return ;
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