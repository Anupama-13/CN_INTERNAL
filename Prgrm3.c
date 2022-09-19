#include<stdio.h>
main()
{
	int i,j,n,s,min=999,next;
	int cost[10][10],dist[10],path[10],visited[10];
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	printf("\nEnter cost matrix: ");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(i==j)
			   cost[i][j]=0;
			if(cost[i][j]==-1)
			   cost[i][j]=999;
		}
	}
	printf("\nEnter source vertex");
	scanf("%d",&s);
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
		path[i]=s;
		dist[i]=cost[s][i];
	}
	dist[s]=0;
	visited[s]=1;
	int count=1;
	while(count<n)
	{
		for(i=1;i<=n;i++)
		{
			if(dist[i]<min && visited[i]!=1)
			{
				min=dist[i];
				next=i;
			}
		}
		visited[next]=1;
		for(i=1;i<=n;i++)
		{
			if(visited[i]!=1)
			{
			if(dist[i]>(min+cost[next][i]))
			{
				dist[i]=min+cost[next][i];
				path[i]=next;
			}
		   }
		}
		count++;		
	}
	printf("\nPath Matrix : \n");
	printf("\nDistance  Node  Path\n");
	for(i=1;i<=n;i++)
	{
		printf("\n%d",dist[i]);
		printf("\t%d",i);
		j=i;
		do
		{
			printf("-->%d",path[j]);
			next=path[j];
			j=next;
		}while(next!=s);
	}	
}
