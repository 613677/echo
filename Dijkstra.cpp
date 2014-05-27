
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
