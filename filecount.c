#include<stdio.h>
int main()
{
	int i,count=0;
	char ch;

	FILE*fp=fopen("testfile.txt","r");
	
	for(i=0;ch!=EOF;i++)
	{
		ch=fgetc(fp);
		if(ch=='\n')
		count++;
	}
	
	printf("the no. of charactes in file are : %d\n",i);
	printf("the no. of lines in file are : %d\n",count);
	
	fclose(fp);
	
	return 0;
}
