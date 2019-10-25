#include<cstdio>
#include<iostream>
using namespace std;
int  gcd(long long  a,long long  b)
{
    if(b==0) return a;
    else return gcd(b,a%b); 
 }   
long long  zuixiao(long long  a,long long  b){return a*b/gcd(a,b);}
int   main(){
        long long  n;
        long long  tmp;
        long long  ans=1;
        while(cin>>n){
                ans=1;
                for(int  i=0;i<n;i++){
                        cin>>tmp;
                        ans=zuixiao(tmp,ans);
                }
                cout<<ans<<endl;


        }
        return 0;

}