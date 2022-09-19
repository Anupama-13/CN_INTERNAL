#include<stdio.h>
struct data
{
	char line[10],dest[10];
	int hop;
}d[10];
main()
{
	int n,min,minver,i;
	char sv[2],temp;
	printf("Enter numer of vertices : ");
	scanf("%d",&n);
	printf("\nEnter source vertex: ");
	scanf("%s",&sv);
	printf("\nEnter routing table for source vertex :(Dest,line,hop) \n");
	for(i=0;i<n;i++)
	{
		scanf("%s%s%d",d[i].dest,d[i].line,&d[i].hop);
	}
	printf("\n Hierarchical table \n");
	for(i=0;i<n;)
	{
		if(sv[0]==d[i].dest[0])
		{
			printf("\n%s %s %d",d[i].dest,d[i].line,d[i].hop);
			i++;
		}
		else
		{
			min=1000,minver=0;
			temp=d[i].dest[0];
			while(temp==d[i].dest[0])
			{
				if(min>d[i].hop)
				{
					min=d[i].hop;
					minver=i;
				}
				i++;
			}
			printf("\n%c %s %d",temp,d[minver].line,d[minver].hop);
		}
	}
}
