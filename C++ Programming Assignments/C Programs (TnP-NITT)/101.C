#include<stdio.h>
main()
{
	int i=1;
	printf("\n%d %d",i^=1%2,i<<=1%2);
}