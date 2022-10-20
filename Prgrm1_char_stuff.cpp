/* program for character stuffing and destuffing */
#include<stdio.h>
#include<string.h>
main()
{
	int i,j,k,c=0,l;
	char in[50],stuff[50];
	printf("Enter the input string\n");
	gets(in);
	l=strlen(in);
	char start[7]="dlestx";
	char end[7]="dleetx";
	strcpy(stuff,start);
	strcat(stuff,in);
	strcat(stuff,end);
	printf("After stuffing\n");
	printf("%s",stuff);
	
	/* now destuffing*/
	char destuff[50],temp[50];
	int len=strlen(stuff);
	for (i=6,j=0;i<len;i++,j++)
	{
		temp[j]=stuff[i];	
	}
	for(i=0,j=0;i<strlen(temp)-6;i++,j++)
	{
		destuff[j]=temp[i];
	}
	printf("\nAfter de stuffing\n");
	printf("%s",destuff);
}
