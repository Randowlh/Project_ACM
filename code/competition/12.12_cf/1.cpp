#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
int main(){
    string tmp;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>tmp;
        int a[4]={0,0,0,0};
        for(int i=0;i<tmp.size();i++){
            if(tmp[i]=='R'){
                a[0]++;
            }else if(tmp[i]=='L'){
                a[1]++;
            }else if(tmp[i]=='U'){
                a[2]++;
            }else if(tmp[i]=='D'){
                a[3]++;
            }
        }
        int l=min(a[0],a[1]);
        int r=min(a[2],a[3]);
        if(min(l,r)==0){
            if(max(l,r)==0)
            printf("0\n");
            else{
                if(l>0){
                    printf("2\n");
                    printf("RL\n");
                }else{
                    printf("2\n");
                    printf("UD\n");
                }
            }
            continue;
        }else
        cout<<(r+l)*2<<endl;
        for(int i=0;i<l;i++){
            cout<<"R";
        }
        for(int i=0;i<r;i++){
            cout<<"U";
        }
        for(int i=0;i<l;i++){
            cout<<"L";
        }
        for(int i=0;i<r;i++){
            cout<<"D";
        }
        cout<<endl;
    }
    return 0;
}