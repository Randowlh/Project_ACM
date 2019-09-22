#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct node
{
    char word[110];
    int val;
} date[1010];
int book[1000];
int flag;
bool cmp(struct node a,struct node b){
    return a.val > b.val;
}
int main(){
    int round;
    char biao[10][4]={
    {0,0,0,0},    
    {'a','b','c',' '},
    {'d','e','f',' '},
    {'g','h','i',' '},
    {'j','k','l',' '},
    {'m','n','o',' '},
    {'p','q','r','s'},
    {'t','u','v',' '},
    {'w','x','y','z'}};
    char tmp[100];
    int n;
    int tail;
    scanf("%d", &round);
    for(int q=1;q<=round;q++){
        printf("Scenario #%d:\n",q);
        scanf("%d",&tail);
        for(int i= 0;i < tail; i++){
            scanf("%s %d",date[i].word,&date[i].val);
        }
        sort(date,date+tail,cmp);
        scanf("%d",&n);
        for(int i=0;i < n;i++){
            int weishu=0;
            while(scanf("%s",tmp)){
                for(int j=0;j<tail;j++){
                    if(book[j]==0&&date[j].word[weishu]!=biao[(tmp[weishu]-'0')][0]&&date[j].word[weishu]!=biao[(tmp-'0')][1]&&date[j].word[weishu]!=biao[(tmp-'0')][2]&&date[j].word[weishu]!=biao[(tmp-'0')][3]){
                        book[j]=1;
                    }
                }
                for(int j=0;j<tail;j++){
                    if(book[j]==0){
                        for(int i=0;i<weishu;i++)
                        printf("%c",date[j].word[i]);
                        printf("\n");
                   }
                }
                weishu++;
           }
           memset(book,0,sizeof(book));
           
        }
    }
    return 0;
}