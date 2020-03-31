#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n;
        int date[1000];
        cin>>n;
        int flag[110];
        memset(flag,0,sizeof(flag));
        for(int i=0;i<n;i++){
            cin>>date[i];
        }
        for(int i=0;i<n;i++){
            int max=-9999;
            int maxt=-1;
            for(int j=0;j<n-1;j++){
                if(flag[j]==0&&max<date[j]-date[j+1]){
                    max=date[j]-date[j+1];
                    maxt=j;
                }
            }
            if(maxt!=-1&&max>0){
                swap(date[maxt],date[maxt+1]);
                flag[maxt]=1;
            }
        }
        for(int i=0;i<n;i++){
            cout<<date[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}