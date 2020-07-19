#include<bits/stdc++.h>
using namespace std;
string ck = "abacaba";
void work(){
    string t;
    int n;
    cin >> n >> t;
    int cnt = 0;
    for (int i = 0; i < t.size(); i++)
        {
            for (int j = 0; j < ck.size() && i + j < t.size(); j++)
            {
                if (t[i + j] != ck[j])
                    break;
                if (j == ck.size() - 1 && ck[j] == t[i + j])
                {
                    cnt++;//一开始扫一遍并计数
                }
            }
        }
    if(cnt>1){
        cout << "No" << endl;//>1直接NO
        return;
    }
    if (cnt == 1){
        cout << "Yes" << endl;//==1YES
        for (int i = 0; i < t.size();i++){
            if(t[i]=='?')
                cout << "z";
            else
                cout << t[i];
        }
        cout << endl;
        return;
    }
    cnt=-1;
    for (int i = 0; i < t.size();i++){
        for (int j = 0; j < ck.size()&&i+j<t.size();j++){
            if(t[i+j]!=ck[j]&&t[i+j]!='?')
                break;
            if (j == ck.size()-1&&(ck[j]==t[i+j]||t[i+j]=='?')){
                cnt=i;
                break;
            }
        }
    }
    if(cnt==-1){
        cout << "No" << endl;
        return;
    }else {
        for (int i = 0; i < ck.size();i++){
            t[cnt + i] = ck[i];
        }
          cout << "Yes" << endl;
        for (int i = 0; i < t.size();i++){
            if(t[i]=='?')
                cout << "z";
            else
                cout << t[i];
        }
        cout << endl;
        return;
    }
}
int main(){
  //  freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        work();
    }
    return 0;
}