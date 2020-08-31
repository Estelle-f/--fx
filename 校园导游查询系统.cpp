//#include<iostream.h> 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define Infinity  1000
#define MaxVertexNum 35
#define MAX  40

typedef struct arcell                               //边的权值信息
{
	int adj;                                        //权值
}arcell,adjmatrix[MaxVertexNum][MaxVertexNum];      //图的邻接矩阵类型

typedef struct vexsinfo                             //顶点信息
{
	int position;                                   //景点的编号
	char name[32];                                  //景点的名称
	char introduction[256];                         //景点的介绍
}vexsinfo;

typedef struct mgraph                               //图结构信息
{
	vexsinfo vexs[MaxVertexNum];                    //顶点向量(数组)
	adjmatrix arcs;                                 //邻接矩阵
	int vexnum,arcnum;                              //分别指定顶点数和边数
}mgraph;

//全局变量

int visited[35];                                    //用于标志是否已经访问过

int d[35];                                          //用于存放权值或存储路径顶点编号

mgraph  campus;                                     //图变量(大学校园)


// (1) 对图初始化

mgraph initgraph()
{
	int i=0,j=0;
	mgraph c;
	
	c.vexnum =22;                                   //顶点个数
	c.arcnum =40;                                   //边的个数
	for(i=0;i<c.vexnum ;i++)                        //依次设置顶点编号
		c.vexs[i].position =i;
	//依次输入顶点信息
		strcpy(c.vexs[0].name,"中区正门");
	strcpy(c.vexs[0].introduction,"离3路、15路公交很近"); 
	strcpy(c.vexs[1].name,"中区图书馆");
	strcpy(c.vexs[1].introduction,"里面有大量的书籍可以借阅"); 
	strcpy(c.vexs[2].name,"中区11教学楼");
	strcpy(c.vexs[2].introduction,"是中区主教学楼");
	strcpy(c.vexs[3].name,"办公楼");
	strcpy(c.vexs[3].introduction,"领导办公的地方");
	strcpy(c.vexs[4].name,"中区体育场");
	strcpy(c.vexs[4].introduction,"里面有排球场、篮球场");
	strcpy(c.vexs[5].name,"教学楼");
	strcpy(c.vexs[5].introduction,"化工与化学工程学院、轻工与纺织学院的教学楼");
	strcpy(c.vexs[6].name,"22#公寓");
	strcpy(c.vexs[6].introduction,"研究生宿舍楼");
	strcpy(c.vexs[7].name,"校史馆");
	strcpy(c.vexs[7].introduction,"齐齐哈尔大学从建立开始的所有历史");
	strcpy(c.vexs[8].name,"2#公寓");
	strcpy(c.vexs[8].introduction,"男生宿舍楼");
	strcpy(c.vexs[9].name,"洗浴中心");
	strcpy(c.vexs[9].introduction,"学生洗澡、打热水的地方");
	strcpy(c.vexs[10].name,"西区正门");
	strcpy(c.vexs[10].introduction,"离104、101路公交比较近");
	strcpy(c.vexs[11].name,"西区2教学楼");
	strcpy(c.vexs[11].introduction,"机电工程学院教学楼");
	strcpy(c.vexs[12].name,"西区1教学楼");
	strcpy(c.vexs[12].introduction,"西区主教学楼楼，计控学院等教学楼");
	strcpy(c.vexs[13].name,"西区图书馆");
	strcpy(c.vexs[13].introduction,"有大量的书籍，还有自习室");
	strcpy(c.vexs[14].name,"西区体育馆");
	strcpy(c.vexs[14].introduction,"有各种健身器材");
	strcpy(c.vexs[15].name,"西区食堂");
	strcpy(c.vexs[15].introduction,"学生吃饭的地方");
	strcpy(c.vexs[16].name,"西区体育场");
	strcpy(c.vexs[16].introduction,"有足球场、田径运动场");
	strcpy(c.vexs[17].name,"宿舍楼");
	strcpy(c.vexs[17].introduction,"学生住的地方");
	strcpy(c.vexs[18].name,"中区15教学楼");
	strcpy(c.vexs[18].introduction,"有许多的计算机，马克思主义学院教学楼");
	strcpy(c.vexs[19].name,"中区食堂");
	strcpy(c.vexs[19].introduction,"旁边有齐大购物中心和齐大培训中心"); 
	strcpy(c.vexs[20].name,"文化宫");
	strcpy(c.vexs[20].introduction,"演出和演讲的地方"); 
	strcpy(c.vexs[21].name,"中区东门");
	strcpy(c.vexs[21].introduction,"距离劳动湖比较近"); 
	
	
		//依次输入边上的权值信息
        for(i=0;i<c.vexnum ;i++)
			for(j=0;j<c.vexnum ;j++)
				c.arcs [i][j].adj =Infinity; //先初始化图的邻接矩阵
        
		//部分弧长
		
		c.arcs[0][1].adj=8;      c.arcs[0][1].adj=8;
	c.arcs[0][1].adj=8;      c.arcs[0][1].adj=8;
	c.arcs[0][1].adj=8;	     c.arcs[0][1].adj=8;
	c.arcs[0][1].adj=8;      c.arcs[0][2].adj=4;
	c.arcs[0][3].adj=4;      c.arcs[1][2].adj=5;
	c.arcs[1][6].adj=10;     c.arcs[1][7].adj=10;
	c.arcs[1][18].adj=10;    c.arcs[2][3].adj=10;
	c.arcs[2][4].adj=3;      c.arcs[3][5].adj=15;
	c.arcs[4][5].adj=6;      c.arcs[4][18].adj=5;
	c.arcs[4][20].adj=60;    c.arcs[5][20].adj=40;
	c.arcs[5][21].adj=40;    c.arcs[6][7].adj=7;
	c.arcs[6][8].adj=25;     c.arcs[7][8].adj=4;
	c.arcs[7][9].adj=10;     c.arcs[8][9].adj=15;
	c.arcs[8][10].adj=30;    c.arcs[9][17].adj=10;
	c.arcs[9][18].adj=20;    c.arcs[10][11].adj=6;
	c.arcs[10][12].adj=4;    c.arcs[10][13].adj=5;
	c.arcs[11][14].adj=10;   c.arcs[12][14].adj=20;
	c.arcs[13][14].adj=15;   c.arcs[14][15].adj=45;
	c.arcs[14][16].adj=30;   c.arcs[15][16].adj=10;
	c.arcs[17][19].adj=10;   c.arcs[19][20].adj=30;
	c.arcs[19][21].adj=30;   c.arcs[20][21].adj=5;

        for(i=0;i<c.vexnum ;i++)                      //邻接矩阵是对称矩阵，对称赋值
			for(j=0;j<c.vexnum ;j++)
				c.arcs[j][i].adj =c.arcs[i][j].adj ;
		return c;
}//initgraph


// (2) 查找景点在图中的序号

int locatevex(mgraph c,int v)
{
	int i;
	for(i=0;i<c.vexnum ;i++)
		if(v==c.vexs[i].position)
			return i;                           //找到，返回顶点序号i
	
    return -1;                                  //否则，返回-1
}


//(3) 、(4) 求两景点间的所有路径

// (3) 打印序号为m,n景点间的长度不超过8个景点的路径

void path(mgraph c, int m,int n,int k)
{
    int s,x=0;
	int t=k+1;                                  //t 记载路径上下一个中间顶点在d[]数组中的下标
	if(d[k]==n && k<8)                          //d[k]存储路径顶点。若d[k]是终点n且景点个数<=8，则输出该路径
	{                                           //递归出口，找到一条路径
      for(s=0;s<k;s++)
		printf("%s--->",c.vexs[d[s]].name);     //输出该路径。s=0 时为起点m
      printf("%s",c.vexs[d[s]].name);           //输出最后一个景点名(即顶点n的名字，此时s==k)
      printf("\n\n");
    }
    else
	{
	  s=0;
      while(s<c.vexnum)                         //从第m个顶点，试探至所有顶点是否有路径
	  {
		if((c.arcs[d[k]][s].adj<Infinity) && (visited[s]==0)) //初态：顶点m到顶点s有边，且未被访问
		{
	       visited[s]=1;
	       d[k+1]=s;                //存储顶点编号s 至d[k+1]中
	       path(c,m,n,t);           //求从下标为t=k+1的第d[t]个顶点开始的路径(递归调用)，同时打印出一条m至n的路径
	       visited[s]=0;            //将找到的路径上顶点的访问标志重新设置为0，以用于试探新的路径
		}
		s++;                        //试探从下一个顶点 s 开始是否有到终点的路径
	  }//endwhile
	  
	}//endelse

}//endpath

//(4) 打印两景点间的景点个数不超过8的所有路径。调用(3)

int allpath(mgraph c)
{
  int k,i,j,m,n;
  printf("\n\n请输入你要查询的两个景点编号:\n\n");
  scanf("%d%d",&i,&j);
  printf("\n\n");
  m=locatevex(c,i);                         //调用(2)，确定该顶点是否存在。若存在，返回该顶点编号
  n=locatevex(c,j);
  d[0]=m;                                   //存储路径起点m (int d[]数组是全局变量)
  for(k=0;k<c.vexnum;k++)                   //全部顶点访问标志初值设为0
    visited[k]=0;
  visited[m]=1;                             //第m个顶点访问标志设置为1
  path(c,m,n,0);                            //调用(3)。k=0，对应起点d[0]==m。k为d[]数组下标
  return 1;
}


// (5) 用迪杰斯特拉算法，求出一个景点到其他景点间的最短路径，并打印

void shortestpath_dij(mgraph c)
{
  //迪杰斯特拉算法，求从顶点v0到其余顶点的最短路经及其带权长度d[v]
  //若p[v][w]为1，则w是从v0到v的最短路经上的顶点
  //final[v]类型用于设置访问标志
		
	int v,w,i,min,t=0,x,flag=1,v0;                //vo为起始景点的编号
	int final[35],d[35],p[35][35];
	printf("\n请输入一个起始景点的编号：");
	scanf("%d",&v0);
    printf("\n\n");
	while(v0<0||v0>c.vexnum)
	{
	    printf("\n你所输入的景点编号不存在\n");
	    printf("请重新输入：");
	    scanf("%d",&v0);
	}//while
	for(v=0;v<c.vexnum ;v++)
	{
		final[v]=0;                               //初始化各顶点访问标志
		d[v]=c.arcs[v0][v].adj;                   //v0 到各顶点 v 的权值赋值给d[v]
		for(w=0;w<c.vexnum ;w++)                  //初始化p[][]数组，各顶点间的路径全部设置为空路径0
			p[v][w]=0;
		if(d[v]<Infinity)                         //v0 到v 有边相连，修改p[v][v0]的值为1
		{
			p[v][v0]=1;
			p[v][v]=1;                            //各顶点自己到自己要连通
		}
	}//for
	d[v0]=0;                                      //自己到自己的权值设为0
	final[v0]=1;                                  //v0的访问标志设为1，v 属于 s 集
	for(i=1;i<c.vexnum ;i++)                      //对其余c.vexnum-1个顶点w，依次求 v 到 w 的最短路径
	{
		min=Infinity;
		for(w=0;w<c.vexnum ;w++)                  //在未被访问的顶点中，查找与 v0 最近的顶点v
			if(!final[w])
				if(d[w]<min)                      //v0 到 w (有边)的权值<min
				{
					v=w;
					min=d[w];
				}//if
		final[v]=1;                                  //v 的访问标志设置为1，v 属于s集
		for(w=0;w<c.vexnum ;w++)                     //修改v0 到其余各顶点w 的最短路径权值d[w]
			if(!final[w]&&(min+c.arcs[v][w].adj <d[w]))  //若w 不属于s，且v 到w 有边相连
			{
				d[w]=min+c.arcs[v][w].adj;               //修改v0 到w 的权值d[w]
				for(x=0;x<c.vexnum ;x++)             //所有v0 到v 的最短路径上的顶点x，都是v0 到w 的最短路径上的顶点
					p[w][x]=p[v][x];
				p[w][w]=1;
			}//if
	}//for
	for(v=0;v<c.vexnum ;v++)                         //输出v0 到其它顶点v 的最短路径
	{
		if(v!=v0)
		    printf("%s",c.vexs[v0].name);            //输出景点v0 的景点名
		for(w=0;w<c.vexnum ;w++)                     //对图中每个顶点w，试探w 是否是v0 到v 的最短路径上的顶点
		{
		    if(p[v][w] && w!=v0 && w!=v)             //若w 是且w 不等于v0，则输出该景点
				  printf("--->%s",c.vexs[w].name);
			 
		}
		printf("---->%s",c.vexs[v].name);  
		printf("\n总路线长为%d米\n\n",d[v]);
		
		
		
	}//for
}//shortestpath_dij 


//(6)-(11)修改图的信息。包括建图、更新信息、删除、增加结点和边
			  
//(6) 构造图的邻接矩阵
	
 int creatgragh(mgraph &c)                          //建图。以图的邻接矩阵存储图
 {
	int i,j,m,n;
	int v0,v1;
	int distance;
	printf("请输入图的顶点数和边数: \n");
	scanf("%d %d",&c.vexnum ,&c.arcnum );
	printf("下面请输入景点的信息：\n");
	for(i=0;i<c.vexnum ;i++)                       //构造顶点向量(数组)
	{
		printf("请输入景点的编号：");
		scanf("%d",c.vexs[i].position );
		printf("\n请输入景点的名称：");
        scanf("%s",c.vexs[i].name );
		printf("\n请输入景点的简介：");
		scanf("%s",c.vexs[i].introduction );
	}
	for(i=0;i<c.arcnum ;i++)                       //初始化邻接矩阵
		for(j=0;j<c.arcnum ;j++)
			c.arcs[i][j].adj =Infinity;
	
	printf("下面请输入图的边的信息：\n");
	for(i=1;i<=c.arcnum ;i++)                      //构造邻接矩阵
	{
		printf("\n第%d条边的起点 终点 长度为：",i);//输入一条边的起点、终点及权值
		scanf("%d %d %d",&v0,&v1,&distance);
		m=locatevex(c,v0);
		n=locatevex(c,v1);
		if(m>=0 && n>=0)
		{
			c.arcs[m][n].adj =distance;
			c.arcs[n][m].adj =c.arcs[m][n].adj ;
		}
	}
	return 1;
}//creatgragh
    
	 
// (7) 更新图的部分信息。返回值: 1

int  newgraph(mgraph &c)
{
	int changenum;                                //计数。用于记录要修改的对象的个数
	int i,m,n,t,distance,v0,v1;
	printf("\n下面请输入你要修改的景点的个数：\n");
	scanf("%d",&changenum);
	while(changenum<0||changenum>c.vexnum )
	{
		printf("\n输入错误！请重新输入");
		scanf("%d",&changenum);
	}

	for(i=0;i<changenum;i++)
	{
		printf("\n请输入景点的编号：");
		scanf("%d",&m);
		t=locatevex(c,m);
		printf("\n请输入景点的名称：");
        scanf("%s",c.vexs[t].name );
		printf("\n请输入景点的简介：");
		scanf("%s",c.vexs[t].introduction );
	}
	
	printf("\n下面请输入你要更新的边数");
	scanf("%d",&changenum);
	while(changenum<0||changenum>c.arcnum )
	{
		printf("\n输入错误！请重新输入");
		scanf("%d",&changenum);
	}
    
	printf("\n下面请输入更新边的信息：\n");
	for(i=1;i<=changenum ;i++)
	{
		printf("\n修改的第%d条边的起点 终点 长度为：",i);
		scanf("%d %d %d",&v0,&v1,&distance);
		m=locatevex(c,v0);
		n=locatevex(c,v1);
		if(m>=0&&n>=0)
		{
			c.arcs[m][n].adj =distance;
			c.arcs[n][m].adj =c.arcs[m][n].adj ;
		}
	}
	return 1;
}//newgraph

// (8) 增加一条边。返回值：1

int enarc(mgraph &c)
{
	int m,n,distance;
	printf("\n请输入边的起点和终点编号,权值：");
    scanf("%d %d %d",&m,&n,&distance);
	while(m<0||m>c.vexnum ||n<0||n>c.vexnum )
	{
		printf("输入错误，请重新输入：");
		scanf("%d %d",&m,&n);
	}
	if(locatevex(c,m)<0)
	{
		printf("此结点%d已删除",m);
		return 1;
	}
	if(locatevex(c,n)<0)
	{
		printf("此结点%d已被删除：",n);
		return 1;
	}
	c.arcs[m][n].adj =distance;
    c.arcs[n][m].adj =c.arcs[m][n].adj;                 //对称赋值
	return 1;
}//enarc

// (9) 增加一个结点。返回值：1

int envex(mgraph &c)
{
	int i;
	printf("请输入你要增加结点的信息：");
	printf("\n编号：");
	scanf("%d",&c.vexs[c.vexnum ].position );
	printf("名称：");
	scanf("%s",c.vexs[c.vexnum ].name );
	printf("简介：");
	scanf("%s",c.vexs[c.vexnum ].introduction) ;
	c.vexnum ++;
	for(i=0;i<c.vexnum;i++)                           //对原邻接矩阵新增加的一行及一列进行初始化
	{
		c.arcs [c.vexnum -1][i].adj=Infinity;         //最后一行(新增的一行)
		c.arcs [i][c.vexnum -1].adj=Infinity;         //最后一列(新增的一列)
	}
	return 1;
}//envex
    
// (10) 删除图的一个顶点。返回值：1

int delvex(mgraph &c)
{
	int i=0,j;
	int m;
	int v;
	if(c.vexnum <=0)
	{
		printf("图中已无顶点");
		return 1;
	}
	printf("\n下面请输入你要删除的景点编号：");
	scanf("%d",&v);
	while(v<0||v>c.vexnum  )
	{
		printf("\n输入错误！请重新输入");
		scanf("%d",&v);
	}
	m=locatevex(c,v);
	if(m<0)
	{
		printf("此顶点 %d 已删除",v);
		return 1;
	}
	for(i=m;i<c.vexnum-1 ;i++)//对顶点信息所在顺序表进行删除m 点的操作
	{
		strcpy(c.vexs[i].name ,c.vexs [i+1].name );
		strcpy(c.vexs[i].introduction ,c.vexs [i+1].introduction );
	}
	//对原邻接矩阵，删除该顶点到其余顶点的邻接关系。分别删除相应的行和列
	for(i=m;i<c.vexnum-1 ;i++)                //行
		for(j=0;j<c.vexnum ;j++)              //列
			c.arcs [i][j]=c.arcs [i+1][j];    //二维数组，从第m+1行开始依次往前移一行。即删除第m 行
	for(i=m;i<c.vexnum-1 ;i++)
		for(j=0;j<c.vexnum ;j++)
            c.arcs [j][i]=c.arcs [j][i+1];    //二维数组，从第m+1列开始依次往前移一列。即删除第m 列
	c.vexnum --;
	return 1;
}//delvex
	
 //(11) 删除图的一条边。返回值：1
	 
int delarc(mgraph &c)
{
	int m,n;
	int v0,v1;
	if(c.arcnum <=0)
	{
		printf("图中已无边，无法删除。");
		return 1;
	}
	printf("\n下面请输入你要删除的边的起点和终点编号：");
	scanf("%d %d",&v0,&v1);
    m=locatevex(c,v0);
	if(m<0)
	{
		printf("此 %d 顶点已删除",v0);
		return 1;
	}
	n=locatevex(c,v1);
	if(n<0)
	{
		printf("此 %d 顶点已删除",v1);
		return 1;
	}
	c.arcs [m][n].adj =Infinity;              //修改邻接矩阵对应的权值
    c.arcs [n][m].adj =Infinity;
	c.arcnum --;
	return 1;
}//delarc

// (12) 输出图的邻接矩阵的值

void printmatrix(mgraph c)
{
	int i,j,k=0;                              //k 用于计数，控制换行

	for(i=0;i<c.vexnum ;i++)
		for(j=0;j<c.vexnum ;j++)
		{
			if(c.arcs[i][j].adj ==Infinity)
				printf("----");
			else
				printf("%4d",c.arcs[i][j].adj);
			k++;
			if(k%c.vexnum ==0)
				printf("\n");
		}
}//printpath

//(13)图操作的主调函数。返回值：1
    
int changegraph(mgraph &c)
{
				
	int yourchoice;
	printf("\n请问是要\n\n     (1)再次建图       (2)删除结点         (3)删除边\n");
	printf("\n(4)增加结点      (5)增加边         (6)更新信息\n\n     (7)打印邻接矩阵     (8)返回?\n\n");

	scanf("%d",&yourchoice);
    printf("\n\n");
	while(!(yourchoice==1||yourchoice==2||yourchoice==3||yourchoice==4||yourchoice==5||yourchoice==6
		  ||yourchoice==7||yourchoice==8))
	{
		printf("输入选择不明确，请重输\n");
		scanf("%d",&yourchoice);
	}
	while(1)
	{
		switch(yourchoice)
		{
			case 1:	creatgragh(c);	break;	
			case 2: delvex(c);		break;
			case 3:	delarc(c);		break;
			case 4:	envex(c);		break;
			case 5:	enarc(c);		break;
			case 6: newgraph(c);	break;
			case 7: printmatrix(c);	break;
			case 8:	return 1;
		}
	    printf("\n请问是要\n\n   (1)再次建图         (2)删除结点          (3)删除边\n");
	    printf("\n(4)增加结点    (5)增加边           (6)更新信息\n\n      (7)打印邻接矩阵     (8)返回?\n\n");

	    scanf("%d",&yourchoice);
        printf("\n\n");
		while(!(yourchoice==1||yourchoice==2||yourchoice==3||yourchoice==4||yourchoice==5||yourchoice==6
			  ||yourchoice==7||yourchoice==8))
		{
			printf("输入选择不明确，请重输\n");
			scanf("%d",&yourchoice);
		}
	}//endwhile(1)

	return 1;
}//changegraph
	 
// (14) 查询两景点间的最短路径

void shortestpath_floyd(mgraph c)
{
	//用floyd算法求各对顶点v和w间的最短路经及其带权长度的d[v][w]。
	//若p[v][w][u]==1；则u是v到w的当前求得的最短路经上的顶点

	int i,j,k,d[35][35],p[35][35][35];
	int v,u,w; 
	for(v=0;v<c.vexnum ;v++)            //初始化各对顶点 v，w 之间的起始距离 d[v][w] 及 路径 p[v][w][] 数组
	{
		for(w=0;w<c.vexnum ;w++)
		{
			d[v][w]=c.arcs[v][w].adj;   //d[v][w] 中存放 v 至 w 间初始权值
			for(u=0;u<c.vexnum ;u++)    //初始化最短路径 p[v][w][] 数组，第 3 个分量全部清0
				p[v][w][u]=0;
			if(d[v][w]<Infinity)        //如果 v 至 w 间有边相连
			{
				p[v][w][v]=1;           // v 是 v 至 w  最短路径上的顶点
				p[v][w][w]=1;           // w 是 v 至 w  最短路径上的顶点
			}//if
		}//for
	}//endfor

	for(u=0;u<c.vexnum ;u++) // 求v至w的最短路径及距离。对任意顶点u，试探其是否为v至w最短路径上的顶点
	{
		for(v=0;v<c.vexnum ;v++)
			for(w=0;w<c.vexnum ;w++)
			  if(d[v][u]+d[u][w]<d[v][w])  //从 v 经 u 到 w 的一条路径更短
			  {
				 d[v][w]=d[v][u]+d[u][w];  //修改 v 至 w 的最短路径长度
				 for(i=0;i<c.vexnum ;i++)  //修改 v 至 w 的最短路径数组。 若i是v至u的最短路径上的顶点,
					p[v][w][i]=p[v][u][i]||p[u][w][i]; //或i是u至w的最短路径上的顶点, 则i是v至w的最短路径上的顶点
			  }
	}//endfor
	
	printf("\n请输入出发点和目的地编号：");
	scanf("%d%d",&k,&j);
	printf("\n\n");
	while(k<0||k>c.vexnum||j<0||j>c.vexnum)
	{
		printf("\n你所输入的景点编号不存在！");
		printf("\n请重新输入出发点和目的地编号：\n\n");
		scanf("%d%d",&k,&j);
		printf("\n\n");
	}
	printf("%s",c.vexs[k].name );              //输出出发景点名称
	for(u=0;u<c.vexnum ;u++)
		if(p[k][j][u] && k!=u && j!=u)         //输出最短路径上中间景点名称
			printf("--->%s",c.vexs[u].name );
	printf("--->%s",c.vexs[j].name );          //输出目的地景点名称

	printf("\n\n\n总长为%d米\n\n\n",d[k][j]);

}//shortestpath_floyd




// (15) 查询景点的信息
	
void seeabout(mgraph c)
{	
	int k;
	printf("\n请输入要查询的景点编号：");
	scanf("%d",&k);
	while(k<0||k>c.vexnum)
	{
		printf("\n你所输入的景点编号不存在！");
		printf("\n请重新输入：");
		scanf("%d",&k);
	}
	printf("\n\n编号：%-4d\n",c.vexs[k].position );
	printf("\n\n景点名称：%-10s\n",c.vexs[k].name );
	printf("\n\n介绍：%-80s\n\n",c.vexs[k].introduction );

}//seeabout

// (16) 显示所有景点信息

void browsecompus(mgraph c)
{
	int i;
	printf(" \n\n编号      景点名称                  简介\n");
	printf("___________________________________________________________________________________________________________\n");

	for(i=0;i<c.vexnum ;i++)
	    printf("%-10d%-25s%-80s\n",c.vexs[i].position,c.vexs[i].name,c.vexs[i].introduction);
	printf("___________________________________________________________________________________________________________\n\n");

}//browsecompus

			
// (17) 主要工作函数。操作区用户界面

void mainwork()
{
	int yourchoice;
	campus=initgraph();
	printf("\n----------------------------欢迎使用校园导游程序-----------------------------\n");
	printf("\n                         欢迎来到齐齐哈尔大学!                        \n\n");
	printf("\n                               菜 单 选 择                                 \n\n");
	printf("        1. 学校景点介绍                          2. 查看游览路线               \n");
	printf("        3. 查询景点间最短路径                    4. 景点信息查询               \n");
	printf("        5. 更改图信息                            6. 查询景点间可行路径         \n");
	printf("        7. 打印邻接矩阵                          8. 退出                       \n");
	printf("\n-----------------------------------------------------------------------------\n");
    printf("请输入你的选择：");
	scanf("%d",&yourchoice);
	while(!(yourchoice==1||yourchoice==2||yourchoice==3||yourchoice==4||yourchoice==5||yourchoice==6
		  ||yourchoice==7||yourchoice==8))
	{
		printf("输入选择不明确，请重输\n");
		scanf("%d",&yourchoice);
	}
	while(1)
	{
		switch(yourchoice)
		{
			case 1:	system("cls");	browsecompus(campus);	    break;
			case 2:	system("cls");	shortestpath_dij(campus);	break;
			case 3:	system("cls");	shortestpath_floyd(campus);	break;
			case 4:	system("cls");	seeabout(campus);			break;
			case 5:	system("cls");	changegraph(campus);		break;
			case 6:	system("cls");  allpath(campus); 		    break;
			case 7: system("cls");  printmatrix(campus); 		break;
			case 8: system("cls");	exit(0); 			    	break;
			default:  break;
		}
	
	    	printf("\n----------------------------欢迎使用校园导游程序-----------------------------\n");
	        printf("\n                          欢迎来到齐齐哈尔大学!                        \n\n");
	        printf("\n                               菜 单 选 择                                 \n\n");
	        printf("        1. 学校景点介绍                          2. 查看游览路线               \n");
	        printf("        3. 查询景点间最短路径                    4. 景点信息查询               \n");
	        printf("        5. 更改图信息                            6. 查询景点间可行路径         \n");
	        printf("        7. 打印邻接矩阵                          8. 退出                       \n");
	        printf("\n-----------------------------------------------------------------------------\n");

	    printf("\n请输入你的选择：");
	    scanf("%d",&yourchoice);
	}//endwhile(1)

}//mainwork
	
// (18) 主函数。设定界面的颜色大小，调用工作区模块函数
	    
int main()
{
	system("color 1f"); //屏幕颜色设定
    system("mode con: cols=140 lines=130"); 
	mainwork();
}
