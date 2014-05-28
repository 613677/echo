
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<process.h>
#include<iostream>

void m(void);		//平面图	
void m2(void);		//主菜单
void m3(void);     //副菜单

#define max     500
#define num     50
#define maxdist 10000

typedef struct ZJGSU
{            
     int  code;
     char name[num];
     char pr[num];
}ZJGSU; /*定义结构体所包含的景点代码、名称、简介*/

/*Dijkstra算法求最短路径*/
void shortestpath( int c[num][num],int n,int i,int d[num],int p[num])            
{						/*c[]用来存放十个景点*/
     int s[num];		/*s[]代表标志，若到此一游，则变为1，否则为0*/
     int mindist;		/*p[]表示最短路径中该景点的前一个顶点的数值*/
     int j,k,u;			/*d[]表示两景点间的路程*/				
     for(j=0;j<n;j++)
	 {
		 d[j]=c[i][j];
		 s[j]=0;
		 if(d[j]<maxdist&&d[j]!=0)
			 p[j]=i;
		 else
			 p[j]=-1;
     }
		 s[i]=1;
		 for(j=0;j<n-1;j++)
		 {
			 mindist=maxdist;
			 u=i;
			 for(k=0;k<n;k++)
				if(s[k]==0&&d[k]<mindist)
				{
					u=k;
					mindist=d[k];
				}
			    s[u]=1;
				for(k=0;k<n;k++)
					if(s[k]==0&&d[u]+c[u][k]<d[k])
					{
						d[k]=d[u]+c[u][k];
						p[k]=u;
					}
		 }
}

/*输出最短路径和最短距离*/
void input(int v,int n,int d[],int p[])                        
{
	int i,pre;
    for(i=0;i<n;i++)
		if(i!=v)
		{
			printf("\n%d",i);
			pre=p[i];
			while(pre!=-1)
			{
				printf("<--%d",pre);			/*输出最短路径所经过的景点*/
				pre=p[pre];
			}
			if(d[i]==maxdist)
				printf("<--%d",v);
			printf("	最短路径为:%d",d[i]);	/*输出最短距离*/
      }		
}

//程序主函数
int main()                                                     
{
     ZJGSU pl[11]={{0,"综合大楼","学校的标志性建筑，学校行政事务处理中心"},{1,"图书馆","不仅仅是阅读和学习"},
					{2,"剧院","学生活动中心"},{3,"信息学院","程序猿，不解释"},
					{4,"墨湖","听荷论道"},{5,"鸽子广场","放的不是鸽子,是梦想!"},
					{6,"球门","学校大门"},{7,"经济学院","虚拟经济"},
					{8,"第一田径场","足球场，篮球场，塑胶跑道，用于学生日常锻炼休闲"},{9,"金沙港","生活园区二"},
	 {10,"钱江湾","生活园区一"}};		/*景点包含的信息*/ 
     int i,j,n=11;
     char s;
     int d[num],p[num],a[num][num];
     for(i=0;i<n;i++)                      
		for(j=0;j<n;j++)
			a[i][j]=maxdist;
		/*给景点之间的路径赋最大值*/

	 a[0][1]=15;a[0][2]=10;a[0][3]=15;a[0][4]=10;a[0][5]=30;
	 a[1][0]=15;a[1][4]=10;                                    
     a[2][0]=10;a[2][4]=10;a[2][6]=15;a[2][7]=10;
	 a[3][0]=15;a[3][5]=30;
	 a[4][0]=10;a[4][1]=10;a[4][2]=10;a[4][6]=10;
	 a[5][0]=30;a[5][3]=30;a[5][6]=45;
	 a[6][2]=15;a[6][4]=10;a[6][5]=45;a[6][9]=50;a[6][10]=5;
	 a[7][2]=20;a[7][8]=20;a[7][9]=30;
	 a[8][7]=20;a[9][6]=50;a[9][7]=30;a[9][10]=55;a[10][6]=5;a[10][9]=55;
	 /*自定义景点间路径长度*/

	 printf("  ########################################\n");
	 printf("  ##                                    ##\n");
	 printf("  ##   浙江工商大学下沙校区校园导游图   ##\n");
	 printf("  ##                                    ##\n");
	 printf("  ##                                    ##\n");
	 printf("  ########################################\n");			 	  
	 m2();	     	//主菜单
     do
     {
		 switch(getchar())
		 {
            case'a':  /*景点名称和简介查询*/
			{ 
				while(1)
				{
					m3();	//副菜单
                    scanf("%d",&i);
                    if(i<0||i>10)          /*输入非0~10退出*/ 
					{   
						printf("该景点不存在!\n");
					    m2();    		//主菜单
                        break;
					}   
                    printf("%s-------%s\n",pl[i].name,pl[i].pr);
				}
			}break;
            case'b': 
			{             /*输入景点代码查到其它景点的最短距离*/
				do
				{
					m3();	    //副菜单
                    scanf("%d",&i);
                    if(i<0||i>10)         /*输入非0~10退出*/   
					{    
						printf("该景点不存在!\n");
					    m2();	  	//主菜单
                        break;
					}
                    shortestpath(a,n,i,d,p);
                    printf("\n\n所有的最短路径分别为:\n");
                    input(i,n,d,p); 
				} 
				while(1);
			}break;
			case'h':
				{
					while(1)
					{
						m();
						break;
					}
				}break;
			default: exit(1);
		 }
	 }
	 while(getchar());
	 s=getchar();
     if(s=='p')exit(0);
	 return 0;
	 
}

void m2(void)			//主菜单
{
	printf("************************************************\n");
	printf("      ~~~菜单选择~~~\n");
	printf("    查询景点简介,请输入a\n");
	printf("    查询某一点到其他景点的最短路径,请输入b\n");
    printf("    如需查看校园平面图,请输入h\n");
	printf("************************************************\n");
}
void m3(void)			//副菜单
{
	printf("\n\n请输入指定景点代表的数字 0~10:\n");
	printf("如果想返回主菜单，请输入0~10以外的数\n\n");
}
void m(void)
{
	printf("               9		");			printf("0—>综合大楼\n");
	printf("              /|		");			printf("1—>图书馆\n");
	printf("       8     / |		");			printf("2—>剧院\n");		
	printf("        \\   /  |		");			printf("3—>信息学院\n");		
	printf("         \\ /   |		");			printf("4—>墨湖\n");	
	printf("          7    |		");			printf("5—>鸽子广场\n");
	printf("          |    |		");			printf("6—>球门\n");	
	printf("          |    |		");			printf("7—>管理学院\n");
	printf("          2    |		");			printf("8—>第一田径场\n");
	printf("         /|\\   |		");			printf("9—>金沙港\n");	
	printf("        / | \\  |                ");			printf("10—>钱江湾\n");
	printf("   3---0--4--6-10\n");
	printf("   |   |\\ |  |\n");			
	printf("   |   | \\|  |\n");			
	printf("   |   |  1  |\n");	  			
	printf("   |   |     |\n");
	printf("   |   |     |\n");
	printf("   |   |     |\n");
	printf("   \\---5-----/\n\n");
}
