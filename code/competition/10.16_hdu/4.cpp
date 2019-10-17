#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
int mod=10007;
ll PowerMod(ll a, ll n, ll m = mod) {
	if (!n || a == 1) return 1ll;
	ll s = PowerMod(a, n >> 1, m);
	s = s * s % m;
	return n & 1 ? s * a % m : s;
}
int map[100000];
int str[1000];
int tail=0;
int main(){
    int k=0;
    cin>>k;
    for(int q=0;q<k;q++){
        int n;
        cin>>n;
        int i=2;
        while(n!=1){
            if(n%i==0){
                str[tail]=i;
                tail++;
                while(n%i==0){
                    n=n/i;
                    map[i]++;
                }
                             
        }
        i++;
        }
    
    int ans=1;
    for(int i=0;i<tail;i++){
        ans=ans*PowerMod(str[i],map[str[i]])%mod;
    }
    printf("%d\n",ans);
    for(int i=0;i<tail;i++){
        map[str[i]]=0;
    }
    
    }
}