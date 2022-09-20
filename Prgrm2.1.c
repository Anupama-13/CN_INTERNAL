#include<stdio.h>
#include<string.h>
main()
{
	int i,j;
	char decoded[100],crc[100];
	printf("Enter final message");
	scanf("%s",decoded);
	printf("Enter crc");
	scanf("%s",crc);
	int m=strlen(decoded);
	int n=strlen(crc);
   for(i=0;i<n;i++)
	{
		if(crc[i]=='1')
		{
			n=n-i;
			break;
		}
	}
	for(j=0;j<n;j++)
	  crc[j]=crc[j+i];
	for(i=0;i<=m-n;)
	{
		for(j=0;j<n;j++)
		   decoded[i+j]=decoded[i+j]==crc[j]?'0':'1';
		for(;i<m&&decoded[i]!='1';i++);
	}
	for(i=0;i<m;i++)
	{
		if(decoded[i]=='1')
		{
			printf("There is some error");
			break;
		}
	}
	if(i==m)
     	printf("Message is correct");
}
