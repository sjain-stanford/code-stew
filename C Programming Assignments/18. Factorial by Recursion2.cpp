#include<stdio.h>
#include<conio.h>
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
    if(n>1)
    return(n*fact(n-1));
    else
    return(1);
    }
