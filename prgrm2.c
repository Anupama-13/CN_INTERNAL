#include<stdio.h>
#include<string.h>
main()
{
	int i,j;
	char msg[100],crc[100],encoded[100],red[10];
	printf("Enter message");
	scanf("%s",msg);
	printf("Enter crc");
	scanf("%s",crc);
	int m=strlen(msg);
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
	strcpy(encoded,msg);
	for(i=0;i<n-1;i++)
	   red[i]='0';
	strcat(encoded,red);
	int l=strlen(encoded);
	for(i=0;i<=l-n;)
	{
		for(j=0;j<n;j++)
		   encoded[i+j]=encoded[i+j]==crc[j]?'0':'1';
		for(;i<l&&encoded[i]!='1';i++);
	}
	/*printf("Encoded %s",encoded);*/
	for(i=0;i<m;i++)
	{
		encoded[i]=msg[i];
	}
	printf(" Final message is %s",encoded);
}
