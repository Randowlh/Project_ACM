#include<stdio.h>
#include<string.h>
struct note{
  char name[100];
  int val;
} jinhuo[10000],xiaoshou[10000],yuangong[10000],vip[10000];
int tailjinhuo=0,tailxiaoshou=0,tailyuangong=0,zafei=-1,tailvip=0;
void outputvip(){
  printf("请输入您要导出的文件名（请将文件放在程序目录中）\n");
  char output[100];
  scanf("%s",output);
  FILE *fout;
  fout= fopen(output,"wb");
  for(int i=0;i<tailvip;i++){
    fprintf(fout, "%s %d\n",vip[i].name,vip[i].val);
  }
  printf("已写入！\n");
  return;
}
void inhandvip() {
  printf("输入完毕输入q退出\n");
  char tmp[100];
  int tmpv;
  while(1){
    scanf("%s",tmp);
    if(tmp[0]=='q'&&strlen(tmp)==1){
      return;
    }
    scanf("%d",&tmpv);
    strcpy(vip[tailvip].name,tmp);
    vip[tailvip].val=tmpv;
    tailvip++;
  }
  return;
}
void infilevip(){
  char input[100];
  memset(input,0,sizeof(input));
  printf("请输入您要读取的文件名（请将文件放在程序目录中）\n");
  scanf("%s",input);
  FILE *fin;
  fin =fopen(input,"rb");
  char tmp[100];
  int tmpv=0;
  while (fscanf(fin,"%s",tmp)!=EOF) {
    fscanf(fin,"%d",&tmpv);
    strcpy(vip[tailvip].name,tmp);
    vip[tailvip].val=tmpv;
    tailvip++;
  }
  return;
}
void jisuanchunli(){
  int ans=0;
  for(int i=0;i<tailjinhuo;i++){
    ans-=jinhuo[i].val;
  }
  for(int i=0;i<tailyuangong;i++){
    ans-=yuangong[i].val;
  }
  for(int i=0;i<tailxiaoshou;i++){
    ans+=xiaoshou[i].val;
  }
  if(zafei==-1){
    printf("您还未输入杂费支出\n");
    return;
  }
  ans-=zafei;
  printf("总纯利润为：%d\n",ans);
  return ;
}
void jisuanzhichu(){
  int ans=0;
  for(int i=0;i<tailjinhuo;i++){
    ans+=jinhuo[i].val;
  }
  for(int i=0;i<tailyuangong;i++){
    ans+=yuangong[i].val;
  }
  if(zafei==-1){
    printf("您还未输入杂费支出\n");
    return;
  }
  ans+=zafei;
  printf("总支出为：%d\n",ans);
  return;
}
void yuangongpaixu() {
  if(tailyuangong==0){
    printf("您还未输入数据!\n");
    return;
  }
  //在此采用冒泡排序
  for(int i=0;i<tailyuangong-1;i++){
    for(int j=0;j<tailyuangong-i-1;j++){
      if(yuangong[j].val<yuangong[j+1].val){
        int t=yuangong[j].val;
        yuangong[j].val=yuangong[j+1].val;
        yuangong[j+1].val=t;
        char tm[100];
        strcpy(tm,yuangong[j].name);
        strcpy(yuangong[j].name,yuangong[j+1].name);
        strcpy(yuangong[j+1].name,tm);
      }
    }
  }
  for (int i = 0; i < tailjinhuo; i++) {
    printf("%s %d\n",jinhuo[i].name,jinhuo[i].val);
  }
  return;
}
void infileyuangong(){
  char input[100];
  memset(input,0,sizeof(input));
  printf("请输入您要读取的文件名（请将文件放在程序目录中）\n");
  scanf("%s",input);
  FILE *fin;
  fin =fopen(input,"rb");
  char tmp[100];
  int tmpv=0;
  while (fscanf(fin,"%s",tmp)!=EOF) {
    fscanf(fin,"%d",&tmpv);
    strcpy(yuangong[tailyuangong].name,tmp);
    yuangong[tailyuangong].val=tmpv;
    tailyuangong++;
  }
  return;
}
void inhandyuangong(){
  printf("输入完毕输入q退出\n");
  char tmp[100];
  int tmpv;
  while(1){
    scanf("%s",tmp);
    if(tmp[0]=='q'&&strlen(tmp)==1){
      return;
    }
    scanf("%d",&tmpv);
    strcpy(yuangong[tailyuangong].name,tmp);
    yuangong[tailyuangong].val=tmpv;
    tailyuangong++;
  }
  return;
}
void jisuanmaolilv(){
  int ans=0;
  int dev=0;
  for(int i=0;i<tailjinhuo;i++){
    ans-=jinhuo[i].val;
    dev+=jinhuo[i].val;
  }
  for(int i=0;i<tailxiaoshou;i++){
    ans+=xiaoshou[i].val;
  }
  printf("毛利率为：%lf\n",(double)ans/(double)dev);
  return;
}
void jisuanmaoli(){
  int ans=0;
  for(int i=0;i<tailjinhuo;i++){
    ans-=jinhuo[i].val;
  }
  for(int i=0;i<tailxiaoshou;i++){
    ans+=xiaoshou[i].val;
  }
  printf("毛利润为：%d\n",ans);
  return;
}
void infilexiaoshou(){
  char input[100];
  memset(input,0,sizeof(input));
  printf("请输入您要读取的文件名（请将文件放在程序目录中）\n");
  scanf("%s",input);
  FILE *fin;
  fin =fopen(input,"rb");
  char tmp[100];
  int tmpv=0;
  while (fscanf(fin,"%s",tmp)!=EOF) {
    fscanf(fin,"%d",&tmpv);
    strcpy(xiaoshou[tailxiaoshou].name,tmp);
    xiaoshou[tailxiaoshou].val=tmpv;
    tailxiaoshou++;
  }
  return;
}
void inhandxiaoshou() {
  printf("输入完毕输入q退出\n");
  char tmp[100];
  int tmpv;
  while(1){
    scanf("%s",tmp);
    if(tmp[0]=='q'&&strlen(tmp)==1){
      return;
    }
    scanf("%d",&tmpv);
    strcpy(xiaoshou[tailxiaoshou].name,tmp);
    xiaoshou[tailxiaoshou].val=tmpv;
    tailxiaoshou++;
  }
  return;
}
void jinhuopaixu() {
  if(tailjinhuo==0){
    printf("您还未输入数据!\n");
    return;
  }
  //在此采用冒泡排序
  for(int i=0;i<tailjinhuo-1;i++){
    for(int j=0;j<tailjinhuo-i-1;j++){
      if(jinhuo[j].val<jinhuo[j+1].val){
        int t=jinhuo[j].val;
        jinhuo[j].val=jinhuo[j+1].val;
        jinhuo[j+1].val=t;
        char tm[100];
        strcpy(tm,jinhuo[j].name);
        strcpy(jinhuo[j].name,jinhuo[j+1].name);
        strcpy(jinhuo[j+1].name,tm);
      }
    }
  }
  for (int i = 0; i < tailjinhuo; i++) {
    printf("%s %d\n",jinhuo[i].name,jinhuo[i].val);
  }
  return;
}
void inhandjinhuo() {
  printf("输入完毕输入q退出\n");
  char tmp[100];
  int tmpv;
  while(1){
    scanf("%s",tmp);
    if(tmp[0]=='q'&&strlen(tmp)==1){
      return;
    }
    scanf("%d",&tmpv);
    strcpy(jinhuo[tailjinhuo].name,tmp);
    jinhuo[tailjinhuo].val=tmpv;
    tailjinhuo++;
  }
  return;
}
void infilejinhuo(){
  char input[100];
  memset(input,0,sizeof(input));
  printf("请输入您要读取的文件名（请将文件放在程序目录中）\n");
  scanf("%s",input);
  FILE *fin;
  fin =fopen(input,"rb");
  char tmp[100];
  int tmpv=0;
  while (fscanf(fin,"%s",tmp)!=EOF) {
    fscanf(fin,"%d",&tmpv);
    strcpy(jinhuo[tailjinhuo].name,tmp);
    jinhuo[tailjinhuo].val=tmpv;
    tailjinhuo++;
  }
  return;
}
int main(){
  int x;
  printf("欢迎进入超市管理系统\n");
  printf("1.手动输入进货商品信息\n");
  printf("2.从文件读入进货商品信息\n");
  printf("3.将进货数据从高到低进行排序\n");
  printf("4.手动输入物品上月销售清单\n");
  printf("5.从文件读人物品上月销售清单\n");
  printf("6.计算总毛利润\n");
  printf("7.计算总毛利率\n");
  printf("8.手动输入员工工资明细\n");
  printf("9.从文件读入员工工资明细\n");
  printf("10.将员工根据工资排序\n");
  printf("11.输入店租和各种杂费的总和\n");
  printf("12.计算总营业支出\n");
  printf("13.计算总纯营业收入\n");
  printf("14.导入VIP客户名单\n");
  printf("15.输入增加的VIP客户\n");
  printf("16.导出VIP客户名单\n");
  printf("17.退出\n");
  while(1){
    scanf("%d", &x);
    if(x==1){
      inhandjinhuo();
    }
    else
    if(x==2){
      infilejinhuo();
    }
    else
    if(x==3){
      jinhuopaixu();
    }
    else
    if(x==4){
      inhandxiaoshou();
    }
    else
    if(x==5){
      infilexiaoshou();
    }
    else
    if(x==6){
      jisuanmaoli();
    }
    else
    if(x==7){
      jisuanmaolilv();
    }
    else
    if(x==8){
      inhandyuangong();
    }
    else
    if(x==9){
      infileyuangong();
    }
    else
    if(x==10){
      yuangongpaixu();
    }
    else
    if(x==11){
      printf("请输入：\n");
      scanf("%d",&zafei);
    }
    else
    if(x==12){
      jisuanzhichu();
    }
    else
    if(x==13){
      jisuanchunli();
    }
    else
    if(x==14){
      infilevip();
    }
    else
    if(x==15){
      inhandvip();
    }
    else
    if(x==16){
      outputvip();
    }
    else
    if(x==17){
      printf("真的要退出吗?\n");
      printf("请输入Y退出\n");
      char tmp;
      scanf("%c\n",&tmp);
      if(tmp=='y'||tmp=='Y'){
        return 0;
      }
    }
    else{
      printf("错误，请重试\n");
    }
    printf("1.手动输入进货商品信息\n");
    printf("2.从文件读入进货商品信息\n");
    printf("3.将进货数据从高到低进行排序\n");
    printf("4.手动输入物品上月销售清单\n");
    printf("5.从文件读人物品上月销售清单\n");
    printf("6.计算总毛利润\n");
    printf("7.计算总毛利率\n");
    printf("8.手动输入员工工资明细\n");
    printf("9.从文件读入员工工资明细\n");
    printf("10.将员工根据工资排序\n");
    printf("11.输入店租和各种杂费的总和\n");
    printf("12.计算总营业支出\n");
    printf("13.计算总纯营业收入\n");
    printf("14.导入VIP客户名单\n");
    printf("15.输入增加的VIP客户\n");
    printf("16.导出VIP客户名单\n");
    printf("17.退出\n");
  }
}
