#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int date[10000];
void Merge(int* A,int left,int mid,int right,int* C)
{	//Merge可以将两个有序的数组排好序,时间复杂度:o(n)
	int i=left;
	int j=mid+1;
	int k=left;
	while(i <= mid && j <= right)
	{
		if(A[i] <= A[j])
			C[k++]=A[i++];
		else
		{
			C[k++]=A[j++];
			count += mid-i+1;//新增
		}
	}
	while(i <= mid)
		C[k++]=A[i++];
	while(j <= right)
		C[k++]=A[j++];
	//C[]已经有序，将C[]中数据复制回原数组A[]
	for(int i=left;i <= right;++i)
		A[i]=C[i];
}	
void MergeSort(int* A,int left,int right,int* C)//假定MergeSort能将一个乱序数组A排好序．
{
	if(left < right)
	{
		int mid=(left+right)/2;
		MergeSort(A,left,mid,C);//排好一个数组1
		MergeSort(A,mid+1,right,C);//排好一个数组2
		Merge(A,left,mid,right,C); //合并两个有序的数组
	}
}
void work()
{
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}