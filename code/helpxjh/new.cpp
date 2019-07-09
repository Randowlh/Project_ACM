#include <bits/stdc++.h>
#define PLAYERCOUNT 3
#define CARDSCOUNT 54
#define CURRENTPLAYER 0
#define VALUECOUNT 17
#define ERROR -1

using namespace std;
const char toFigure[]="34567890JQKA 2YZ";
enum COLOR{  //花色显示ASCII: 3~6
    eHEART=3,//红桃
    eDIAMOND,//方片
    eCLUB,   //草花
    eSPADE   //黑桃
};

class Card;
class CardsType;
class CardGroup;
class Player;
class Landlords;
class LastCards;
bool makeChoice(string tip);
bool cmp(Card* a,Card* b);

class Card{
  public:
    char figure;
    COLOR color;
    int value;
    Card(char _figure,COLOR _color){
        figure=_figure;
        color=_color;
        value=calValue();
    }
    int calValue(){//计算大小
        for(int i=0;toFigure[i];i++){
            if(toFigure[i]==figure){
                return i;
            }
        }
        return ERROR;
    }
    void print(){
        assert(value!=ERROR);
        if(figure=='Z'){
            cout<<"ZZ";
        }else if(figure=='Y'){
            cout<<"YY";
        }else{
            cout<<figure<<(char)color;
        }
        cout<<' ';
    }
};

class CardsType{
  public:
    //为了规范查找对应牌的方法
    //统一为3个参数cnt1、isContinuous、cnt2
    int typeId;
    string typeStr;
    int cnt1,cnt2;
    bool isContinuous;
    CardsType(){
        typeId=ERROR;
    }
    bool operator ==(const CardsType& other)const{
        return this->typeId==other.typeId;
    }
    void init(char* _typeStr,int _typeId,int _cnt1,bool _isContinuous,int _cnt2){
        cnt1=_cnt1;
        isContinuous=_isContinuous;
        cnt2=_cnt2;
        typeStr=_typeStr;
        typeId=_typeId;
    }
};

class CardGroup{
  public:
    vector<Card*> cards;
    CardsType type;
    void calType(){
        int i,n=cards.size();
        //init(typeStr,typeId,cnt1,isContinuous,cnt2)
        if(n==0){
            type.init("不出",14,0,0,0);
            return;
        }
        if(n==2&&cards[0]->value==15&&cards[1]->value==14){
            type.init("王炸",0,0,0,0);
            return;
        }
        //统计同点数牌有多少张
        int cntFlag[VALUECOUNT]={0};
        for(i=0;i<n;i++){
            cntFlag[cards[i]->value]++;
        }
        //统计点数最多和最少的牌
        int maxCnt=0,minCnt=4;
        for(i=0;i<VALUECOUNT;i++){
            if(maxCnt<cntFlag[i]){
               maxCnt=cntFlag[i];
            }
            if(cntFlag[i]&&minCnt>cntFlag[i]){
               minCnt=cntFlag[i];
            }
        }
        if(n==4&&maxCnt==4){
            type.init("炸dan",1,4,0,0);
            return;
        }
        if(n==1){
            type.init("单牌",2,1,0,0);
            return;
        }
        if(n==2&&maxCnt==2){
            type.init("对子",3,2,0,0);
            return;
        }
        if(n==3&&maxCnt==3){
            type.init("三张 ",4,3,0,0);
            return;
        }
        if(n==4&&maxCnt==3){
            type.init("三带一",5,3,0,1);
            return;
        }
        if(n==5&&maxCnt==3&&minCnt==2){
            type.init("三带一对",6,3,0,2);
            return;
        }
        if(n==6&&maxCnt==4){
            type.init("四带二",7,4,0,1);
            return;
        }
        if(n==8&&maxCnt==4&&minCnt==2){
            type.init("四带二",8,4,0,2);
            return;
        }
        if(n>=5&&maxCnt==1&&cards[0]->value==cards[n-1]->value+n-1){
            type.init("顺子",9,1,1,0);
            return;
        }
        if(n>=6&&maxCnt==2&&minCnt==2&&cards[0]->value==cards[n-1]->value+n/2-1){
            type.init("连对",10,2,1,0);
            return;
        }
        int fjCnt;//统计连续且大于3三张的牌
        for(i=0;i<VALUECOUNT &&cntFlag[i]<3;i++);
        for(fjCnt=0;i<VALUECOUNT &&cntFlag[i]>=3;i++,fjCnt++);
        if(fjCnt>1){
            if(n==fjCnt*3)
                type.init("飞机",11,3,1,0);
            else if(n==fjCnt*4)
                type.init("飞机",12,3,1,1);
            else if(n==fjCnt*5&&minCnt==2)
                type.init("飞机",13,3,1,2);
        }
    }
    void init(string inputStr, vector<Card*> &cardsHolded){
        this->cards.clear();
        //不出
        if(inputStr=="N"){
            this->calType();
            return;
        }
        int i,j;
        //输入合法性判断
        for(i=0;i<inputStr.size();i++){
            bool find=false;
            for(j=0;toFigure[j];j++){
                if(inputStr[i]==toFigure[j]){
                    find=true;
                    break;
                }
            }
            if(find==false){
                //输入字符不在toFigure中
                return;
            }
        }
        //查找手中有没有这些牌
        int visitFlag[20]={0};
        for(i=0;i<inputStr.size();i++){
            Card *find=NULL;
            for(j=0;j<cardsHolded.size();j++){
                if(!visitFlag[j]&&cardsHolded[j]->figure==inputStr[i]){
                    visitFlag[j]=1;
                    find=cardsHolded[j];
                    break;
                }
            }
            if(find){
                this->cards.push_back(find);
            }else{
                cout<<inputStr[i];
                cout<<"没有找到\t";
                this->cards.clear();
                return;
            }
        }//end for(i=0;i<inputStr.size();i++)
        this->arrange();
    }
    void init(vector<Card*> newCards){
        this->cards=newCards;
        this->arrange();
    }
    bool isCanBeat(CardGroup &cardGroup){
        if(cardGroup.type.typeStr=="王炸"){
            return false;
        }else if(this->type.typeStr=="王炸"){
            return true;
        }else if(cardGroup.type==this->type &&this->type.typeStr=="炸dan"){
            return value()>cardGroup.value();
        }else if(cardGroup.type.typeStr=="炸dan"){
            return false;
        }else if(this->type.typeStr=="炸dan"){
            return true;
        }else if(cardGroup.type==this->type &&this->cards.size()==cardGroup.cards.size()){
            return this->value()>cardGroup.value();
        }else{
            return false;
        }
    }
    int value(){
        //计算牌组权值
        int i;
        if(type.typeStr=="三带一"||type.typeStr=="三带一对"||type.typeStr=="飞机"){
            for(i=2;i<cards.size();i++){
                if(cards[i]->value==cards[i-2]->value){
                    return cards[i]->value;
                }
            }
        }
        if(type.typeStr=="四带二"){
            for(i=3;i<cards.size();i++){
                if(cards[i]->value==cards[i-3]->value){
                    return cards[i]->value;
                }
            }
        }
        return cards[0]->value;
    }
    void arrange(){
        //整理：排序、计算类型
        sort(this->cards.begin(),this->cards.end(),cmp);
        this->calType();
    }
};
class LastCards{
    static LastCards *lastCards;
  public:
    Player *player;
    CardGroup cardGroup;
    static LastCards* inst(){//单例模式
        if(lastCards==NULL){
            lastCards=new LastCards();
        }
        return lastCards;
    }
    vector<Card*> findCanBeatFrom(vector<Card*> &cardsHolded){
        //查找能打得过的牌
        int i,j,k,n=cardsHolded.size(),m=cardGroup.cards.size();
        string typeStr=cardGroup.type.typeStr;
        vector<Card*> ret;
        if(typeStr=="王炸"||n<m){
            //打不过，返回空数组
            return ret;
        }
        int value=cardGroup.value();
        //统计各点牌出现的次数
        int cntFlag[VALUECOUNT]={0};
        for(i=0;i<n;i++){
            cntFlag[cardsHolded[i]->value]++;
        }
        int continuousCount=1;
        if(cardGroup.type.isContinuous){
            continuousCount=m/(cardGroup.type.cnt1+cardGroup.type.cnt2);
        }
        bool findFirstFigure;
        //cout<<"continuousCount="<<continuousCount<<endl;
        for(i=value+1;i<VALUECOUNT;i++){
            findFirstFigure=true;
            for(j=0;j<continuousCount;j++){
                if(cntFlag[i-j]<cardGroup.type.cnt1){
                    findFirstFigure=false;
                    break;
                }
            }
            if(findFirstFigure){
                ret.clear();
                int firstFigure=i;
                //cout<<"查找"<<cardGroup.type.cnt1<<"个"<<firstFigure+3<<endl;
                for(k=0,j=0;k<cardsHolded.size() &&j<continuousCount;k++){
                    if(cardsHolded[k]->value==firstFigure-j){
                        for(int kk=0;j>=0&&kk<cardGroup.type.cnt1;kk++){
                            ret.push_back(cardsHolded[k+kk]);
                        }
                        j++;
                    }
                }
                if(cardGroup.type.cnt2>0){
                    int SecondFigures[5];
                    int SecondCount=continuousCount;
                    if(cardGroup.type.typeStr=="四带二")
                        SecondCount=2;
                    bool findSecondFigure=true;
                    for(j=0,k=-1;j<SecondCount &&findSecondFigure;j++){
                        findSecondFigure=false;
                        for(k++;k<VALUECOUNT;k++){
                            SecondFigures[j]=k;
                            if(cntFlag[k]>=cardGroup.type.cnt2 &&cntFlag[k]<cardGroup.type.cnt1){
                                findSecondFigure=true;
                                break;
                            }
                        }
                    }
                    if(findSecondFigure){
                        //cout<<"查找SecondFigure "<<cardGroup.type.cnt2<<"个"<<SecondFigures[0]+3<<endl;
                        //cout<<"SecondCount= "<<SecondCount<<endl;
                        //for(i=0;i<SecondCount;i++)cout<<"SecondFigures["<<i<<"]="<<SecondFigures[i]<<endl;
                        for(i=0;i<SecondCount;i++){
                            for(j=0;j<cardsHolded.size();){
                                if(cardsHolded[j]->value==SecondFigures[i]){
                                    for(k=0;k<cardGroup.type.cnt2;k++){
                                        //cout<<"添加"<<cardsHolded[j]->value+3<<endl;
                                        ret.push_back(cardsHolded[j+k]);
                                    }
                                    do{
                                        j++;
                                    }while(j<cardsHolded.size()&&cardsHolded[j]->value==SecondFigures[i]);
                                }else{
                                    j++;
                                }
                            }
                        }
                        return ret;
                    }//if(findSecondFigure)
                }//end if(cardGroup.type.cnt2>0)
                else{
                    return ret;
                }
            }//end if(findFirstFigure)
        }//end for(i=value+1;i<VALUECOUNT;i++)
        ret.clear();
        //没牌打得过时查找有没有炸dan
        if(typeStr!="炸dan"){
            for(i=cardsHolded.size()-1;i>=3;i--){
                if(cardsHolded[i]->value==cardsHolded[i-3]->value){
                    for(j=0;j<4;j++){
                        ret.push_back(cardsHolded[i-j]);
                    }
                    break;
                }
            }
        }
        return ret;
    }//end vector<Card*> findCanBeatFrom()
};
LastCards* LastCards::lastCards = NULL;

class Player{
  public:
    string name;
    vector<Card*> cards;
    void arrange(){
        sort(cards.begin(),cards.end(),cmp);
    }
    void print(){
        cout<<this->name<<":\t";
        for(int i=0;i<cards.size();i++){
            cards[i]->print();
        }
        cout<<"["<<cards.size()<<"]\n";
    }
    vector<Card*> tip(){
        //提示功能,使自己最小一张连最长
        CardGroup ret;
        string temp;
        int j,k,m=cards.size();
        for(j=0;j<m;j++){
            temp="";
            for(k=j;k<m;k++){
                temp+=cards[k]->figure;
            }
            ret.init(temp,cards);
            if(ret.type.typeId!=ERROR){
                return ret.cards;
            }
        }
        ret.cards.clear();
        return ret.cards;
    }
    void chupai(CardGroup &cardGroup){
        //出牌
        cout<<this->name<<":\t";
        cout<<cardGroup.type.typeStr<<' ';
        for(int i=0;i<cardGroup.cards.size();i++){
            cardGroup.cards[i]->print();
            this->cards.erase(find(this->cards.begin(),this->cards.end(),cardGroup.cards[i]));
        }
        cout<<"\t["<<this->cards.size()<<"]\n";
        if(cardGroup.type.typeStr!="不出"){
            //记录到 LastCards 中
            LastCards::inst()->player=this;
            LastCards::inst()->cardGroup.init(cardGroup.cards);
        }
    }
};

class Landlords{
    Player *player[PLAYERCOUNT];
    bool finished,youWin,landlordWin;
    int landlordIndex;
    Card *cards[CARDSCOUNT];
  public:
    Landlords(){
        int i,j,k;
        for(i=0;i<PLAYERCOUNT;i++){
            this->player[i]=new Player();
        }
        //54张牌初始化
        for(k=i=0;i<14;i++){
            if(toFigure[i]==' '){
                continue;
            }
            for(COLOR color=eHEART;color<=eSPADE;color=(COLOR)(color+1)){
                this->cards[k++]=new Card(toFigure[i],color);
            }
        }
        this->cards[k++]=new Card('Y',eSPADE);
        this->cards[k]=new Card('Z',eHEART);
    }
    ~Landlords(){
        for(int i=0;i<PLAYERCOUNT;i++){
            delete this->player[i];
        }
        for(int i=0;i<CARDSCOUNT;i++){
            delete this->cards[i];
        }
    }
    void init(){
        player[CURRENTPLAYER]->name="Bice";
        player[1]->name="玩家2";
        player[2]->name="玩家3";
        finished=false;
        youWin=false;
        landlordWin=false;
        //抢地主
        landlordIndex=ERROR;
        while(landlordIndex==ERROR){
            srand((int)time(0));
            shuffle();
            landlordIndex=chooseLandlord();
        }
        cout<<player[landlordIndex]->name<<"\t成为地主\n\n";
        this->add3Cards();
        LastCards::inst()->player=player[landlordIndex];
    }
    void startGame(){
        string inputSrt;
        CardGroup inputCards;
        for(int iTurns=landlordIndex;!finished;iTurns++){
            if(iTurns>=PLAYERCOUNT){
                iTurns=0;
            }
            if(iTurns==CURRENTPLAYER){
                cout<<endl;
                player[iTurns]->print();
                cout<<"输入提示：Z=大王 Y=小王 0=10 输入可无序 例如:JKQ0A9\n请出牌：\t";
                do{
                    cin>>inputSrt;
                    inputCards.init(inputSrt,player[iTurns]->cards);
                }while(check(&inputCards)==false);
            }else{
                if(player[iTurns]==LastCards::inst()->player){
                    //若是上次出牌的是自己，启用提示功能
                    inputCards.init(player[iTurns]->tip());
                }else{
                    //查找能打得过上家的牌
                    inputCards.init(LastCards::inst()->findCanBeatFrom(player[iTurns]->cards));
                }
            }
            player[iTurns]->chupai(inputCards);//出牌

            if(player[iTurns]->cards.size()==0){
                //玩家手中没牌了，游戏结束
                finished=true;
                landlordWin=iTurns==landlordIndex;
                if(landlordWin){
                    youWin=landlordIndex==CURRENTPLAYER;
                }else{
                    youWin=landlordIndex!=CURRENTPLAYER;
                }
            }
        }
        cout<<"\n_________________________ "<<(youWin?"You Win!":"You Lose!")<<" _________________________\n\n";
    }
    void add3Cards(){
        cout<<"地主3张牌:\t";
        for(int i=PLAYERCOUNT*17;i<CARDSCOUNT;i++){
            this->cards[i]->print();
            player[landlordIndex]->cards.push_back(cards[i]);
        }
        cout<<endl;
        player[landlordIndex]->arrange();
    }
    int chooseLandlord(){
        cout<<"\n_________________________ 抢地主 _________________________\n\n";
        int first=-1,last,cnt=0,i,j=rand()%PLAYERCOUNT;
        bool decision;
        for(i=0;i<PLAYERCOUNT;i++,j==2?j=0:j++){
            if(j==CURRENTPLAYER){
                decision=makeChoice("是否抢地主？(Y=抢/N=不抢):");
            }else{
                decision=rand()%2;
            }
            if(decision){
                cnt++;
                last=j;
                if(first==-1){
                    first=j;
                }
                cout<<this->player[j]->name<<"\t抢地主\n";
            }else{
                cout<<this->player[j]->name<<"\t没有抢\n";
            }
        }
        if(cnt==0){
            cout<<"没人抢，重新发牌\n";
            return ERROR;
        }
        if(cnt==1){
            //第一轮只有一人抢地主
            return first;
        }
        else{
            //最后一次争抢
            if(first==CURRENTPLAYER){
                decision=makeChoice("是否抢地主？(Y=抢/N=不抢):");
            }else{
                decision=rand()%2;
            }
            if(decision){
                cout<<this->player[first]->name<<"\t抢地主\n";
                return first;
            }else{
                cout<<this->player[first]->name<<"\t没有抢\n";
                return last;
            }
        }
    }
    void shuffle(){
        int i,j,k;
        //洗牌
        for(i=0;i<CARDSCOUNT;i++){
            swap(this->cards[i],this->cards[rand()%CARDSCOUNT]);
        }

        //分牌
        for(k=i=0;i<PLAYERCOUNT;i++){
            this->player[i]->cards.clear();
            for(j=0;j<17;j++){
                this->player[i]->cards.push_back(this->cards[k++]);
            }
            this->player[i]->arrange();//整理
            this->player[i]->print();
        }
    }
    bool check(CardGroup *cardGroup){
        if(cardGroup->type.typeId==ERROR){
            cout<<"出牌错误，重新输入\n";
            return false;
        }else if(cardGroup->type.typeStr=="不出"){
            return true;
        }else if(LastCards::inst()->player!=player[CURRENTPLAYER]&&!cardGroup->isCanBeat(LastCards::inst()->cardGroup)){
            cout<<"打不过，重新输入\n";
            return false;
        }else{
            return true;
        }
    }
};

int main(){
    Landlords *landlords=new Landlords();
    do{
        landlords->init();//发牌、抢地主
        landlords->startGame();//游戏开始
    }while(makeChoice("\n是否继续游戏？（Y=继续/N=结束）: "));
    delete landlords;
    return 0;
}

bool makeChoice(string tip){
    cout<<tip;
    string input;
    cin>>input;
    return input=="Y"||input=="y";
}

bool cmp(Card* a,Card* b){
    //比较两张牌大小
    if(a->value==b->value){
        return a->color>b->color;
    }else{
        return a->value>b->value;
    }
}
