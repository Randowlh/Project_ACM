#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
struct node
{
    int a, b;
};
void work()
{
    int n;
    cin >> n;
    string a, b, ta, tb;
    cin >> a >> b;
    if(a==b){
        cout<<"Yes"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            for(int j=i+1;j<n;j++){
                swap(a[j],b[i]);
                if(a==b){
                    cout<<"Yes"<<endl;
                    return;
                }
                swap(a[j],b[i]);
            }
            break;
        }
    }
    cout<<"No"<<endl;
    return;
}
int main()
{
      //freopen("in.txt","r",stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}