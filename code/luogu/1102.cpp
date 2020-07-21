#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int date[2001000];
signed main(){
    int n, c;
   // freopen("in.txt", "r", stdin);  
    n = read(), c = read();
    for (int i = 1; i <= n;i++)
        date[i] = read();
    sort(date + 1, date + n + 1);
    int ans = 0;
    for (int i = 1; i <= n;i++){
        int b = 1;
        int e = n+1;
        while(b<e){
            int mid = (b + e) >> 1;
            if(!(date[mid]>=c+date[i]))
                b = mid + 1;
            else
                e = mid;
        }
        int a1 = b;
        b = 1;
        e = n + 1;
        //e++;
        while(b<e){
            int mid = (b + e) >> 1;
            if(!(date[mid]>c+date[i]))
                b = mid + 1;
            else
                e = mid;
        }
        ans += e-a1 ;
    }
    printf("%lld\n", ans);
}