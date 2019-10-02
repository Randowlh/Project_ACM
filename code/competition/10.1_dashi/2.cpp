#include<iostream>
#include<cstring>
#define MAXN 10001
using namespace std;
int a[MAXN],b[MAXN],g[MAXN],k[MAXN];    
int main(){
    int n;
    cin>>n;     
    for(int i=1;i<=n;i++){
        int g1,k1;
        cin>>a[i]>>b[i]>>g1>>k1;
        g[i]=g1+a[i],k[i]=k1+b[i];      
    }
    int x,y;
    cin>>x>>y;
    int data=-1;        
    for(int i=1;i<=n;i++){      
        if(x>=a[i]&&x<=g[i]&&y>=b[i]&&y<=k[i]){     
            data=i;     
        } 
    }
    cout<<data<<endl;       
    return 0;
} 