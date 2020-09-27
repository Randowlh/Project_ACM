#include<bits/stdc++.h>
#define ll long long
int _;
ll n;
ll solve(ll x){
	ll res=0;
	while (x>4)
	if (x%4){
		res+=x/2;
		x=x/2-1;
	}
	else res++,x-=2;
	res+=x-1;
	return res;
}
int main(){
	for (scanf("%d",&_);_;_--){
		scanf("%lld",&n);
		printf("%lld\n",n&1?n-solve(n-1):solve(n));
	}
	return 0;
}