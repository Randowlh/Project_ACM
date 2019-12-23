#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
    int num;
    int date;
    bool operator<(node a)
    {
        if (this->date == a.date)
            return this->num < a.num;
        else
            return this->date > a.date;
    }
} date[1010];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0;i<n;i++){
        scanf("%d",&date[i].date);
        date[i].num=i+1;
    }
    sort(date,date+n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            if(date[j].num==i){
                printf("%d ",j+1);
                break;
            }
        }
    }
    return 0;
}