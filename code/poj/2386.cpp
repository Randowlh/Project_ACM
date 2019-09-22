#include<cstdio>
struct node
{
    int x;
    int y;
}que[10010];
int head,tail;
int book[110][110];
int map[110][110];
int n,m;
int ans;
char tmp;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;i++){
            scanf("%c",&tmp);
            if(tmp=='W')
                map[i][j]=1;
                else
                {
                    map[i][j]=0;
                }

        }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;i++){
               if(map[i][j]==1&&book[i][j]==0){
                ans++;
                tail=0;
                head=0;
                que[tail].x=i;
                que[tail].y=j;
                book[i][j]=1;
                tail++;
                while(head^tail){
                        if(map[i-1][j+1]==1&&book[i-1][j+1]==0){
                            que[tail].x=i-1;
                            que[tail].y=j+1;
                            tail++;
                            book[i-1][j+1]=1;
                        }
                        if(map[i+1][j+1]==1&&book[i+1][j+1]==0){
                            que[tail].x=i+1;
                            que[tail].y=j+1;
                            tail++;
                            book[i+1][j+1]=1;
                        }
                        if(map[i-1][j-1]==1&&book[i-1][j-1]==0){
                            que[tail].x=i-1;
                            que[tail].y=j-1;
                            tail++;
                            book[i-1][j-1]=1;
                        }
                        if(map[i+1][j-1]==1&&book[i+1][j-1]==0){
                            que[tail].x=i+1;
                            que[tail].y=j-1;
                            tail++;
                            book[i+1][j-1]=1;
                        }
                        if(map[i][j+1]==1&&book[i][j+1]==0){                                                                                           
                            que[tail].x=i;
                                                        que[tail].y=j+1;
                            tail++;
                            book[i][j+1]=1;
                        }
                        if(map[i][j-1]==1&&book[i][j-1]==0){
                            que[tail].x=i;
                            que[tail].y=j-1;
                            tail++;
                            book[i][j-1]=1;
                        }
                        if(map[i+1][j]==1&&book[i+1][j]==0){
                            que[tail].x=i+1;
                            que[tail].y=j;
                            tail++;
                            book[i+1][j]=1;
                        }
                        if(map[i-1][j]==1&&book[i-1][j]==0){
                            que[tail].x=i-1;
                            que[tail].y=j;
                            tail++;
                            book[i-1][j]=1;
                        }
                        head++;
                }
            }
        }
        printf("%d",ans);
        return 0;
}
