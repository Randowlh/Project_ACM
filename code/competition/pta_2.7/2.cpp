#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    int a,b;
    scanf("%d:%d",&a,&b);
    if(a<12){
        printf("Only %02d:%02d.  Too early to Dang.\n",a,b);
        return;
    }
    if(a==12&&b==0){
        printf("Only 12:00.  Too early to Dang.\n");
        return;
    }
    int fl=a-12;
    if(b>0)
    fl++;
    for(int i=0;i<fl;i++){
        cout<<"Dang";
    }
    cout<<endl;
    return;
}
int main(){
   // freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}
//Only 07:05.  Too early to Dang.