#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    string tmp;
    getchar();
    getline(cin, tmp);
    int l;
    if (tmp.size() % n == 0)
    {
        l = tmp.size() / n;
    }
    else
    {
        l = tmp.size() / n + 1;
    }
    for(int i=0;i<n;i++){
        for(int j=l-1;j>=0;j--){
            if(j*n+i<tmp.size()){
                cout<<tmp[j*n+i];
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}