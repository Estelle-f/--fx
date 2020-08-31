//#include<iostream.h> 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define Infinity  1000
#define MaxVertexNum 35
#define MAX  40

typedef struct arcell                               //�ߵ�Ȩֵ��Ϣ
{
	int adj;                                        //Ȩֵ
}arcell,adjmatrix[MaxVertexNum][MaxVertexNum];      //ͼ���ڽӾ�������

typedef struct vexsinfo                             //������Ϣ
{
	int position;                                   //����ı��
	char name[32];                                  //���������
	char introduction[256];                         //����Ľ���
}vexsinfo;

typedef struct mgraph                               //ͼ�ṹ��Ϣ
{
	vexsinfo vexs[MaxVertexNum];                    //��������(����)
	adjmatrix arcs;                                 //�ڽӾ���
	int vexnum,arcnum;                              //�ֱ�ָ���������ͱ���
}mgraph;

//ȫ�ֱ���

int visited[35];                                    //���ڱ�־�Ƿ��Ѿ����ʹ�

int d[35];                                          //���ڴ��Ȩֵ��洢·��������

mgraph  campus;                                     //ͼ����(��ѧУ԰)


// (1) ��ͼ��ʼ��

mgraph initgraph()
{
	int i=0,j=0;
	mgraph c;
	
	c.vexnum =22;                                   //�������
	c.arcnum =40;                                   //�ߵĸ���
	for(i=0;i<c.vexnum ;i++)                        //�������ö�����
		c.vexs[i].position =i;
	//�������붥����Ϣ
		strcpy(c.vexs[0].name,"��������");
	strcpy(c.vexs[0].introduction,"��3·��15·�����ܽ�"); 
	strcpy(c.vexs[1].name,"����ͼ���");
	strcpy(c.vexs[1].introduction,"�����д������鼮���Խ���"); 
	strcpy(c.vexs[2].name,"����11��ѧ¥");
	strcpy(c.vexs[2].introduction,"����������ѧ¥");
	strcpy(c.vexs[3].name,"�칫¥");
	strcpy(c.vexs[3].introduction,"�쵼�칫�ĵط�");
	strcpy(c.vexs[4].name,"����������");
	strcpy(c.vexs[4].introduction,"���������򳡡�����");
	strcpy(c.vexs[5].name,"��ѧ¥");
	strcpy(c.vexs[5].introduction,"�����뻯ѧ����ѧԺ���Ṥ���֯ѧԺ�Ľ�ѧ¥");
	strcpy(c.vexs[6].name,"22#��Ԣ");
	strcpy(c.vexs[6].introduction,"�о�������¥");
	strcpy(c.vexs[7].name,"Уʷ��");
	strcpy(c.vexs[7].introduction,"���������ѧ�ӽ�����ʼ��������ʷ");
	strcpy(c.vexs[8].name,"2#��Ԣ");
	strcpy(c.vexs[8].introduction,"��������¥");
	strcpy(c.vexs[9].name,"ϴԡ����");
	strcpy(c.vexs[9].introduction,"ѧ��ϴ�衢����ˮ�ĵط�");
	strcpy(c.vexs[10].name,"��������");
	strcpy(c.vexs[10].introduction,"��104��101·�����ȽϽ�");
	strcpy(c.vexs[11].name,"����2��ѧ¥");
	strcpy(c.vexs[11].introduction,"���繤��ѧԺ��ѧ¥");
	strcpy(c.vexs[12].name,"����1��ѧ¥");
	strcpy(c.vexs[12].introduction,"��������ѧ¥¥���ƿ�ѧԺ�Ƚ�ѧ¥");
	strcpy(c.vexs[13].name,"����ͼ���");
	strcpy(c.vexs[13].introduction,"�д������鼮��������ϰ��");
	strcpy(c.vexs[14].name,"����������");
	strcpy(c.vexs[14].introduction,"�и��ֽ�������");
	strcpy(c.vexs[15].name,"����ʳ��");
	strcpy(c.vexs[15].introduction,"ѧ���Է��ĵط�");
	strcpy(c.vexs[16].name,"����������");
	strcpy(c.vexs[16].introduction,"�����򳡡��ﾶ�˶���");
	strcpy(c.vexs[17].name,"����¥");
	strcpy(c.vexs[17].introduction,"ѧ��ס�ĵط�");
	strcpy(c.vexs[18].name,"����15��ѧ¥");
	strcpy(c.vexs[18].introduction,"�����ļ���������˼����ѧԺ��ѧ¥");
	strcpy(c.vexs[19].name,"����ʳ��");
	strcpy(c.vexs[19].introduction,"�Ա�����������ĺ������ѵ����"); 
	strcpy(c.vexs[20].name,"�Ļ���");
	strcpy(c.vexs[20].introduction,"�ݳ����ݽ��ĵط�"); 
	strcpy(c.vexs[21].name,"��������");
	strcpy(c.vexs[21].introduction,"�����Ͷ����ȽϽ�"); 
	
	
		//����������ϵ�Ȩֵ��Ϣ
        for(i=0;i<c.vexnum ;i++)
			for(j=0;j<c.vexnum ;j++)
				c.arcs [i][j].adj =Infinity; //�ȳ�ʼ��ͼ���ڽӾ���
        
		//���ֻ���
		
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

        for(i=0;i<c.vexnum ;i++)                      //�ڽӾ����ǶԳƾ��󣬶ԳƸ�ֵ
			for(j=0;j<c.vexnum ;j++)
				c.arcs[j][i].adj =c.arcs[i][j].adj ;
		return c;
}//initgraph


// (2) ���Ҿ�����ͼ�е����

int locatevex(mgraph c,int v)
{
	int i;
	for(i=0;i<c.vexnum ;i++)
		if(v==c.vexs[i].position)
			return i;                           //�ҵ������ض������i
	
    return -1;                                  //���򣬷���-1
}


//(3) ��(4) ��������������·��

// (3) ��ӡ���Ϊm,n�����ĳ��Ȳ�����8�������·��

void path(mgraph c, int m,int n,int k)
{
    int s,x=0;
	int t=k+1;                                  //t ����·������һ���м䶥����d[]�����е��±�
	if(d[k]==n && k<8)                          //d[k]�洢·�����㡣��d[k]���յ�n�Ҿ������<=8���������·��
	{                                           //�ݹ���ڣ��ҵ�һ��·��
      for(s=0;s<k;s++)
		printf("%s--->",c.vexs[d[s]].name);     //�����·����s=0 ʱΪ���m
      printf("%s",c.vexs[d[s]].name);           //������һ��������(������n�����֣���ʱs==k)
      printf("\n\n");
    }
    else
	{
	  s=0;
      while(s<c.vexnum)                         //�ӵ�m�����㣬��̽�����ж����Ƿ���·��
	  {
		if((c.arcs[d[k]][s].adj<Infinity) && (visited[s]==0)) //��̬������m������s�бߣ���δ������
		{
	       visited[s]=1;
	       d[k+1]=s;                //�洢������s ��d[k+1]��
	       path(c,m,n,t);           //����±�Ϊt=k+1�ĵ�d[t]�����㿪ʼ��·��(�ݹ����)��ͬʱ��ӡ��һ��m��n��·��
	       visited[s]=0;            //���ҵ���·���϶���ķ��ʱ�־��������Ϊ0����������̽�µ�·��
		}
		s++;                        //��̽����һ������ s ��ʼ�Ƿ��е��յ��·��
	  }//endwhile
	  
	}//endelse

}//endpath

//(4) ��ӡ�������ľ������������8������·��������(3)

int allpath(mgraph c)
{
  int k,i,j,m,n;
  printf("\n\n��������Ҫ��ѯ������������:\n\n");
  scanf("%d%d",&i,&j);
  printf("\n\n");
  m=locatevex(c,i);                         //����(2)��ȷ���ö����Ƿ���ڡ������ڣ����ظö�����
  n=locatevex(c,j);
  d[0]=m;                                   //�洢·�����m (int d[]������ȫ�ֱ���)
  for(k=0;k<c.vexnum;k++)                   //ȫ��������ʱ�־��ֵ��Ϊ0
    visited[k]=0;
  visited[m]=1;                             //��m��������ʱ�־����Ϊ1
  path(c,m,n,0);                            //����(3)��k=0����Ӧ���d[0]==m��kΪd[]�����±�
  return 1;
}


// (5) �õϽ�˹�����㷨�����һ�����㵽�������������·��������ӡ

void shortestpath_dij(mgraph c)
{
  //�Ͻ�˹�����㷨����Ӷ���v0�����ඥ������·�������Ȩ����d[v]
  //��p[v][w]Ϊ1����w�Ǵ�v0��v�����·���ϵĶ���
  //final[v]�����������÷��ʱ�־
		
	int v,w,i,min,t=0,x,flag=1,v0;                //voΪ��ʼ����ı��
	int final[35],d[35],p[35][35];
	printf("\n������һ����ʼ����ı�ţ�");
	scanf("%d",&v0);
    printf("\n\n");
	while(v0<0||v0>c.vexnum)
	{
	    printf("\n��������ľ����Ų�����\n");
	    printf("���������룺");
	    scanf("%d",&v0);
	}//while
	for(v=0;v<c.vexnum ;v++)
	{
		final[v]=0;                               //��ʼ����������ʱ�־
		d[v]=c.arcs[v0][v].adj;                   //v0 �������� v ��Ȩֵ��ֵ��d[v]
		for(w=0;w<c.vexnum ;w++)                  //��ʼ��p[][]���飬��������·��ȫ������Ϊ��·��0
			p[v][w]=0;
		if(d[v]<Infinity)                         //v0 ��v �б��������޸�p[v][v0]��ֵΪ1
		{
			p[v][v0]=1;
			p[v][v]=1;                            //�������Լ����Լ�Ҫ��ͨ
		}
	}//for
	d[v0]=0;                                      //�Լ����Լ���Ȩֵ��Ϊ0
	final[v0]=1;                                  //v0�ķ��ʱ�־��Ϊ1��v ���� s ��
	for(i=1;i<c.vexnum ;i++)                      //������c.vexnum-1������w�������� v �� w �����·��
	{
		min=Infinity;
		for(w=0;w<c.vexnum ;w++)                  //��δ�����ʵĶ����У������� v0 ����Ķ���v
			if(!final[w])
				if(d[w]<min)                      //v0 �� w (�б�)��Ȩֵ<min
				{
					v=w;
					min=d[w];
				}//if
		final[v]=1;                                  //v �ķ��ʱ�־����Ϊ1��v ����s��
		for(w=0;w<c.vexnum ;w++)                     //�޸�v0 �����������w �����·��Ȩֵd[w]
			if(!final[w]&&(min+c.arcs[v][w].adj <d[w]))  //��w ������s����v ��w �б�����
			{
				d[w]=min+c.arcs[v][w].adj;               //�޸�v0 ��w ��Ȩֵd[w]
				for(x=0;x<c.vexnum ;x++)             //����v0 ��v �����·���ϵĶ���x������v0 ��w �����·���ϵĶ���
					p[w][x]=p[v][x];
				p[w][w]=1;
			}//if
	}//for
	for(v=0;v<c.vexnum ;v++)                         //���v0 ����������v �����·��
	{
		if(v!=v0)
		    printf("%s",c.vexs[v0].name);            //�������v0 �ľ�����
		for(w=0;w<c.vexnum ;w++)                     //��ͼ��ÿ������w����̽w �Ƿ���v0 ��v �����·���ϵĶ���
		{
		    if(p[v][w] && w!=v0 && w!=v)             //��w ����w ������v0��������þ���
				  printf("--->%s",c.vexs[w].name);
			 
		}
		printf("---->%s",c.vexs[v].name);  
		printf("\n��·�߳�Ϊ%d��\n\n",d[v]);
		
		
		
	}//for
}//shortestpath_dij 


//(6)-(11)�޸�ͼ����Ϣ��������ͼ��������Ϣ��ɾ�������ӽ��ͱ�
			  
//(6) ����ͼ���ڽӾ���
	
 int creatgragh(mgraph &c)                          //��ͼ����ͼ���ڽӾ���洢ͼ
 {
	int i,j,m,n;
	int v0,v1;
	int distance;
	printf("������ͼ�Ķ������ͱ���: \n");
	scanf("%d %d",&c.vexnum ,&c.arcnum );
	printf("���������뾰�����Ϣ��\n");
	for(i=0;i<c.vexnum ;i++)                       //���춥������(����)
	{
		printf("�����뾰��ı�ţ�");
		scanf("%d",c.vexs[i].position );
		printf("\n�����뾰������ƣ�");
        scanf("%s",c.vexs[i].name );
		printf("\n�����뾰��ļ�飺");
		scanf("%s",c.vexs[i].introduction );
	}
	for(i=0;i<c.arcnum ;i++)                       //��ʼ���ڽӾ���
		for(j=0;j<c.arcnum ;j++)
			c.arcs[i][j].adj =Infinity;
	
	printf("����������ͼ�ıߵ���Ϣ��\n");
	for(i=1;i<=c.arcnum ;i++)                      //�����ڽӾ���
	{
		printf("\n��%d���ߵ���� �յ� ����Ϊ��",i);//����һ���ߵ���㡢�յ㼰Ȩֵ
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
    
	 
// (7) ����ͼ�Ĳ�����Ϣ������ֵ: 1

int  newgraph(mgraph &c)
{
	int changenum;                                //���������ڼ�¼Ҫ�޸ĵĶ���ĸ���
	int i,m,n,t,distance,v0,v1;
	printf("\n������������Ҫ�޸ĵľ���ĸ�����\n");
	scanf("%d",&changenum);
	while(changenum<0||changenum>c.vexnum )
	{
		printf("\n�����������������");
		scanf("%d",&changenum);
	}

	for(i=0;i<changenum;i++)
	{
		printf("\n�����뾰��ı�ţ�");
		scanf("%d",&m);
		t=locatevex(c,m);
		printf("\n�����뾰������ƣ�");
        scanf("%s",c.vexs[t].name );
		printf("\n�����뾰��ļ�飺");
		scanf("%s",c.vexs[t].introduction );
	}
	
	printf("\n������������Ҫ���µı���");
	scanf("%d",&changenum);
	while(changenum<0||changenum>c.arcnum )
	{
		printf("\n�����������������");
		scanf("%d",&changenum);
	}
    
	printf("\n������������±ߵ���Ϣ��\n");
	for(i=1;i<=changenum ;i++)
	{
		printf("\n�޸ĵĵ�%d���ߵ���� �յ� ����Ϊ��",i);
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

// (8) ����һ���ߡ�����ֵ��1

int enarc(mgraph &c)
{
	int m,n,distance;
	printf("\n������ߵ������յ���,Ȩֵ��");
    scanf("%d %d %d",&m,&n,&distance);
	while(m<0||m>c.vexnum ||n<0||n>c.vexnum )
	{
		printf("����������������룺");
		scanf("%d %d",&m,&n);
	}
	if(locatevex(c,m)<0)
	{
		printf("�˽��%d��ɾ��",m);
		return 1;
	}
	if(locatevex(c,n)<0)
	{
		printf("�˽��%d�ѱ�ɾ����",n);
		return 1;
	}
	c.arcs[m][n].adj =distance;
    c.arcs[n][m].adj =c.arcs[m][n].adj;                 //�ԳƸ�ֵ
	return 1;
}//enarc

// (9) ����һ����㡣����ֵ��1

int envex(mgraph &c)
{
	int i;
	printf("��������Ҫ���ӽ�����Ϣ��");
	printf("\n��ţ�");
	scanf("%d",&c.vexs[c.vexnum ].position );
	printf("���ƣ�");
	scanf("%s",c.vexs[c.vexnum ].name );
	printf("��飺");
	scanf("%s",c.vexs[c.vexnum ].introduction) ;
	c.vexnum ++;
	for(i=0;i<c.vexnum;i++)                           //��ԭ�ڽӾ��������ӵ�һ�м�һ�н��г�ʼ��
	{
		c.arcs [c.vexnum -1][i].adj=Infinity;         //���һ��(������һ��)
		c.arcs [i][c.vexnum -1].adj=Infinity;         //���һ��(������һ��)
	}
	return 1;
}//envex
    
// (10) ɾ��ͼ��һ�����㡣����ֵ��1

int delvex(mgraph &c)
{
	int i=0,j;
	int m;
	int v;
	if(c.vexnum <=0)
	{
		printf("ͼ�����޶���");
		return 1;
	}
	printf("\n������������Ҫɾ���ľ����ţ�");
	scanf("%d",&v);
	while(v<0||v>c.vexnum  )
	{
		printf("\n�����������������");
		scanf("%d",&v);
	}
	m=locatevex(c,v);
	if(m<0)
	{
		printf("�˶��� %d ��ɾ��",v);
		return 1;
	}
	for(i=m;i<c.vexnum-1 ;i++)//�Զ�����Ϣ����˳������ɾ��m ��Ĳ���
	{
		strcpy(c.vexs[i].name ,c.vexs [i+1].name );
		strcpy(c.vexs[i].introduction ,c.vexs [i+1].introduction );
	}
	//��ԭ�ڽӾ���ɾ���ö��㵽���ඥ����ڽӹ�ϵ���ֱ�ɾ����Ӧ���к���
	for(i=m;i<c.vexnum-1 ;i++)                //��
		for(j=0;j<c.vexnum ;j++)              //��
			c.arcs [i][j]=c.arcs [i+1][j];    //��ά���飬�ӵ�m+1�п�ʼ������ǰ��һ�С���ɾ����m ��
	for(i=m;i<c.vexnum-1 ;i++)
		for(j=0;j<c.vexnum ;j++)
            c.arcs [j][i]=c.arcs [j][i+1];    //��ά���飬�ӵ�m+1�п�ʼ������ǰ��һ�С���ɾ����m ��
	c.vexnum --;
	return 1;
}//delvex
	
 //(11) ɾ��ͼ��һ���ߡ�����ֵ��1
	 
int delarc(mgraph &c)
{
	int m,n;
	int v0,v1;
	if(c.arcnum <=0)
	{
		printf("ͼ�����ޱߣ��޷�ɾ����");
		return 1;
	}
	printf("\n������������Ҫɾ���ıߵ������յ��ţ�");
	scanf("%d %d",&v0,&v1);
    m=locatevex(c,v0);
	if(m<0)
	{
		printf("�� %d ������ɾ��",v0);
		return 1;
	}
	n=locatevex(c,v1);
	if(n<0)
	{
		printf("�� %d ������ɾ��",v1);
		return 1;
	}
	c.arcs [m][n].adj =Infinity;              //�޸��ڽӾ����Ӧ��Ȩֵ
    c.arcs [n][m].adj =Infinity;
	c.arcnum --;
	return 1;
}//delarc

// (12) ���ͼ���ڽӾ����ֵ

void printmatrix(mgraph c)
{
	int i,j,k=0;                              //k ���ڼ��������ƻ���

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

//(13)ͼ��������������������ֵ��1
    
int changegraph(mgraph &c)
{
				
	int yourchoice;
	printf("\n������Ҫ\n\n     (1)�ٴν�ͼ       (2)ɾ�����         (3)ɾ����\n");
	printf("\n(4)���ӽ��      (5)���ӱ�         (6)������Ϣ\n\n     (7)��ӡ�ڽӾ���     (8)����?\n\n");

	scanf("%d",&yourchoice);
    printf("\n\n");
	while(!(yourchoice==1||yourchoice==2||yourchoice==3||yourchoice==4||yourchoice==5||yourchoice==6
		  ||yourchoice==7||yourchoice==8))
	{
		printf("����ѡ����ȷ��������\n");
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
	    printf("\n������Ҫ\n\n   (1)�ٴν�ͼ         (2)ɾ�����          (3)ɾ����\n");
	    printf("\n(4)���ӽ��    (5)���ӱ�           (6)������Ϣ\n\n      (7)��ӡ�ڽӾ���     (8)����?\n\n");

	    scanf("%d",&yourchoice);
        printf("\n\n");
		while(!(yourchoice==1||yourchoice==2||yourchoice==3||yourchoice==4||yourchoice==5||yourchoice==6
			  ||yourchoice==7||yourchoice==8))
		{
			printf("����ѡ����ȷ��������\n");
			scanf("%d",&yourchoice);
		}
	}//endwhile(1)

	return 1;
}//changegraph
	 
// (14) ��ѯ�����������·��

void shortestpath_floyd(mgraph c)
{
	//��floyd�㷨����Զ���v��w������·�������Ȩ���ȵ�d[v][w]��
	//��p[v][w][u]==1����u��v��w�ĵ�ǰ��õ����·���ϵĶ���

	int i,j,k,d[35][35],p[35][35][35];
	int v,u,w; 
	for(v=0;v<c.vexnum ;v++)            //��ʼ�����Զ��� v��w ֮�����ʼ���� d[v][w] �� ·�� p[v][w][] ����
	{
		for(w=0;w<c.vexnum ;w++)
		{
			d[v][w]=c.arcs[v][w].adj;   //d[v][w] �д�� v �� w ���ʼȨֵ
			for(u=0;u<c.vexnum ;u++)    //��ʼ�����·�� p[v][w][] ���飬�� 3 ������ȫ����0
				p[v][w][u]=0;
			if(d[v][w]<Infinity)        //��� v �� w ���б�����
			{
				p[v][w][v]=1;           // v �� v �� w  ���·���ϵĶ���
				p[v][w][w]=1;           // w �� v �� w  ���·���ϵĶ���
			}//if
		}//for
	}//endfor

	for(u=0;u<c.vexnum ;u++) // ��v��w�����·�������롣�����ⶥ��u����̽���Ƿ�Ϊv��w���·���ϵĶ���
	{
		for(v=0;v<c.vexnum ;v++)
			for(w=0;w<c.vexnum ;w++)
			  if(d[v][u]+d[u][w]<d[v][w])  //�� v �� u �� w ��һ��·������
			  {
				 d[v][w]=d[v][u]+d[u][w];  //�޸� v �� w �����·������
				 for(i=0;i<c.vexnum ;i++)  //�޸� v �� w �����·�����顣 ��i��v��u�����·���ϵĶ���,
					p[v][w][i]=p[v][u][i]||p[u][w][i]; //��i��u��w�����·���ϵĶ���, ��i��v��w�����·���ϵĶ���
			  }
	}//endfor
	
	printf("\n������������Ŀ�ĵر�ţ�");
	scanf("%d%d",&k,&j);
	printf("\n\n");
	while(k<0||k>c.vexnum||j<0||j>c.vexnum)
	{
		printf("\n��������ľ����Ų����ڣ�");
		printf("\n����������������Ŀ�ĵر�ţ�\n\n");
		scanf("%d%d",&k,&j);
		printf("\n\n");
	}
	printf("%s",c.vexs[k].name );              //���������������
	for(u=0;u<c.vexnum ;u++)
		if(p[k][j][u] && k!=u && j!=u)         //������·�����м侰������
			printf("--->%s",c.vexs[u].name );
	printf("--->%s",c.vexs[j].name );          //���Ŀ�ĵؾ�������

	printf("\n\n\n�ܳ�Ϊ%d��\n\n\n",d[k][j]);

}//shortestpath_floyd




// (15) ��ѯ�������Ϣ
	
void seeabout(mgraph c)
{	
	int k;
	printf("\n������Ҫ��ѯ�ľ����ţ�");
	scanf("%d",&k);
	while(k<0||k>c.vexnum)
	{
		printf("\n��������ľ����Ų����ڣ�");
		printf("\n���������룺");
		scanf("%d",&k);
	}
	printf("\n\n��ţ�%-4d\n",c.vexs[k].position );
	printf("\n\n�������ƣ�%-10s\n",c.vexs[k].name );
	printf("\n\n���ܣ�%-80s\n\n",c.vexs[k].introduction );

}//seeabout

// (16) ��ʾ���о�����Ϣ

void browsecompus(mgraph c)
{
	int i;
	printf(" \n\n���      ��������                  ���\n");
	printf("___________________________________________________________________________________________________________\n");

	for(i=0;i<c.vexnum ;i++)
	    printf("%-10d%-25s%-80s\n",c.vexs[i].position,c.vexs[i].name,c.vexs[i].introduction);
	printf("___________________________________________________________________________________________________________\n\n");

}//browsecompus

			
// (17) ��Ҫ�����������������û�����

void mainwork()
{
	int yourchoice;
	campus=initgraph();
	printf("\n----------------------------��ӭʹ��У԰���γ���-----------------------------\n");
	printf("\n                         ��ӭ�������������ѧ!                        \n\n");
	printf("\n                               �� �� ѡ ��                                 \n\n");
	printf("        1. ѧУ�������                          2. �鿴����·��               \n");
	printf("        3. ��ѯ��������·��                    4. ������Ϣ��ѯ               \n");
	printf("        5. ����ͼ��Ϣ                            6. ��ѯ��������·��         \n");
	printf("        7. ��ӡ�ڽӾ���                          8. �˳�                       \n");
	printf("\n-----------------------------------------------------------------------------\n");
    printf("���������ѡ��");
	scanf("%d",&yourchoice);
	while(!(yourchoice==1||yourchoice==2||yourchoice==3||yourchoice==4||yourchoice==5||yourchoice==6
		  ||yourchoice==7||yourchoice==8))
	{
		printf("����ѡ����ȷ��������\n");
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
	
	    	printf("\n----------------------------��ӭʹ��У԰���γ���-----------------------------\n");
	        printf("\n                          ��ӭ�������������ѧ!                        \n\n");
	        printf("\n                               �� �� ѡ ��                                 \n\n");
	        printf("        1. ѧУ�������                          2. �鿴����·��               \n");
	        printf("        3. ��ѯ��������·��                    4. ������Ϣ��ѯ               \n");
	        printf("        5. ����ͼ��Ϣ                            6. ��ѯ��������·��         \n");
	        printf("        7. ��ӡ�ڽӾ���                          8. �˳�                       \n");
	        printf("\n-----------------------------------------------------------------------------\n");

	    printf("\n���������ѡ��");
	    scanf("%d",&yourchoice);
	}//endwhile(1)

}//mainwork
	
// (18) ���������趨�������ɫ��С�����ù�����ģ�麯��
	    
int main()
{
	system("color 1f"); //��Ļ��ɫ�趨
    system("mode con: cols=140 lines=130"); 
	mainwork();
}
