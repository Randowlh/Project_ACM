#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
#define MP make_pair
#define pb push_back
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
vector<string> wd,fg;
bool ck(string& s){
    if((int)s.size()==1)
        return false;
    if(s[0]>='a'&&s[0]<='z')
        return false;
    int cnt=0;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]>='A'&&s[i]<='Z')
            cnt++;
    }
    return cnt==1;
}
bool ck2(string&s){
    if((int)s.size()>1)
        return  false;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]!=' ')
            return false;
    }
    return true;
}
void work()
{
    string tmp;
    while(getline(cin, tmp)){
        if(tmp.empty()){
            cout<<endl;
            continue;
        }
        wd.clear();
        fg.clear();
        string ww,fgg;
        int flag=1;
        if((tmp[0]>='a'&&tmp[0]<='z')||(tmp[0]>='A'&&tmp[0]<='Z')){
            flag=0;
        }
        for(int i=0;i<tmp.size();i++){
            if((tmp[i]>='a'&&tmp[i]<='z')||(tmp[i]>='A'&&tmp[i]<='Z')){
                if(!fgg.empty()){
                    fg.push_back(fgg);
                    fgg.clear();
                }
                ww.push_back(tmp[i]);
            }
            else{
                if(!ww.empty()){
                    wd.push_back(ww);
                    ww.clear();
                }
                fgg.push_back(tmp[i]);
            }
        }
        if(!ww.empty())
            wd.push_back(ww);
        if(!fgg.empty())
            fg.push_back(fgg);
        string ans;
        if(flag)
            ans+=fg[0];
        int pre=0;
        while(pre<(int)wd.size()){
            int i;
            int f=0;
            for(i=pre;i<(int)wd.size();i++){
                if(!ck(wd[i])){
                    i--;
                    break;
                }
                if(i+flag==fg.size()||!ck2(fg[i+flag])){
                    break;
                }
            }
            if(wd.size()==i)
                i--;
            if(i<=pre){
                ans+=wd[pre];
                if(pre+flag<(int)fg.size())
                    ans+=fg[pre+flag];
                if(pre>i)
                    pre=pre+1;
                else
                    pre=i+1;
                continue;
            }
            for(int j=pre;j<=i;j++)
                ans.push_back(wd[j][0]);
            ans.push_back(' ');
            ans.push_back('(');
            for(int j=pre;j<=i;j++){
                ans+=wd[j];
                ans.push_back(' ');
            }
            ans.pop_back();
            ans.push_back(')');
            if(i+flag<(int)fg.size())
            ans+=fg[i+flag];
            pre=i+1;
        }
        cout<<ans<<endl;
    }
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}