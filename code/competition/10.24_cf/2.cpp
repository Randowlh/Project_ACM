#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int que[100010];
int head,tail;
int ans[100010];
int tmp[100010];
int taila;
int main(){
    int t;
    int n;
    cin>>t;
    for(int q=0;q<t;q++){
        head=0;
        tail=0;
        taila=0;
        cin>>n;
        int now=0;
        //int tmp;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp[i]);
        }
        int flag=0;
        for(int i=0;i<n;i++){
            if((tmp[i]<1&&tmp[i]>n)||tmp[i]<now){
                cout<<-1<<endl;
                flag=1;
                break;
            }
            if(tmp[i]!=now){
                ans[taila]=tmp[i];
                taila++;
                for(int j=now+1;j<tmp[i];j++){
                    que[tail]=j;
                    //cout<<que[tail]<<"rfsfsa"<<endl;
                    tail++;
                }
                now=tmp[i];
            }else{
                ans[taila]=que[head];
                taila++;
                head++;
                if(head>tail){
                    cout<<-1<<endl;
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){
        for(int i=0;i<taila;i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
        }
    }
    return 0;
}