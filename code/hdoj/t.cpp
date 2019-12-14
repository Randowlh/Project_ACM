#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;
struct node
{   
    double date;
    int num;
    char name[1000];
    bool operator<(node a){
        return this->date>a.date;
    }
    /* data */
}date[100];

int main(){
    for(int i=0;i<10;i++){
        scanf("%s %lf",date[i].name,&date[i].date);
        date[i].num=i+1;
    }
    sort(date,date+10);
    for(int i=0;i<10;i++){
        cout<<date[i].num<<' '<<date[i].name<<' '<<date[i].date<<endl;
    }
    return 0;
}