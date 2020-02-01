#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
#define each(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define reach(i, n) for (int(i) = n - 1; (i) >= 0; (i)--)
#define range(i, st, en) for (int(i) = (st); (i) <= (en); (i)++)
#define rrange(i, st, en) for (int(i) = (en); (i) >= (st); (i)--)
#define fill(ary, num) memset((ary), (num), sizeof(ary))
vector<int> v[100];
set<int> s[100];
void work(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        int tmp;
        for(int j=0;j<m;j++){
            cin>>tmp;
            v[i].push_back(tmp);
            s[i].insert(tmp);
        }
    }
    int k;
    cin>>k;
    int a,b;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        a--;
        b--;
        int cnt=0;
        set<int> t=s[a];
        for(int i=0;i<v[a].size();i++){
            if(s[b].count(v[a][i])==1&&t.count(v[a][i])==1){
                cnt++;
                t.erase(v[a][i]);
            }
        }
        cnt*=100;
        set<int> w;
        for(int i=0;i<v[a].size();i++){
            w.insert(v[a][i]);
        }
        for(int i=0;i<v[b].size();i++){
            w.insert(v[b][i]);
        }
        printf("%.2f%%\n",(double)cnt/(double)w.size());
    }
    return;
}
int main(){
 //   freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}