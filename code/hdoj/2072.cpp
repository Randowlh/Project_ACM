#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
void work(){
    string tmp;
    while(getline(cin,tmp)){
        if(tmp[0]=='#')
        break;
        set<string> s;
        s.clear();
         string temp;
            stringstream ss(tmp);
            while(ss >> temp)     s.insert(temp);
            cout << s.size() << endl;
    }
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    //cin>>t;
    while(t--){
        work();
    }
    return 0;
}