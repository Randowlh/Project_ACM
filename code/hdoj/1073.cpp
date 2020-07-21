#include<bits/stdc++.h>
using namespace std;
string cst="START";
void work(){
    string a, b;
    string tt;
    char tmp;
    int flag=0;
    while(cin>>tt){
        if(tt=="START")
        break;
    }
    while (tmp=getchar()){
        if(tmp=='D'&&a.size()>=2&&a[a.size()-1]=='N'&&a[a.size()-2]=='E')
            break;
        a += tmp;
    }
    while(cin>>tt){
        if(tt=="START")
        break;
        if(tt.size()>=5){
            int f = 0;
            for (int i = 4; i >= 0;i--)
            if(tt[tt.size()-4+i-1]==tt[tt.size()-])
        }
    }
    while(tmp=getchar()){
       if(tmp=='D'&&b.size()>=2&&b[b.size()-1]=='N'&&b[b.size()-2]=='E')
            break;
        b += tmp;
    }
    if(a==b){
        cout << "Accepted" << endl;
        return;
    }
    string ta, tb;
    for (int i = 0;i<a.size();i++){
        if(a[i]!='\t'&&a[i]!='\n'&&a[i]!=' '){
            ta.push_back(a[i]);
        }
    }
    for (int i = 0;i<b.size(); i++){
        if(b[i]!='\n'&&b[i]!='\t'&&b[i]!=' '){
            tb.push_back(b[i]);
        }
    }
    if(ta==tb){
        cout << "Presentation Error" << endl;
    }else
        cout << "Wrong Answer" << endl;
}
int main(){
 // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
   // getchar();
    while(t--)
        work();
}