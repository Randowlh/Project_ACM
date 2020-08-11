int n;
double date[110][110];
bool guass(int n){
    for(int i=1;i<=n;i++){
        int mix=-1;
        for(int j=i;j<=n;j++)
            if(date[j][i]!=0){
                mix=j;break;
            }
        if(mix==-1)
            return false;
        if(mix!=i)
            for(int j=1;j<=n+1;j++)
                swap(date[mix][j],date[i][j]);
        double t=date[i][i];
        for(int j=i;j<=n+1;j++){
            date[i][j]=date[i][j]/t;
        }
        for(int j=1;j<=n;j++){
            if(date[j][i]==0||j==i)
                continue;
            double g=date[j][i]/date[i][i];
            for(int k=1;k<=n+1;k++)
                date[j][k]-=date[i][k]*g;
        }
    }                                                                         
    return true;
}