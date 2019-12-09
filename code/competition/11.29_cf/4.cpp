#include <cstdio>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
int date[100000];
int map[260];
int find(int x)
{
    if (date[x] == x)
    {
        return x;
    }
    else
    {
        date[x] = find(date[x]);
        return date[x];
    }
}
int merge(int a, int b)
{
    int l = find(a);
    int r = find(b);
    if (l == r)
    {
        return 0;
    }
    else
    {
        date[r] = l;
        return 1;
    }
}
int main(){
    int  n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(date[s[i]]==0){
                date[s[i]]=s[i];
            }
        }
        for(int i=0;i<s.size()-1;i++){
            merge(s[i],s[i+1]);
        }
    }
    int ans=0;
    for(int i='a';i<='z';i++){
        if(date[i]!=0&&map[find(i)]==0){
            ans++;
            map[find(i)]=1;
        }
    }
    cout<<ans<<endl;
}