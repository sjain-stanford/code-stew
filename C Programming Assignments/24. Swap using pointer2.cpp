#include<stdio.h>
#include<conio.h>
main()
{
      int a,b;
      printf("Enter two numbers: ");
      scanf("%d %d",&a,&b);
      int *s,*t;
      s=&a;
      t=&b;
      int x;
      x=a;
      a=b;
      b=x;
      printf("The swapped values are: %d %d",*s,*t);
      getch();
      }
      
