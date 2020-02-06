#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
struct node
{   
    int rk;
    string name;
    int score;
    bool operator<(node a)
    {
        if (score == a.score)
        {
            return name < a.name;
        }
        return score > a.score;
    }
};
void work()
{
    int n,g,k;
    vector<node> v;
    cin>>n>>g>>k;
    for(int i=0;i<n;i++){
        node x;
        cin>>x.name>>x.score;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int now=v[0].score;
    int rk=1;
    int tol=0;
    int tmp=0;
    for(int i=0;i<n;i++){
        if(v[i].score>=g){
            tol+=50;
        }else if(v[i].score>=60){
            tol+=20;
        }
        if(v[i].score==now){
            v[i].rk=rk;
            tmp++;
        }else{
            now=v[i].score;
            rk+=tmp;
            tmp=1;
            v[i].rk=rk;
        }
    }
    cout<<tol<<endl;
    for(int i=0;i<n;i++){
        if(v[i].rk>k){
            break;
        }
        cout<<v[i].rk<<' '<<v[i].name<<' '<<v[i].score<<endl;
    }
    return;
}
int main()
{
   // freopen("in.txt","r",stdin);
    int t = 1;
   // cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}