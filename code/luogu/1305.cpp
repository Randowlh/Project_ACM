#include<bits/stdc++.h>
using namespace std;
map<char,pair<char,char>> mp;
int ch[100];
string ans;
void dfs(char a){
    ans.push_back(a);
    if(mp[a].first!='*'){
        dfs(mp[a].first);
    }
    if(mp[a].second!='*'){
        dfs(mp[a].second);
    }
    
}
int main(){
    int n;
    cin>>n;
    char a,b,c;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        mp[a]=make_pair(b,c);
        if(b!='*')
        ch[b-'a']++;
        if(c!='*')
        ch[c-'a']++;
    }
    for(int i=0;i<26;i++){
        if(!ch[i]){
            dfs(i+'a');
            break;
        }
    }
    cout<<ans<<endl;
}