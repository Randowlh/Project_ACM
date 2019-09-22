#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
string a,b;
int main(){
    cin>>a;
    b=a;
    sort(a.begin(),a.begin()+a.size() ,greater<int>() );
    if(a[a.size()-1]<b[b.size()-1]){
        printf("%c",a[a.size()-1]-b[b.size()-1]+10+'0');
    }else
    {
        printf("%c",a[a.size()-1]-b[b.size()-1]+'0');
            }
    return 0;

}