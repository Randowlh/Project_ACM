#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#include<cctype>
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define ms(a,x) memset(a,x,sizeof(a))
#define lr dying111qqz
using namespace std;
#define For(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef double DB;
const int inf = 0x3f3f3f3f;
const int N=17;
int d[N][N];
int n,m;
int dp[(1<<16)+5][N];

void floyd(){
    For(k,n){
	For(i,n){
	    For (j,n){
		d[i][j] = min ( d[i][j] , d[i][k]+d[k][j]);
	    }
	}
    }

}

void solve()
{
    dp[0][0] = 0;
    for ( int i = 0 ; i <(1<<n) ; i ++){
	for ( int j = 0 ; j < n ;j++){
	    if (dp[i][j]!=inf){
		for (int k = 0 ; k < n ; k++){
		    int tmp = i|(1<<k);
		    dp[tmp][k] = min(dp[tmp][k],dp[i][j] + d[j][k]);
		}
	    }
	}
    }
}
int main()
{
  #ifndef  ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
  #endif
    int T;
    cin>>T;
    while (T--){
	scanf("%d %d",&n,&m);
	ms(d,inf);
	ms(dp,inf);
	For(i,n){
	    d[i][i] = 0 ;
	}
	int u,v,w;
	For(i,m){
	    scanf("%d %d %d",&u,&v,&w);
	    u--;v--;
	    d[u][v] = d[v][u] =min(d[u][v],w);
	}
	floyd();
//	for ( int i = 0 ; i < n; i++){
//	    for ( int j = 0 ; j < n ; j++){
//		cout<<d[i][j]<<" ";
//	    
//	    }
//	    cout<<endl;

//	}
	solve();
	int ans = dp[(1<<n)-1][0];
	printf("%d\n",ans);

    }
  
  
 #ifndef ONLINE_JUDGE  
  fclose(stdin);
  #endif
	return 0;
}
