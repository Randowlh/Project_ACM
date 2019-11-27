#include<cstdio>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
string s;
int n;
int k;
//int maps[2010];
//int fr[20100];
//int af[20100];
//stack<int> st;
int st[100010];
int st2[100010];
int tail;
void swaps(int a,int b){
    //cout<<a+1<<' '<<b+1<<endl;
    st[tail]=a+1;
    st2[tail]=b+1;
    tail++;
    if(a+2<b){
    st[tail]=a+2;
    st2[tail]=b;
    tail++;
    }
    //cout<<a+2<<' '<<b<<endl;
    swap(s[a],s[b]);
    //cout<<s<<endl;
}
int main(){
    int  t;
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>n>>k;
        cin>>s;
        tail=0;
        for(int i=0;i<k-1;i++){
            if(s[i*2]!='('){
                for(int j=i*2+1;j<s.size();j++){
                    if(s[j]=='('){
                        swaps(i*2,j);
                        break;
                    }
                }
            }
            if(s[i*2+1]!=')'){
                for(int j=i*2+2;j<s.size();j++){
                    if(s[j]==')'){
                        swaps(i*2+1,j);
                        break;
                    }
                }
            }
       }
       //cout<<s<<endl;
       for(int i=(k-1)*2;i<((k-1)*2+n)/2;i++){
           if(s[i]!='('){
                for(int j=i+1;j<s.size();j++){
                    if(s[j]=='('){
                        swaps(i,j);
                        break;
                    }
                }
            }
       }
       cout<<tail<<endl;
       for(int i=0;i<tail;i++){
           printf("%d %d\n",st[i],st2[i]);
       }
        //cout<<s<<endl;
    }  
    return 0;
}