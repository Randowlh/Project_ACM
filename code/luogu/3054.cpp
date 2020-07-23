#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
int arr[110000];
int n, l, c;
const double inf = 0x3f3f3f3f;
int qs[110000];
int mxd = 0;

int a[110000], tmp[110000];
int aa;
void Merge(int l,int m,int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
    while(i <= m && j <= r)
    {
        if(a[i] > a[j])
        {
            tmp[k++] = a[j++];
            aa += m - i + 1;
        }
        else
        {
            tmp[k++] = a[i++];
        }
    }
    while(i <= m) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(int i=l;i<=r;i++)
        a[i] = tmp[i];
}
v1  oid Merge_sort(int l,int r)
{
    if(l < r)
    {
        int m = (l + r) >> 1;
        Merge_sort(l,m);
        Merge_sort(m+1,r);
        Merge(l,m,r);
    }
}
signed main(){
// freopen("in.txt", "r", stdin);
    cin >> n >> l >> c;
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    sort(arr , arr + n );
    for (int i = 0; i < n;i++){
        qs[i] = (int) (arr[i ]*l/arr[n-1]) ;
        a[i] =arr[i] * l % arr[n - 1];
    }
    Merge_sort(0, n-1);
    int ans = 0;
    int tol = 0;
    for (int i = n-1; i>=0;i--){
        tol += qs[i];
        ans += tol - qs[i] * (n-i);
       // cout <<ans<<' ' <<tol <<' '<<qs[i]<< endl;
    }
    cout << ans - aa << endl;
}