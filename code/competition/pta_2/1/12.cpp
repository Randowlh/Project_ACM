#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define each(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define reach(i, n) for (int(i) = n - 1; (i) >= 0; (i)--)
#define range(i, st, en) for (int(i) = (st); (i) <= (en); (i)++)
#define rrange(i, st, en) for (int(i) = (en); (i) >= (st); (i)--)
#define fill(ary, num) memset((ary), (num), sizeof(ary))
string tmp;
bool check(int x, int y)
{
    if (x < 0)
        return false;
    if (y >= tmp.size())
        return false;
    return true;
}
void work()
{
    //string tmp;
    getline(cin, tmp);
    int mx = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        int tmx = 1;
        for (int j = 1;j<=tmp.size();j++){
            if(!check(i-j,i+j)){
                break;
            }
            if(tmp[i-j]==tmp[i+j]){
                tmx+=2;
            }else{
                break;
            }
        }
        mx=max(mx,tmx);
    }
    for (int i = 0; i < tmp.size(); i++)
    {
        int tmx =0;
        for (int j = 1;j<=tmp.size();j++){
            if(!check(i-j+1,i+j)){
                break;
            }
            if(tmp[i-j+1]==tmp[i+j]){
                tmx+=2;
            }else{
                break;
            }
        }
        mx=max(mx,tmx);
    }
    cout<<mx<<endl;
}
int main()
{
   freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}