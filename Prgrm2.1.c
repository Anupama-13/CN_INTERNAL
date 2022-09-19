#include<stdio.h>
#include<string.h>
main()
{
	int i,j;
	char msg[100],crc[100],decoded[100],red[10];
	printf("Enter final message");
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
	strcpy(decoded,msg);
	for(i=0;i<n-1;i++)
	   red[i]='0';
	strcat(decoded,red);
	int l=strlen(decoded);
	for(i=0;i<=l-n;)
	{
		for(j=0;j<n;j++)
		   decoded[i+j]=decoded[i+j]==crc[j]?'0':'1';
		for(;i<l&&decoded[i]!='1';i++);
	}
	/*printf("Encoded %s",encoded);*/
	for(i=0;i<l;i++)
	{
		if(decoded[i]=='1')
		{
			printf("There is some error");
			break;
		}
	}
	if(i==l)
     	printf("Message is correct");
}
