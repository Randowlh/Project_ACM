#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
string s;
int n;
int st[1000];
int tail=0;
void sp(int i){
    if(s[i]=='W')
    s[i]='B';
    else
    s[i]='W';
}
int main(){
    cin>>n;
    cin>>s;
    for(int i=1;i<n-1;i++){
        if(s[i]!=s[i-1]){
            sp(i);
            sp(i+1);
            st[tail]=i+1;
            tail++;
        }else{
            continue;
        }
    }
    if(s[n-1]!=s[n-2]){
        if((n-1)%2==0){
            for(int i=0;i<n-1;i+=2){
                st[tail]=i+1;
                tail++;
            }
            cout<<tail<<endl;
            for(int i=0;i<tail;i++){
                printf("%d ",st[i]);
            }
            cout<<endl;
        }else
        cout<<-1<<endl;
    }else{
        cout<<tail<<endl;
        for(int i=0;i<tail;i++){
            printf("%d ",st[i]);
        }
        cout<<endl;
    }
    return 0;

}