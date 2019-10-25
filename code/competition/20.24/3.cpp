#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int ji[500000];
int ou[500000];
int tail1,tail2;
string tmp1;
int main(){
    int n;
    cin>>n;
    for(int q=0;q<n;q++){
        cin>>tmp1;
        tail1=0;
        tail2=0;
        for(int j=0;j<tmp1.size();j++){
            if((tmp1[j]-'0')%2==0){
                ou[tail2]=tmp1[j]-'0';
                tail2++;
            }else{
                ji[tail1]=tmp1[j]-'0';
                tail1++;
            }
        }
        int fr1=0;
        int fr2=0;
        for(int i=0;i<tmp1.size();i++){
            if(fr1<tail1&&fr2<tail2){
                if(ji[fr1]<ou[fr2]){
                    printf("%d",ji[fr1]);
                    fr1++;
                }else{
                    printf("%d",ou[fr2]);
                    fr2++;
                }
            }else{
                if(fr1<tail1){
                    for(int j=fr1;j<tail1;j++){
                        printf("%d",ji[j]);  
                    }
                    break;
                }else{
                    for(int j=fr2;j<tail2;j++){
                        printf("%d",ou[j]);  
                    }
                    break;
                }
            }
        }
        cout<<endl;
        
    }
}