#include<stdio.h>
main()
{
	unsigned char ch;
	FILE *fp;
	fp=fopen("trial","r");
	while((ch=getc(fp))!=EOF)
		printf("%c",ch);
    fclose(fp);
}