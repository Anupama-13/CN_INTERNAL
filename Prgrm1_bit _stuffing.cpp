/* Program for bit stuffing and de stuffing */

#include<stdio.h>
#define MS 100
 main()
 {
 	char *p,*q;
 	char t;
 	char in[MS];
 	char stuff[MS];
 	char destuff[MS];
 	int count=0;
 	printf("Enter character string :\n");
 	scanf("%s",in);
 	p=in;
 	q=stuff;
 	while(*p!='\0')
 	{
 		if(*p=='0')
		 {
		 	*q=*p;
		 	q++;
		 	p++;
		 }
		 else
		 {
		 	while(*p=='1'&&count!=5)
		 	{
		 		count++;
		 		*q=*p;
		 		q++;
		 		p++;
			 }
			 if(count==5)
			 {
			 	*q='0';
			 	q++;
			 }
			 count=0;
		 }
	 }
	 *q='\0';
	 printf("The character string after stuffing is\n");
	 printf("%s",stuff);
	 
	 /* Now destuffing the stuffed string*/
	 p=stuff;
	 q=destuff;
	 while(*p!='\0')
	 {
	 	if(*p=='0')
	 	{
	 		*q=*p;
	 		q++;
			 p++;
		}
	 	else
	 	{
	 		while(*p=='1' && count<5)
	 		{
	 			count++;
	 			*q=*p;
	 			p++;
	 			q++;
		 	}
		 	if(count==5)
		 	{
		 		p++;
			 }
		 	count=0;
		}
	}
	*q='\0';
	printf("\nThe destuffed character string is \n");
	printf("%s",destuff);	 
 	
 }
