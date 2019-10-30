#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
long long  date[50010];
int n,m;
int fin1(int tmp)
{
    int low = 0, high = n - 1;
    while( low <= high )
    {
	int mid = (low + high) >> 1;
	if( date[mid] > tmp )
	    high = mid - 1;
	else low = mid + 1;
    }
    return high;
}
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
	int t;
	cin>>t;
	for(int q=0;q<t;q++){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			scanf("%d",&date[i]);
			date[i]*=date[i];
		}
		sort(date,date+n);
		int fr,bk;
		for(int i=0;i<m;i++){
			scanf("%d%d",&fr,&bk);
			int tmp1=fin2(fr);
			int tmp2=fin1(bk);
			printf("%d\n",tmp2-tmp1);
		}
	}
	return 0;
}