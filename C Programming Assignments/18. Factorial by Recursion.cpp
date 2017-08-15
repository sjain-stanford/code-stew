#include<stdio.h>
#include<conio.h>
long int f=1;
long int fact(int);
main()
{
      int n;
      printf("Enter the number:");
      scanf("%d",&n);
      printf("The factorial of %d is %ld.",n,fact(n));
      getch();
      }
long int fact(int n)
{
    if(n==0)
    return(1);
    f=n*f;
    --n;
     if(n==1||n==0)
     return f;
     else
     return(fact(n));
    }

      
