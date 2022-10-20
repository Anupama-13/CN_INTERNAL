#include<stdio.h>
#include<string.h>
main()
{
	char in[50],stuff[50],destuff[50];
	int i,j,fs,nf,tf,l,t;
	printf("Enter string\n");
	scanf("%s",in);
	l=strlen(in);
	printf("Enter frame size\n");
	scanf("%d",&fs);
	t=fs;
	tf=fs-1;
	nf=(l/tf)+1;
	j=0;
	for(i=0;i<(l+nf);i++)
	{
		if(i%fs==0)
		{
			if((l-j)<fs)
			{
				fs=l-j+1;
			}
			stuff[i]=(char)(48+fs);
			fs=t;
		}
		else
		{
			stuff[i]=in[j];
			j++;
			
		}
	}
	stuff[l+nf]='\0';
	printf("Stuffed data is\n");
	printf("%s",stuff);
	
	//Destuffing
	j=0;
	for(i=0;i<(l+nf);i++)
	{
		if(i%fs!=0)
		{
			destuff[j]=stuff[i];
			j++;
		}
	}
	printf("\nDestuffed data is\n");
	printf("%s",destuff);
}
