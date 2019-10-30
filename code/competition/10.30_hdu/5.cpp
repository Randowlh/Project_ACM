#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int date[1000];
int main(){
    int t;
    int n;
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>n;
        int max=-99999;
        for(int i=0;i<n;i++){
            cin>>date[i];
            if(max<date[i]){
                max=date[i];
            }
        }
        if(max!=0)
        for(int i=max;i>0;i--){
            for(int j=0;j<n;j++){
                if(date[j]>=i){
                    cout<<'#';
                }else{
                    cout<<'.';
                }
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++){
            cout<<'@';
        }
        cout<<endl;
    }
}