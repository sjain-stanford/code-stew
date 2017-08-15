#include<stdio.h>
#include<conio.h>
main()
{
      int fact=1,n;
      printf("Enter the number:");
      scanf("%d",&n);
      for(int i=1;i<=n;i++)
      fact=fact*i;
      printf("The factorial of the number is : %d",fact);
      getch();
      }
      
