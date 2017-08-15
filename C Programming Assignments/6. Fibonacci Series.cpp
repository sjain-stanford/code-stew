#include<stdio.h>
#include<conio.h>
main()
{
      int a=1,b=1,i,n;
      printf("Enter the n upto which the fibonacci series is to be generated:");
      scanf("%d",&n);
      for(i=1;i<=n/2;i++)
      {
                         printf("%d\n",a);
                         printf("%d\n",b);
                         a=a+b;
                         b=a+b;
                         }
                         getch();
                         }
