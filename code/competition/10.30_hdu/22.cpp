#include<cstdio>
int m,n;
long long date[100010];
int fin2(int tmp)
{
    int low = 0, high = n - 1;
    while( low <= high )
    {
	int mid = (low + high) >> 1;
	if( date[mid] >= tmp )
	    high = mid - 1;
	else low = mid + 1;
    }
    return high;
}
int main(){
 //int n,m;
 long long tmp;
 int t;
    scanf("%d",&t);
    for(int q=0;q<t;q++){
        scanf("%d%d",&n,&m);
        if(n>0){
            scanf("%lld",&date[0]);
        }
        for(int i=1;i<n;i++){
           scanf("%lld",&date[i]);
           date[i]+=date[i-1]; 
        }
        long long tmp;
        for(int i=0;i<m;i++){
            scanf("%lld",&tmp);
            if(tmp<date[0]){
                printf("0\n");
            }else{
           printf("%d\n",fin2(tmp)+1);
            }
        }
    }
    return 0;
}