#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
string a,b;
int main(){
    int n;
    cin>>n;
    for(int q=0;q<n;q++){
        cin>>a>>b;
        if(a<b){
            cout<<a<<endl;
            continue;
        }else{
            //int flag=0;
            for(int i=0;i<a.size()-1;i++){
                int mi=inf;
                int mit=-1;
                for(int j=i+1;j<a.size();j++){
                if(mi>=a[j]){
                    mi=a[j];
                    mit=j;
                }
                }
                if(a[i]>a[mit]){
                 swap(a[i],a[mit]);
                 break;   
                }
            }
            //swap(a[0],a[mit]);
            if(a<b){
                cout<<a<<endl;
            }else{
                cout<<"---"<<endl;
            }
        }
    }
    return 0;
}