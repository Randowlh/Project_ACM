#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
vector<int> ans[1000];
void work()
{
    int n;
    vector<int> v;
    vector<int> tv;
    int tmp;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp * 10);
        tv.push_back(tmp);
    }
    int cnt=1;
    int mix=0;
    int fl=0;
    vector<int> dui;
    while (true)
    {   
         fl = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > 0)
            {
                fl++;
                v[i]--;
                mix=i;
                ans[i].push_back(cnt);
                cnt++;
                dui.push_back(i);
            }
        }
      //  cout<<fl<<endl;
        if(fl<=1){
            break;
        }
    }
    if(dui[dui.size()-2]==mix){
       // cout<<ans[mix][ans[mix].size()-1]<<endl;
    ans[mix][ans[mix].size()-1]++;
    cnt++;
    }
    cnt++;
    if(fl==1)
    while(v[mix]!=0){
        v[mix]--;
        ans[mix].push_back(cnt);
        cnt+=2;
    }
    for(int i=0;i<n;i++){
        cout<<"#"<<i+1<<endl;
        for(int j=0;j<tv[i];j++){
            for(int k=0;k<9;k++){
                cout<<ans[i][j*10+k]<<' ';
            }
            cout<<ans[i][j*10+9]<<endl;
        }
    }
    return ;
}
int main()
{
   // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}