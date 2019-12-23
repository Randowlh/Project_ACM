#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        cout<<6;
        for(int j=a.size()-5;j<a.size();j++){
            cout<<a[j];
        }
        cout<<endl;
    }
    return 0;
}