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
