#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
void work()
{
    double tmp;
    vector<double> a, b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    vector<int> yu;
    for(int i=0;i<a.size()-b.size();i++){
        double chu=a[i]/b[0];
        yu.push_back(chu);
        a[i]=0;
        for(int j=1;j<b.size();j++){
            a[i+j]-=b[j]*chu;
        }
    }
    int fl=1;
    for(int i=0;i<b.size();i++){
        if(a[a.size()-b.size()+i]>b[i]){
            break;
        }
        if(a[a.size()-b.size()+i]<b[i]){
            fl=0;
            break;
        }
    }
    if(fl){
        double chu=a[a.size()-b.size()]/b[0];
        yu.push_back(chu);
        a[a.size()-b.size()]=0;
        for(int j=1;j<b.size();j++){
            a[a.size()-b.size()+j]-=b[j]*chu;
        }
    }
    for(int i=a.size()-b.size();i<a.size();i++){
        printf("%.1f");
    }
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