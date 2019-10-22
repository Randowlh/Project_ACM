#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct book	        /*定义结构体类型*/
{
	long num;               /*图书数量*/
	char name[100];         /*图书名称*/
	char aut[100];          /*图书作者*/
	int amount;             /*图书数量*/
}
STU;

void input()		        /*输入函数，完成将键盘输入的图书数据写入磁盘*/
{
	int i,n,x;
	STU a;			/*结构体变量a 用来存放一种书的数据*/
	FILE *fp;
	system("cls");/*清屏*/
	printf("输入菜单");
	printf("\n\tThe operation will clean all the data,continue？ (1)Yes (0)No\n");    /*判断是否继续输入*/
	scanf("%d",&x);
	if(x==0)
	{
		printf("\n\tpress any key to continue");
		getch();
		return;
	}
	if(x==1)
	{
		if((fp=fopen("e:\\file1.txt","wb"))==NULL)   /*以只写方式打开文件*/
		{ printf("error!\n");exit(0); }
		printf("\n\t请输入图书种类数:");
		scanf("%d",&n);		/*输入书的种类数*/
		for(i=0;i<n;i++)			/*以循环的方式输入每种书的数据*/
		{
			printf("\n\t请输入第%d种书的信息:\n",i+1);
			printf("\t编号:");
			scanf("%ld",&a.num);
			printf("\t书名:");
			scanf("%s",a.name);
			printf("\t作者:");
			scanf("%s",a.aut);
			printf("\t图书数量:");
			scanf("%d",&a.amount);
			fwrite(&a,sizeof(STU),1,fp);    /*将数据写入文件*/
		}
		printf("\n\tpress any key to continue...");
		fclose(fp);/*关闭文件*/
	}
}

void list()				                  /*显示函数，完成将文件中的图书数据显示在屏幕上*/
{
	STU a;			/*结构体变量a 用来存放一种书的数据*/
	FILE *fp;
	system("cls");			/*清屏*/
	printf("显示菜单");
	if((fp=fopen("e:\\file1.txt","rb"))==NULL)   /*以只读方式打开文件*/
	{ printf("error!\n");exit(0); }
	printf("\n\n\n\t编号\t书名\t\t\t作者\t\t\t图书数量\n\n");
	while(fread(&a,sizeof(STU),1,fp)!=0)
		printf("\t%ld\t%-20s\t%-20s\t%d\n",a.num,a.name,a.aut,a.amount);
	fclose(fp);         /*关闭文件*/
	printf("\n\tpress any key to continue...");
	getch();			/*程序暂停*/
}

void append()			                  /*追加函数，完成将键盘上输入的图书数据追加到文件中*/
{
	int i,n,x,t=0,f,u;int m[10];
	STU a,b;          /*结构体变量a、b 用来存放一种书的数据*/
	FILE *fp;
	system("cls");			/*清屏*/
	printf("追加菜单\n");
	if((fp=fopen("e:\\file1.txt","rb"))==NULL)    /*以只读方式打开文件*/
	{ printf("error!\n");exit(0); }
		printf("\n\n\n\t编号\t书名\t\t\t作者\t\t\t图书数量\n\n");
	while(fread(&b,sizeof(STU),1,fp)!=0)
	{
		printf("\t%ld\t%-20s\t%-20s\t%d\n",b.num,b.name,b.aut,b.amount);
		m[t]=b.num;      /*将图书编号记录到m[t]中*/
		t++;           	 /*变量t累计文件中图书种数*/
	}
	fclose(fp);         /*关闭文件*/
	if((fp=fopen("e:\\file1.txt","ab"))==NULL)    /*以追加方式打开文件*/
	{ printf("error!\n");exit(0); }
	printf("是否继续追加？ （1）yes   （2）no\n");
	scanf("%d",&u);
	if(u==2)
	{
		printf("press any key to continue.");
		getch();
		return;
	}
	if(u==1)
	{
		printf("\n\n\t请输入追加图书种数:");
		scanf("%d",&n);
		for(i=0;i<n;i++)     /*输入图书信息，循环n次*/
		{
			f=0;
			printf("\t编号:");
			scanf("%ld",&a.num);
			for(x=0;x<t;x++)
				if(a.num==m[x])     /*判断图书编号是否已存在*/
				{
					printf("图书编号已存在\n");
					f=1;
					break;
				}
				if(f==1)
				{
					n++;
					continue;    /*若已存在，则提前结束此次循环，重新执行循环*/
				}
				printf("\t书名:");
				scanf("%s",a.name);
				printf("\t作者:");
				scanf("%s",a.aut);
				printf("\t图书数量:");
				scanf("%d",&a.amount);
				fwrite(&a,sizeof(STU),1,fp);    /*将数据写入文件*/
		}
	}
	fclose(fp);         /*关闭文件*/
}

void sort()			                       /*排序函数，完成对文件中的图书数据按学号排序并显示在屏幕上*/
{
	int i,j,n=0;
	STU a[10],t;		/*结构体数组a 可存放10种图书的数据*/
	FILE *fp;
	system("cls");			/*清屏*/
	printf("排序菜单");
	if((fp=fopen("e:\\file1.txt","rb"))==NULL)    /*以只读方式打开文件*/
	{ printf("error!\n");exit(0); }
	while(fread(&a[n],sizeof(STU),1,fp)!=0)
		n++;			/*变量n累计文件中图书种数*/
	for(i=0;i<n-1;i++)
		for(j=n-1;j>i;j--)
			if(a[j].num<a[j-1].num)    /*比较两种图书编号大小*/
			{  t=a[j];a[j]=a[j-1];a[j-1]=t; }      /*图书数据互换*/
			printf("\n\n\n\t按编号排序:\n");
			printf("\n\t编号\t书名\t\t\t作者\t\t\t图书数量\n\n");
			for(i=0;i<n;i++)
				printf("\t%ld\t%-20s\t%-20s\t%d\n",a[i].num,a[i].name,a[i].aut,a[i].amount);
			fclose(fp);         /*关闭文件*/
			printf("\n\tpress any key to continue...");
			getch();			/*程序暂停*/
}

void modify()                                 /*修改函数，修改除编号外的图书数据*/
{
	long n=0;int f=0;int i,m,j,num;
	STU a[10];		/*结构体数组a 可存放10种图书的数据*/
	FILE *fp;
	system("cls");			/*清屏*/
	printf("修改菜单");
	if((fp=fopen("e:\\file1.txt","rb"))==NULL)   /*以只读方式打开文件*/
	{ printf("error!\n");exit(0); }
	while(fread(&a[n],sizeof(STU),1,fp)!=0)
		n++;			/*变量n累计文件中图书种数*/
	printf("\n\n\n\t编号\t书名\t\t\t作者\t\t\t图书数量\n\n");
	for(i=0;i<n;i++)         /*将已有数据输出在屏幕上*/
		printf("\t%ld\t%-20s\t%-20s\t%d\n",a[i].num,a[i].name,a[i].aut,a[i].amount);
	printf("\n\t请输入图书编号:");
	scanf("%d",&num);
	{
		for(i=0;i<n;i++)     /*寻找与输入编号符合的图书编号*/
		{
			if(a[i].num==num)
			{
				printf("\n\t已找到，如下:\n");
				printf("\n\t编号\t书名\t\t\t作者\t\t\t图书数量\n\n");
				printf("\t%ld\t%-20s\t%-20s\t%d\n",a[i].num,a[i].name,a[i].aut,a[i].amount);
				f=1;
				break;
			}
		}
	}
	if(f==0)
	{
		{printf("\n\t对不起，没找到\n");}
		fclose(fp);         /*关闭文件*/
		printf("\n\tpress any key to continue...");
		getch();			/*程序暂停*/
	}
	fclose(fp);         /*关闭文件*/
	{
		printf("\n\t是否修改该图书数据 (1-修改，0-不修改) ?\n");
		scanf("%d",&m);
		if(m==0)
		{
			printf("\n\tpress any key to continue...");
			getch();			/*程序暂停*/
		}
		if(m==1)
		{
			fp=fopen("e:\\file1.txt","wb");
			printf("\t书名:");
			scanf("%s",a[i].name);
			printf("\t作者:");
			scanf("%s",a[i].aut);
			printf("\t图书数量:");
			scanf("%d",&a[i].amount);
			for(j=0;j<n;j++)
			fwrite(&a[j],sizeof(STU),1,fp);     /*将数据写入文件*/
			fclose(fp);                         /*关闭文件*/
			printf("\n修改完成!\n\n");
			printf("\n\tpress any key to continue...");
			getch();			/*程序暂停*/
		}
	}
}

void del()                                 /*删除函数，删除图书数据*/
{
	int num,i,j,u,x;int n=0;int f=0;
	STU a[10];			/*结构体变量a 用来存放一种书的数据*/
	FILE *fp;
	system("cls");			/*清屏*/
	printf("删除菜单");
	if((fp=fopen("e:\\file1.txt","rb"))==NULL)    /*以只读方式打开文件*/
	{ printf("error!\n");exit(0); }
	printf("\n\n\n\t编号\t书名\t\t\t作者\t\t\t图书数量\n\n");
	while(fread(&a[n],sizeof(STU),1,fp)!=0)
	{
		printf("\t%ld\t%-20s\t%-20s\t%d\n",a[n].num,a[n].name,a[n].aut,a[n].amount);
	    n++;
	}
	fclose(fp);                       /*关闭文件*/
	printf("是否删除继续删除(1-删除，0-不删除)?\n");
	scanf("%d",&x);
	if(x==0)
	{	printf("press any key to continue.");
		getch();
		return;
	}
	if(x==1)
	{
		printf("\n\t输入要删除的图书编号：");
		scanf("%d",&num);
		for(i=0;i<n;i++)
		{
			if(a[i].num==num)       /*判断编号是否存在*/
			{
				f=1;
				break;              /*若已存在，结束循环*/
			}
		}
		if(f==0)
		{
			printf("编号已存在!");
			getch();
			return;
		}
		for(j=i;j<n;j++)      /*从a[i]位置开始依次向前覆盖数据*/
		{
			a[j].num=a[j+1].num;
			strcpy(a[j].name,a[j+1].name);
			strcpy(a[j].aut,a[j+1].aut);
			a[j].amount=a[j+1].amount;
		}
		fp=fopen("e:\\file1.txt","wb");        /*以只写方式打开文件*/
		for(u=0;u<n-1;u++)                     /*图书数量减1*/
			fwrite(&a[u],sizeof(STU),1,fp);    /*将数组a[u]写入文件*/
		fclose(fp);         /*关闭文件*/
		printf("删除成功！");
		printf("\n\tpress any key to continue...");
		getch();			/*程序暂停*/
	}
}

void search_num()                        /*查询图书名称函数，按图书名称查询*/
{
	long n=0;int f=0;int i,num;
	STU a[10];		/*结构体数组a 可存放10种图书的数据*/
	FILE *fp;
	system("cls");			/*清屏*/
	if((fp=fopen("e:\\file1.txt","rb"))==NULL)   /*以只读方式打开文件*/
	{ printf("error!\n");exit(0); }
	printf("\n\t请输入图书编号:");
	scanf("%d",&num);
	while(fread(&a[n],sizeof(STU),1,fp)!=0)
		n++;			/*变量n累计文件中图书种数*/
	{
		for(i=0;i<n;i++)     /*寻找与输入编号符合的图书编号*/
		{
			if(a[i].num==num)
			{
				printf("\n\t已找到，如下:\n");
				printf("\n\n\n\t编号\t书名\t\t\t作者\t\t\t图书数量\n\n");
				printf("\t%ld\t%-20s\t%-20s\t%d\n",a[i].num,a[i].name,a[i].aut,a[i].amount);
				f=1;
				break;
			}
		}
	}
	if(f==0)
		{printf("\n\t对不起，没找到\n");}
	fclose(fp);         /*关闭文件*/
	printf("\n\tpress any key to continue...");
	getch();			/*程序暂停*/
}

void search_name()                        /*查询图书名称函数，按图书名称查询*/
{
	char s[10];int f=0;
	STU a;		/*结构体数组a 可存放1种图书的数据*/
	FILE *fp;
	system("cls");			/*清屏*/
	if((fp=fopen("e:\\file1.txt","rb"))==NULL)   /*以只读方式打开文件*/
	{ printf("error!\n");exit(0); }
	printf("\n\t请输入图书名称:");
	scanf("%s",s);
	while(fread(&a,sizeof(STU),1,fp)!=0)
	{
		if(strcmp(a.name,s)==0)     /*寻找与输入名称符合的图书名称*/
		{
			printf("\n\t已找到，如下:\n");
			printf("\n\n\n\t编号\t书名\t\t\t作者\t\t\t图书数量\n\n");
			printf("\t%ld\t%-20s\t%-20s\t%d\n",a.num,a.name,a.aut,a.amount);
			f=1;
			break;
		}
	else
		continue;      /*若没找到，跳出循环*/
	}
	if(f==0)
	   printf("\n\t对不起，没找到\n");
	fclose(fp);         /*关闭文件*/
	printf("\n\tpress any key to continue...");
	getch();			/*程序暂停*/
}

void search_author()                        /*查询作者函数，按作者查询*/
{
	char s[10];int f=0;
	STU a;		/*结构体数组a 可存放1种图书的数据*/
	FILE *fp;
	system("cls");			/*清屏*/
	if((fp=fopen("e:\\file1.txt","rb"))==NULL)    /*以只读方式打开文件*/
	{ printf("error!\n");exit(0); }
	printf("\n\t请输入作者:");
	scanf("%s",s);
	while(fread(&a,sizeof(STU),1,fp)!=0)
	{
		if(strcmp(a.aut,s)==0)     /*寻找与输入作者符合的图书作者*/
		{
			printf("\n\t已找到，如下:\n");
			printf("\n\n\n\t编号\t书名\t\t\t作者\t\t\t图书数量\n\n");
			printf("\t%ld\t%-20s\t%-20s\t%d\n",a.num,a.name,a.aut,a.amount);
			f=1;
			break;
		}
	else
		continue;      /*若没找到，跳出循环*/
	}
	if(f==0)
	   printf("\n\t对不起，没找到\n");
	fclose(fp);         /*关闭文件*/
	printf("\n\tpress any key to continue...");
	getch();			/*程序暂停*/
}

void search()           /*查询函数，完成程序菜单的显示并调用以上各函数*/
{
	int a;
	do
	{
		system("cls");	/*清屏*/
		printf("\n\n\n\n\n\t\t查询菜单\n");	/*显示程序菜单*/
		printf("\t\t*******************************\n");
		printf("\t\t\t1----按图书编号查询\n");
		printf("\t\t\t2----按图书名称查询\n");
		printf("\t\t\t3----按作者查询\n");
		printf("\t\t\t0----返回主菜单\n");
		printf("\t\t*******************************\n");
		printf("\t\t请选择:");
		scanf("%d",&a);
		switch(a)
		{
		case 1:search_num();break;	        /*调用查询图书编号函数*/
		case 2:search_name();break;		    /*调用查询图书名称函数*/
		case 3:search_author();break;       /*调用查询图书作者函数*/
		case 0:return;                      /*返回主菜单*/
		}
	}
	while(a!=0);
	return;
}

main()		       	       /*主函数，完成程序菜单的显示并调用以上各函数*/
{
	system("color f2");    /*更改界面颜色（白底绿字）*/
	int a;
	do
	{
		system("cls");	/*清屏*/
		printf("\n\n\n\n\n\t\t图书管理系统\n");	/*显示程序菜单*/
		printf("\t\t*******************************\n");
		printf("\t\t\t1----输入\n");
		printf("\t\t\t2----显示\n");
		printf("\t\t\t3----追加\n");
		printf("\t\t\t4----排序\n");
		printf("\t\t\t5----查询\n");
		printf("\t\t\t6----修改\n");
		printf("\t\t\t7----删除\n");
		printf("\t\t\t0----退出\n");
		printf("\t\t*******************************\n");
		printf("\t\t请选择:");
		scanf("%d",&a);
		switch(a)
		{
		case 1:input();break;	  /*调用输入函数*/
	  	case 2:list();break;	  /*调用显示函数*/
	  	case 3:append();break;	  /*调用追加函数*/
	  	case 4:sort();break;	  /*调用排序函数*/
		case 5:search();break;    /*调用查询函数*/
		case 6:modify();break;    /*调用修改函数*/
		case 7:del();break;       /*调用删除函数*/
	  	case 0:exit(0);			  /*结束程序的运行*/
		}
	}
	while(a!=0);
	return a;
}
