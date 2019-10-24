#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string a;
int n;
int main(){
    cin>>n;
    for(int k=0;k<n;k++){
        cin>>a;
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(a[i]<='9'&&a[i]>='0'){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}