#include <bits/stdc++.h>
using namespace std;
int main(){
    string tmp;
    cin >> tmp;
    int now = 0;
    for (int i = 0; i < tmp.size();i++){
        if(tmp[i]=='A')
            now++;
        else
            now--;
        if(now<0){
            cout << "Nao" << endl;
            return;
        }
    }
    if(now)
    cout<<"Nao"<<endl;
    else
        cout << "Sim" << endl;
}