#include<stdio.h>
#include<string.h>
int st[1000];
char tmp[100][1000];
int st[1000];
int tail;
int tails[1000];
int l;
char pre[1000];
int endpre=0;
char in[100000];
int kuo[1000][100];
int tailsk[1000];
int tailk;
int calc(){

    for(int i=0;i<l;i++){
        if((in[i]<='z'&&in[i]>='a')||(in[i]<='Z'&&in[i]>='A')){
            tmp[tail][tails[tail]]=in[i];
            tails[tail]++;
            pre[endpre]=in[i];
            endpre++;
           // kuo[tail][tailsk[tail]]=tail;
        }
        if(in[i]=='('){
            calc();
        }
        if(in[i]==')'){
            int flag=0;
            for(int i=0;i<tail;i++){
                if(strcmp(pre,tmp[i])){
                    st[i]++;
                    flag=1;
                }
            }
            if(flag==0){
                tail++;
                    strcmp(tmp[tail],pre);
                    st[tail]++;
            }
        }
        if(in[i]<='9'&&in[i]>='0'){
            if(pre[0]==')'){
                    for(int i=0;i<tailsk[tailk];i++){
                        st[kuo[tailk][i]]++;
                    }
            }else{
                int flag=0;
                for(int i=0;i<tail;i++){
                    if(strcmp(pre,tmp[i])){
                        st[i]++;
                        flag=1;
                    }
                }
                if(flag==0){
                    tail++;
                    strcmp(tmp[tail],pre);
                    st[tail]++;
                }
            }
        }
    }
}
int main(){
    gets(in);
    tail=0;
    memset(tails,0,sizeof(tails));
     l=strlen(in);
    
    for(int i=0;i<l;i++){
        if((in[i]<='z'&&in[i]>='a')||(in[i]<='Z'&&in[i]>='A')){
            tmp[tail][tails[tail]]=in[i];
            tails[tail]++;
            pre[endpre]=in[i];
            endpre++;
           // kuo[tail][tailsk[tail]]=tail;
        }
        if(in[i]=='('){
            tail++;
            tailk++;
        }
        if(in[i]==')'){
            int flag=0;
            for(int i=0;i<tail;i++){
                if(strcmp(pre,tmp[i])){
                    st[i]++;
                    flag=1;
                }
            }
            if(flag==0){
                tail++;
                    strcmp(tmp[tail],pre);
                    st[tail]++;
            }
        }
        if(in[i]<='9'&&in[i]>='0'){
            if(pre[0]==')'){
                    for(int i=0;i<tailsk[tailk];i++){
                        st[kuo[tailk][i]]++;
                    }
            }else{
                int flag=0;
                for(int i=0;i<tail;i++){
                    if(strcmp(pre,tmp[i])){
                        st[i]++;
                        flag=1;
                    }
                }
                if(flag==0){
                    tail++;
                    strcmp(tmp[tail],pre);
                    st[tail]++;
                }
            }
        }
    }
}