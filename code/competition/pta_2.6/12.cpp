#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
double tol = 0;
struct node
{
    vector<int> next;
    int bei;
    double g;
} date[100000];
void work()
{
    int n;
    double r;
    double s;
    cin >> n >> s >> r;
    r = 100 - r;
    r /= 100;
    // cout<<r<<endl;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k == 0)
            cin >> date[i].bei;
        else
        {
            date[i].bei = 1;
            for (int j = 0; j < k; j++)
            {
                int tmp;
                cin >> tmp;
             //   cout<<tmp<<endl;
                date[i].next.push_back(tmp);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<date[i].bei<<' '<<date[i].next.size()<<endl;
    //     for(int j=0;j<date[i].next.size();j++)
    //     cout<<date[i].next[j]<<' ';
    //     cout<<endl;
    // }
    date[0].g = s;
    date[0].bei = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        for (int i = 0; i < date[q.front()].next.size(); i++)
        {
            if (date[date[q.front()].next[i]].bei == 1){
                date[date[q.front()].next[i]].g = date[q.front()].g*r ;
                q.push(date[q.front()].next[i]);
            }
            else
            {
                date[date[q.front()].next[i]].g = date[q.front()].g * date[date[q.front()].next[i]].bei*r;
                tol += date[date[q.front()].next[i]].g;
                 q.push(date[q.front()].next[i]);
            }
            
        }
        q.pop();
    }
    int ans=(int)tol;
    cout<<ans<<endl;
    return;
}
int main()
{
  //  freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}