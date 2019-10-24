#include<cstdio>
#include<cstring>
const int MAXN = 10001;
int prime[MAXN];
bool vis[MAXN]; 
int phi[MAXN];
int cnt=0;
void Prime(int n)
{
	
	memset(vis,0,sizeof(vis));
	for(int i=2;i<n;i++)
	{
		if(!vis[i])
		{                   
			prime[cnt++]=i;
			phi[i]=i-1;
		}
		for(int j=0;j<cnt&&i*prime[j]<n;j++)
		{
			long long k=i*prime[j];
			vis[k]=1;
			if(i%prime[j]==0)
			{
				phi[k]=phi[i]*prime[j];
				break;
			}
			else
			phi[k]=phi[i]*(prime[j]-1);
		
		}
	}
}

int main(){
    Prime(10001);
    int k,n;
    scanf("%d%d",&n,&k);
    int ans=0;
    int cntt=0;
    int flag=0;
    for(int i=cnt-1;i>0;i--){
        if(prime[i]<=n){
            ans+=prime[i];
            cntt++;
            if(k==cntt){
                printf("%d=",prime[i]);
                flag=1;
                break;
            }else
            {
                printf("%d+",prime[i]);
            }
            
        }
    }
    if(flag==0){
        ans+=prime[0];
        printf("%d=",prime[0]);
    }
    printf("%d\n",ans);
    return 0;
}