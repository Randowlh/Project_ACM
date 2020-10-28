# 数据结构作业报告1 迷宫搜索

班级：19184115    姓名：施博儒    学号：190419822


## 一、需求分析

​        迷宫问题大体分为两个部分要求，第一部分是如何生成一个迷宫，并且控制路径数量合理（不能太多也不能太少），另一部分是运用搜索算法，动态输出多路径并记录，并且找到最短路径。

​        对于动态显示，我用"■"表示墙，"  "两个空格表示路，并且在数组Maze中用0表示路，1表示墙。在搜索的过程中，用"↑","↓","←","→"四个符号表示当前行进的方向。

​        迷宫生成需要用到随机函数，但是，单纯的随机算法又不能保证路通并且限制多路径的数量。

​        迷宫搜索需要用到dfs深度优先搜索和bfs广度优先搜索，这就需要我们自己写一个栈和队列来实现。



## 二、概要设计



### 1、迷宫生成

​        为了解决第一部分的问题，如果使用随机化的迷宫生成方法，容易造成路径过多的情况或者路不通的情况，使得程序的运行时间大大增加。因此我选择使用最小生成树的Prim算法，保证了从一点到另一点只存在一条路径，并且也使得生成的迷宫更加美观。

![image-20201019103408563](C:\Users\HUAWEI\AppData\Roaming\Typora\typora-user-images\image-20201019103408563.png) 

​        如图所见，通过Prim算法生成迷宫不仅能够大大节省时间，并且能更好的控制路径数量，使生成的迷宫更加简洁美观。

#### Prim实现最小生成树

​        首先，让所有横纵坐标皆为奇数的点成为节点，像上下左右连边，即可生成一张无向图。所有的这些横纵坐标皆为奇数的点即为图的节点。

![image-20201019104603415](C:\Users\HUAWEI\AppData\Roaming\Typora\typora-user-images\image-20201019104603415.png) 

​        如图所示，白色为节点，红色为边。

​        设定起点已经访问。

​        随机得到一个已经访问过的点，随机这个点的边，随机找到与这个节点相连的任意一个其他节点，把这个节点加入树中，并且把迷宫地图上对应的墙打通（Maze[i] [j]=0)

​        一直找点，直到到达一个点，它所有的边都连接的点都已经在树上，这种情况需要重新从树上随机一个点，并重复上面的步骤。

​        重复上面的步骤直到所有的点都在树上。

​        伪代码

```
//迷宫生成Prim算法
while(还存在不在树上的点){
	x = 随机一个已经在树上的点; 
	if(所有x连接的点都已经在树上) continue; 
	edge = 随机一条边连接没访问的点;
	打通edge对应Maze数组中的墙
	x = edge去到的点;
	把新的 x 加入树中; 
} 
```

#### 迷宫存图

​        用二维数组Maze[] []存。

​        对于每个图上的坐标：

​        我用"■"表示墙，在数组中就记为1；

​         "  "两个空格表示路，并且在数组Maze中用0表示路；



### 2、路径搜索

​        程序要求找到多路径，最短路径，并且动态显示搜索过程，在程序结束时打印整条路经。

#### 动态显示搜索过程

​        在搜索的过程中，用"↑","↓","←","→"四个符号表示当前行进的方向，存在方向数组jt[] []中；

```
char jt[5][6]={"  ","↑","↓","←","→"}; 
```

​         在搜索时候用数组d记录方向，1234分别表示上下左右，输出路径时按照对应方向输出。

```
int d[MAXNN][MAXNN];//记录当前位置搜索的方向，输出路径时用
```

​        在回溯的时候重置d[i] [j]=0,输出路径时照旧输出空格即可。

#### 路径输出

​        两层循环遍历Maze数组，如果为1则输出墙"■"。如果是0，则继续检测d数组，看看有没有存对应方向的箭头，如果有则输出箭头，没有则输出"  "表示空路。

​        在循环循环搜索完成后如何输出栈中的路径？

​        这里一开始我比较疑惑，因为栈只能从顶部取元素，而要实现路径输出，必须先输出栈底的起点，再一步一步向上输出。

​        所以在这里我选择新建一个栈，在搜索完成后，把原先dfs搜索栈中的元素全部一个一个加入新的栈，这样取出来的顺序就是从下到上的顺序了。在这个取出来的过程中，把元素重新放入原先的栈，这里复杂度也是比较可控的，我觉得应该还算是一个合理的方法。

​        伪代码：

```
if(达到终点){
	临时新建一个栈stack2;
	while(stack1不为空){
		取出stack1的top元素;
		把这个元素放到stack2;
		stack1的top元素出队;
	}
	while(stack1不为空){
		取出stack1的top元素;
		输出该元素的坐标(x,y)->来显示路径
		把这个元素放到stack2;
		stack1的top元素出队;
	}
}
```



## 三、详细设计



### 1、一些重要的小部件

#### ok函数

```c++
bool OK(int x,int y){//判断点是否在界内
    return x>0&&x<MAXN&&y>0&&y<MAXN;
}
```

​        用来检测当前节点xy是否在迷宫的范围内，防止搜索的时候出现越界。

#### 方向数组与动态显示箭头

```c++
int d[MAXNN][MAXNN];//记录当前位置搜索的方向，输出路径时用
char jt[5][6]={"  ","↑","↓","←","→"}; 
```

​        在搜索的过程中，用"↑","↓","←","→"四个符号表示当前行进的方向，存在方向数组jt[] []中。

####  maze_path函数-在搜索的时候动态显示搜索过程

```c++
void maze_path(){//在搜索时同时打印迷宫和路径
	for(int i=1;i<MAXN;i++){
        for(int j=1;j<MAXN;j++){
            if(maze_map[i][j]) cout<<"■";
            else if(d[i][j]) cout<<jt[d[i][j]];
            else cout<<"  ";
        }
        cout<<endl;
    }
} 
```

​        两层循环遍历Maze数组，如果为1则输出墙"■"。如果是0，则继续检测d数组，看看有没有存对应方向的箭头，如果有则输出箭头，没有则输出"  "表示空路。

#### 自定义迷宫搜索的参数

```c++
int shuaxintime;//刷新时间
int MAXN;
```

​        每次刷新的时间，决定了搜索的快慢，MAXN决定了生成迷宫的大小。

​        这两个变量在一开始main函数中的交互界面会有输入。



### 2、数据结构-栈Stack

​        写的挺平凡的一个栈。限定仅在表尾进行插入和删除操作的线性表。

```c++
class Stack{
private:
    Node* head;//栈的头指针 
public:
    Stack():head(NULL){}//头指针赋值为空
    ~Stack(){//析构函数,防止内存泄漏
        Node* px;
        while(head!=NULL){
            px = head;
            head = px->next;
            delete(px);
        }
    }
    void push(int x,int y,int fx){
        Node *px = new Node(x,y,fx);//构造新节点
        px->next = head;
        head = px;
    }
    void pop(){//栈顶
        if(empty()) return;//避免栈空的情况
        Node* px = head;
        head = px->next;
        delete(px);
    }
    bool empty(){//判空
        return head==NULL;
    }
    Node& top(){//返回栈顶节点
        return *head;
    }
};
```



### 3、生成迷宫

```c++
void maze_generate(){//Prim树结构迷宫生成
    srand((unsigned)time(NULL));//随机种子
    for(int i=1;i<MAXN;i++){
        for(int j=1;j<MAXN;j++){
            viss[i][j] = d[i][j] = vis[i][j] = 0;//重置所有点未访问
            if(i==1||i==MAXN-1||j==1||j==MAXN-1) maze_map[i][j]=1;
            else if(i%2==0&&j%2==0) maze_map[i][j]=0;
            else maze_map[i][j] = 1;
        }
    }
    maze_map[2][1] = maze_map[MAXN-2][MAXN-1] = 0;//起点和终点
    bool flag = 1;
    vis[2][2] = 1;//访问过起点
    int nowx = 2,nowy = 2;//当前访问格子
    while(flag){//直到所有点都被访问过
        while(1){
            //判断周围的点是否都被访问过
            bool flag2=1;
            int sj,dx,dy;
            for(int i=0;i<4;i++){
                dx = nowx + dir[i][0]*2;
                dy = nowy + dir[i][1]*2;
                if(!OK(dx,dy)) continue;//越界
                if(vis[dx][dy]) continue;//访问过了
                flag2=0;//有没访问过的点
            }
            if(flag2){
                break;//退出while
            }
            flag2 = 1;
            while(flag2){//随机找到下一个没被访问过的点
                sj = rand()%4;
                dx = nowx + dir[sj][0]*2;
                dy = nowy + dir[sj][1]*2;
                if(!OK(dx,dy)){continue;}//越界
                if(vis[dx][dy]){continue;}//访问过了
                vis[dx][dy] = 1;//访问该点
                maze_map[nowx+dir[sj][0]][nowy+dir[sj][1]]=0;
                nowx = dx;nowy = dy;
                break;
            }
        }
        //看是否所有点都被访问过
        flag = 0;//如果有则改成1
        for(int i=1;i<MAXN;i++){
            for(int j=1;j<MAXN;j++){
                if(i%2==0&&j%2==0){
                    if(!vis[i][j]){//还有点没被访问的
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        //找新的nowx,nowy
        if(!flag) break;//所有点都已经被访问
        while(1){
            nowx = rand()%(MAXN-1)+1;
            nowy = rand()%(MAXN-1)+1;
            if(nowx%2==1) nowx++;
            if(nowy%2==1) nowy++;
            if(!OK(nowx,nowy)) continue;
            if(!vis[nowx][nowy]) continue;
            //到这里说这对now xy是可以的
            break;
        }
    }
}
```

​        这里的程序写的比较长，主要思路就是：

​        设定起点已经访问。

​        代码的核心就在Prim这里寻找新的点的部分：

```c++
while(flag2){//随机找到下一个没被访问过的点
    sj = rand()%4;
    dx = nowx + dir[sj][0]*2;
    dy = nowy + dir[sj][1]*2;
    if(!OK(dx,dy)){continue;}//越界
    if(vis[dx][dy]){continue;}//访问过了
    vis[dx][dy] = 1;//访问该点
    maze_map[nowx+dir[sj][0]][nowy+dir[sj][1]]=0;
    nowx = dx;nowy = dy;
    break;
}
```

​        随机得到一个已经访问过的点，随机这个点的边，随机找到与这个节点相连的任意一个其他节点，把这个节点加入树中，并且把迷宫地图上对应的墙打通（Maze[i] [j]=0)

​        一直找点，直到到达一个点，它所有的边都连接的点都已经在树上，这种情况需要重新从树上随机一个点，并重复上面的步骤。

​        重复上面的步骤直到所有的点都在树上。

​        但是在这之前，必须先检测这个点是不是已经到达了"四周的点都已经是生成树上的节点"的情况，这时候只需要一个for循环遍历周围四个点检测是不是都已经在树上即可。

​        如果是这种所说的情况，则需要退出while循环，重新选择一个树上的节点开始继续搜索。

```c++
for(int i=0;i<4;i++){
    dx = nowx + dir[i][0]*2;
    dy = nowy + dir[i][1]*2;
    if(!OK(dx,dy)) continue;//越界
    if(vis[dx][dy]) continue;//访问过了
    flag2=0;//有没访问过的点
}
if(flag2){
	break;//退出while
}
```

​        一开始用了另外一种方案，即找到一个叶子节点时打通四周所有的边，但是这样生成的迷宫空路太多了，所以后来给废弃掉了，选择了现在的方法。

```
//这里是原先采取的第二种策略
//即找到已访问的方块后，把四面都打通
//但是这样的结果就是挖的空太多了，导致存在很多很多路径 
int ss = rand()%4,tt = rand()%4;
for(int i=ss;i<=tt;i++){
    dx = nowx + dir[i][0]*2;
    dy = nowy + dir[i][1]*2;
    if(OK(dx,dy)){
    	maze_map[nowx+dir[i][0]][nowy+dir[i][1]]=0;
	}
}
```



### 4、迷宫搜索

```c++
void dfs(int sx,int sy,int tx,int ty){//使用堆栈实现的深度优先搜索
    Stack st;//栈
	st.push(sx,sy,4);
	int x,y,dx,dy;
	while(!st.empty()){
		//输出迷宫部分
		x = st.top().x;y = st.top().y;
		viss[x][y] = 1;
		d[x][y] = st.top().fx;
		Sleep(shuaxintime);
		system("cls");
		maze_path();
		cout<<endl;
		cout<<"■现在位置:("<<x<<','<<y<<")"<<endl;
		if(x==tx&&y==ty){
			cout<<"■找到终点"<<endl;
			cout<<"■一共有 1 条路径:"<<endl; 
			cout<<"■路径 1 :"<<endl;
			outps(st);
			cout<<endl;
			break;
		}
		if(st.top().fx==0){//回溯
			viss[x][y] = 1;
			st.pop();
			continue;
		}
		st.top().fx=0;
		for(int i=0;i<4;i++){
			dx = x+dir[i][0]; dy = y+dir[i][1];
			if(OK(dx,dy)&&viss[dx][dy]==0&&maze_map[dx][dy]==0){
				st.push(dx,dy,i+1);//新点入栈
			}
		}
	}
}
```

​        按照穷举的思路，枚举所有可行走的方向，并且用vis数组防止走重复的路。在发现一个新的可走的点的时候把这个点推入栈中，并且记录在d数组中，以便之后动态显示的时候输出箭头。

​        中间的这两个是为了使动态搜索有一个时间间隔，以至于不会搜的太快。

```c++
Sleep(shuaxintime);
system("cls");
```

​        用一个for循环来枚举四个可以行走的方向。确定可以走之后推入到stack栈中。

```c++
for(int i=0;i<4;i++){
	dx = x+dir[i][0]; dy = y+dir[i][1];
	if(OK(dx,dy)&&viss[dx][dy]==0&&maze_map[dx][dy]==0){
		st.push(dx,dy,i+1);//新点入栈
	}
}
```

​        找到终点之后需要输出路径，这时候需要调用一个outps的函数，之后会再说明

```c++
if(x==tx&&y==ty){
	cout<<"■找到终点"<<endl;
	cout<<"■一共有 1 条路径:"<<endl; 
	cout<<"■路径 1 :"<<endl;
	outps(st);
	cout<<endl;
	break;
}
```



### 5、路径输出

​        用outps函数实现搜索完成后的路径输出。

​        在循环循环搜索完成后如何输出栈中的路径？

```c++
void outps(Stack &stk){//结尾输出路径 
	Stack tmp;
	Node hc; 
	while(!stk.empty()){
		hc = stk.top();
		stk.pop();
		tmp.push(hc.x,hc.y,hc.fx);
	}
	hc = tmp.top();
	tmp.pop();
	cout<<'('<<hc.x<<','<<hc.y<<')';
	while(!tmp.empty()){
		hc = tmp.top();
		tmp.pop();
		cout<<"->"<<'('<<hc.x<<','<<hc.y<<')';
	}
} 
```

​        这里一开始我比较疑惑，因为栈只能从顶部取元素，而要实现路径输出，必须先输出栈底的起点，再一步一步向上输出。

​        所以在这里我选择新建一个栈，在搜索完成后，把原先dfs搜索栈中的元素全部一个一个加入新的栈，这样取出来的顺序就是从下到上的顺序了。在这个取出来的过程中，把元素重新放入原先的栈，这里复杂度也是比较可控的，我觉得应该还算是一个合理的方法。



### 6、交互界面

​        在main函数中实现。

```c++
int main(){
	cout<<"■请自定迷宫大小"<<endl; 
	cout<<"■Option:必须为奇数,推荐在10-40之间选"<<endl;
	cout<<"□迷宫大小:";
	cin>>MAXN;
	MAXN++;
	char hc;
	system("cls");
    maze_generate();//生成树形迷宫
    print_maze();//打印迷宫 
	cout<<"■Option:迷宫为树形结构,存在且只有一条路径"<<endl;
	cout<<"□开始搜索/退出程序[Y/N]:";
	cin>>hc;
	if(hc=='Y'||hc=='y'){
		system("cls");
		print_maze();//打印迷宫 
		cout<<"■如果是20左右,推荐50,如果迷宫比较大,因为打印迷宫也需要时间,可以设置间隔为0"<<endl;
		cout<<"□输入搜索间隔(单位ms):";
		cin>>shuaxintime;
		dfs(2,1,MAXN-2,MAXN-1);//开始搜索
	}
}
```

​        先要求使用者输入迷宫的大小，保存到MAXN变量中，之后生成迷宫的时候需要参考这个变量进行生成

```c++
cout<<"■请自定迷宫大小"<<endl; 
cout<<"■Option:必须为奇数,推荐在10-40之间选"<<endl;
cout<<"□迷宫大小:";
cin>>MAXN;
```

​        根据迷宫的大小不同，还需要让使用者自定义搜索的速度，存在shuaxintime里面，之后每次搜索到新的点，都用sleep来使程序睡眠一段时间来制造间隔。

```c++
print_maze();//打印迷宫 
cout<<"■如果是20左右,推荐50,如果迷宫比较大,因为打印迷宫也需要时间,可以设置间隔为0"<<endl;
```



## 四、程序测试

![image-20201020113418502](C:\Users\HUAWEI\AppData\Roaming\Typora\typora-user-images\image-20201020113418502.png) 

​        一开始让我设定迷宫的大小，我先选择了21这个比较小的数字，之后再测试大的。

![image-20201020113531443](C:\Users\HUAWEI\AppData\Roaming\Typora\typora-user-images\image-20201020113531443.png) 

​        可以看到，我们能够顺利的生成出一个比较规整的迷宫，程序又让我们确认开始搜索。

​        我选择搜索的间隔为50ms，因为刷新打印整个迷宫也需要时间，所以我把间隔设定的相对较短。

​        再搜索的过程中，我们发现程序能够正常的动态输出路径，并且回溯时也能正常的擦去之前走过的路。

![image-20201020113745884](C:\Users\HUAWEI\AppData\Roaming\Typora\typora-user-images\image-20201020113745884.png) 

​        使用箭头显示迷宫搜索的过程，还是比较直观的。

![image-20201020113840063](C:\Users\HUAWEI\AppData\Roaming\Typora\typora-user-images\image-20201020113840063.png) 

​        在搜索结束后，发现路径的打印也是正常的。

​        我们再测试一个稍大的迷宫，大小设定为51，但是对于稍大的迷宫，用for循环打印迷宫的时候出现了比较明显的延迟（一行一行往下打印需要时间），个人认为效果不是太好。

![image-20201020114028823](C:\Users\HUAWEI\AppData\Roaming\Typora\typora-user-images\image-20201020114028823.png) 

​        最后的结果也是能正常输出的。

![image-20201020115105121](C:\Users\HUAWEI\AppData\Roaming\Typora\typora-user-images\image-20201020115105121.png) 

![image-20201020115121664](C:\Users\HUAWEI\AppData\Roaming\Typora\typora-user-images\image-20201020115121664.png) 

​        至此，迷宫生成搜索程序测试完毕。