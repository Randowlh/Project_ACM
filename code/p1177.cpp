#include <cstdio>
int ar[100000];
void qsort(int first,int end){
        if(first>=end)
                return;
        int i=first+1;
        int j=end;
        int key=ar[first];
        while (true) {

                while(ar[i]<key) {
                        i++;
                        if(i==end)
                                break;
                }
                while(ar[j]>key) {
                        j--;
                        if(j==first)
                                break;
                }
                if(i>=j)
                        break;
                int tmp =ar[i];
                ar[i]=ar[j];
                ar[j]=tmp;
        }
        int tmp =ar[first];
        ar[first]=ar[j];
        ar[j]=tmp;
        qsort(first,j-1);
        qsort(j+1,end);
        return;
}
int main(){
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; i++) {
                scanf("%d",&ar[i] );
        }
        qsort(0,n-1);
        for (int i = 0; i < n; i++) {
                printf("%d ",ar[i] );
        }
        return 0;
}
