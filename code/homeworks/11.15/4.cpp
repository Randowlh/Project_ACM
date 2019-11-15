#include<string>
#include<iostream>
using namespace std;
int main(){
    string tmp;
    cin>>tmp;
    int ans=0;
    for(int i=0;i<tmp.size();i++){
        if(tmp[i]>='0'&&tmp[i]<='9'){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}