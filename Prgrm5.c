#include<stdio.h>
struct router
{
   unsigned dist[20];
   unsigned from[20];
}rt[10];

main()
{
    int cost[20][20];
    int n,i,j,k,count=0;
    printf("\nEnter the number of nodes : ");
    scanf("%d",&n);
    printf("\nEnter the cost matrix :\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&cost[i][j]);
		cost[i][i]=0;
		rt[i].dist[j]=cost[i][j];
		rt[i].from[j]=j;
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	for(k=1;k<=n;k++)
	if(rt[i].dist[j]>cost[i][k]+rt[k].dist[j])
	{
		rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
		rt[i].from[j]=k;
	}
	for(i=1;i<=n;i++)
	{
		printf("\n\nState value for router %d is \n",i);
		for(j=1;j<= n;j++)
		{
			printf("\t\nnode %d via %d Distance%d",j,rt[i].from[j],rt[i].dist[j]);
		}
	}

}
