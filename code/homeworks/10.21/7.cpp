
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int MAXN=3000001;
int prime[MAXN];//保存素数 
bool vis[MAXN];//初始化 
int phi[MAXN];//欧拉函数 
void Prime(int n)
{
	int cnt=0;
	memset(vis,0,sizeof(vis));
	for(int i=2;i<n;i++)
	{
		if(!vis[i])
		{
			prime[cnt++]=i;
			phi[i]=i-1;// if p is prime,then phi[i]=i-1
		}
		for(int j=0;j<cnt&&i*prime[j]<n;j++)
		{
			__int64 k=i*prime[j];
			vis[k]=1;
			if(i%prime[j]==0)//关键 
			{
				phi[k]=phi[i]*prime[j];
				break;
			}
			else
			phi[k]=phi[i]*(prime[j]-1);
		
		}
	}
}
int main()
{
	int a,b;
	Prime(3000000);
	while(cin>>a>>b)
	{
		__int64 ans=0;
		for(int i=a;i<=b;i++)
		ans+=phi[i];
		cout<<ans<<endl;
	}

}