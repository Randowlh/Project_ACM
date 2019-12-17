#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int inf =0x7FFFFFFF;
long long mod=1000000007;
char map[100][100];
int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int r,c;
        scanf("%d%d",&r,&c);
        int flag=0;
        int flag1=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>map[i][j];
                if(map[i][j]=='P')
                flag=1;
                else{
                    flag1=1;
                }
            }
        }
        if(flag==0){
            cout<<0<<endl;
            continue;
        }
        if(flag1==0){
            cout<<"MORTAL"<<endl;
            continue;
        }
        flag=1;
        for(int i=0;i<r;i++){
            if(map[i][0]=='P'){
                flag=2;
                break;
            }
        }
        if(flag==1){
            cout<<1<<endl;
            continue;
        }
        /////////////////////////////
        flag=1;
        for(int i=0;i<r;i++){
            if(map[i][c-1]=='P'){
                flag=2;
                break;
            }
        }
        if(flag==1){
            cout<<1<<endl;
            continue;
        }
        ///////////////////////////
        flag=1;
        for(int i=0;i<c;i++){
            if(map[0][i]=='P'){
                flag=2;
                break;
            }
        }
        if(flag==1){
            cout<<1<<endl;
            continue;
        }
        ///////////////////////////
        flag=1;
        for(int i=0;i<c;i++){
            if(map[r-1][i]=='P'){
                flag=2;
                break;
            }
        }
        if(flag==1){
            cout<<1<<endl;
            continue;
        }
        ////////////////////////////
        if(map[0][0]=='A'||map[0][c-1]=='A'||map[r-1][0]=='A'||map[r-1][c-1]=='A'){
            cout<<2<<endl;
            continue;
        }
        ///////////////////////
        flag=0;
        for(int i=0;i<r;i++){
            flag1=0;
            for(int j=0;j<c;j++){
                if(map[i][j]=='P'){
                    flag1=1;
                    break;
                }
            }
            if(flag1==0){
                flag=1;
                break;    
            }
        }
        if(flag==1){
            cout<<2<<endl;
            continue;
        }
        /////////////////////////////
         flag=0;
        for(int i=0;i<c;i++){
            flag1=0;
            for(int j=0;j<r;j++){
                if(map[j][i]=='P'){
                    flag1=1;
                    break;
                }
            }
            if(flag1==0){
                flag=1;
                break;    
            }
        }
        if(flag==1){
            cout<<2<<endl;
            continue;
        }
        /////////////////////////////
        flag=1;
        for(int i=0;i<r;i++){
            if(map[i][0]=='A'){
                flag=2;
                break;
            }
        }
        if(flag==2){
            cout<<3<<endl;
            continue;
        }
        /////////////////////////////
        flag=1;
        for(int i=0;i<r;i++){
            if(map[i][c-1]=='A'){
                flag=2;
                break;
            }
        }
        if(flag==2){
            cout<<3<<endl;
            continue;
        }
        ///////////////////////////
        flag=1;
        for(int i=0;i<c;i++){
            if(map[0][i]=='A'){
                flag=2;
                break;
            }
        }
        if(flag==2){
            cout<<3<<endl;
            continue;
        }
        ///////////////////////////
        flag=1;
        for(int i=0;i<c;i++){
            if(map[r-1][i]=='A'){
                flag=2;
                break;
            }
        }
        if(flag==2){
            cout<<3<<endl;
            continue;
        }
        cout<<4<<endl;
    }
}