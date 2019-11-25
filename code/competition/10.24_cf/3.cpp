#include<cstdio>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
string s;
int n;
int k;
int maps[2010];
int fr[20100];
int af[20100];
stack<int> st;
int tail;
int main(){
    int  t;
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>n>>k;
        cin>>s;
        tail=0;
        for(int i=0;i<n;i++){
            maps[i]=0;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='(' ){
                st.push(i);
            }
            if(s[i]==')'&& !st.empty()){
            maps[st.top()]=1;
            maps[i]=1;
            st.pop();
            }
        }
        while(!st.empty()){
            st.pop();
        }
        //cout<<"yes"<<endl;
        for(int i=0;i<n;i++){
            if(maps[i]==0&&s[i]==')'){
                st.push(i);
                //cout<<"yes"<<endl;
            }else
            if(maps[i]==0&&s[i]=='('){
                fr[tail]=st.top();
               st.pop();
                af[tail]=i;
                tail++;
            }
        }
       // cout<<"yes"<<endl;
        for(int i=0;i<tail;i++){
            swap(s[fr[i]],s[af[i]]);
        }
       // cout<<s<<endl;
       
    }
    return 0;
}