#include  <stdio.h>
#include  <string.h>
struct note {
        char name[100];
        int money;
} or[10000],sname[10000],smoney[10000];                                    //储存数据节点 or：输入原数据 sname：按名字排序数据 smoney：按盈利排序数据
int rightm[10000],rightn[10000],tail,tailm=1,tailn=1,headm=1,headn=1;
//之前想要采用基于链表插排的排序算法 但是寻找插入点需要o（n）的复杂度，因此采用用堆排序维护的优先队列。
void insent1(){
        if(tailm==1) {
                tailm++;
                return;
        }
        if(smoney[tailm].money<smoney[headm].money) {
                rightm[tailm]=headm;
                headm=tailm;
                tailm++;
                return;
        }
        int i=headm;
        while(1) {
                if(rightm[i]==0) {
                        rightm[i]=tailm;
                        break;
                }
                if(smoney[tailm].money<smoney[i].money) {
                        rightm[tailm]=rightm[i];
                        rightm[i]=tailm;
                        break;
                }
                i=rightm[i];
        }
        tailm++;
        return;
}               //smoney链表的插入函数
void insent2(){
        if(tailn==1) {
                tailn++;
                return;
        }
        if(strcmp(sname[tailn].name,sname[headn].name)<=0) {
                rightn[tailn]=headn;
                headn=tailn;
                tailn++;
                return;
        }
        int i=headn;
        while(1) {
                if(rightn[i]==0) {
                        rightn[i]=tailn;
                        break;
                }
                if(strcmp(sname[tailn].name,sname[i].name)<=0)  {
                        rightn[tailn]=rightn[i];
                        rightn[i]=tailn;
                        break;
                }
                i=rightn[i];
        }
        tailn++;
        return;
}//sname链表的插入函数
void inputman(){
        printf("please input the recordname and money\n");
        printf("input q to quit\n");2
        while (1) {
                char tmp[100];
                int tmpm=0;
                memset(tmp,0,sizeof(tmp));
                scanf("%s",tmp);
                if(tmp[0]=='q'&&strlen(tmp)==1) {
                        break;
                }else{
                        scanf("%d",&tmpm);
                        or[tail].money=tmpm;
                        sname[tailn].money=tmpm;
                        smoney[tailm].money=tmpm;
                        int i=0
                        for( i=0; i<strlen(tmp); i++) {
                                or[tail].name[i]=tmp[i];
                                sname[tailn].name[i]=tmp[i];
                                smoney[tailm].name[i]=tmp[i];
                        }
                        insent1();
                        insent2();
                        tail++;
                }
        }
        return;
}//屏幕输入函数
void inputbyfile(){
        printf("please input the name of the file\n");
        char tmpf[100];
        scanf("%s",tmpf);
        FILE *ftmp;
        ftmp = fopen(tmpf,"rb");
        while (1) {
                char tmp[100];
                int tmpm=0;
                memset(tmp,0,sizeof(tmp));
                fscanf(ftmp,"%s",tmp);
                if(tmp[0]==EOF) break;
                else{
                        fscanf(ftmp,"%d",&tmpm);
                        or[tail].money=tmpm;
                        sname[tailn].money=tmpm;
                        smoney[tailm].money=tmpm;
                        int i;
                        for( i=0; i<strlen(tmp); i++) {
                                or[tail].name[i]=tmp[i];
                                sname[tailn].name[i]=tmp[i];
                                smoney[tailm].name[i]=tmp[i];
                        }
                        insent1();
                        insent2();
                        tail++;
                }
        }
        return;
}//文件输入函数
void caltol(){
        printf("the total number of record : %d\n",tail );
        int ans=0;
        int i;
        for( i=0; i<tail; i++) {
                ans+=or[i].money;
        }
        printf("the totol money is : %d\n",ans );
        return;
}//计算总和函数
void caleva(){
        printf("the total number of record : %d\n",tail );
        int ans=0;
        int i;
        for( i=0; i<tail; i++) {
                ans+=or[i].money;
        }
        printf("the average  money of each record is : %lf\n",(double)ans/(double)tail );
        return;
}//计算平均数函数
void sortbymoney(){
        int i=headm;
        while(i!=0) {
                printf("%s %d\n",smoney[i].name,smoney[i].money );
                i=rightm[i];
        }
}//按营业额排序
void sortbyname(){
        int i=headn;
        while(i!=0) {
                printf("%s %d\n",sname[i].name,sname[i].money );
                i=rightn[i];
        }
}//按记录名称的字典序排序
void drawgragh(){
        printf("this part of the program haven't finish yet\n" );
}
void saveonfile(){
        printf("1,save date in file in original\n");
        printf("2.save date in file sort by the name of the record\n");
        printf("3.save date in file sort by the amount of money \n");
        printf("please input your choice\n");
        int x=0;
        scanf("%d",&x);
        char ftmp[100];
        memset(ftmp,0,sizeof(ftmp));
        scanf("%s",ftmp);
        FILE *fout;
        fout = fopen(ftmp,"wb");
        if(x==1) {
                int i;
                for( i=0; i<tail; i++) {
                        fprintf(fout, "%s %d\n",or[i].name,or[i].money );
                }
        }else if(x==2)
        {
                int i=headn;
                while(i!=0) {
                        fprintf(fout,"%s %d\n",sname[i].name,sname[i].money );
                        i=rightn[i];
                }
        }else if( x==3) {
                int i=headm;
                while(i!=0) {
                        fprintf(fout,"%s %d\n",smoney[i].name,smoney[i].money );
                        i=rightm[i];
                }
        }else printf("ERROR\n");
        return;
}
int main(){
        int x;
        printf("welcome using the supermaket selling date manange system \033[41;32mpowered by lhy\033[0m\n");
        printf("1.Input date manually\n");
        printf("2.Input date by file\n");
        printf("3.Calculate the total earning\n");
        printf("5.Sort by the amount of money\n");
        printf("6.Sort by the name of the record\n");
        printf("7.Draw a graph of all date\n");
        printf("8.Save date in file\n");
        printf("4.Calculate the average earning of each record\n");
        printf("9.Exit\n");
        printf("please input your choice:\n");
        scanf("%d",&x);
        while(1) {
                if(x==1) inputman();
                else if(x==2) inputbyfile();
                else if(x==3) caltol();
                else if(x==4) caleva();
                else if(x==5) sortbymoney();
                else if(x==6) sortbyname();
                else if(x==7) drawgragh();
                else if(x==8) saveonfile();
                else if(x==9) {printf("Exiting\n"); return 0;}
                else printf("ERROR\n");
                printf("welcome using the supermaket selling date manange system \033[41;32mpowered by lhy\033[0m\n");
                printf("1.Input date manually\n");
                printf("2.Input date by file\n");
                printf("3.Calculate the total earning\n");
                printf("4.Calculate the average earning of each record\n");
                printf("5.Sort by the amount of money\n");
                printf("6.Sort by the name of the record\n");
                printf("7.Draw a graph of all date\n");
                printf("8.Save date in file\n");
                printf("9.Exit\n");
                printf("please input your choice:\n");
                scanf("%d",&x);
        }
        return 0;
}
