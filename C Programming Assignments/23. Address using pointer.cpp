#include<stdio.h>
#include<conio.h>
main()
{
      int a;
      int *ptr;
      printf("Enter the value of a:");
      scanf("%d",&a);
      ptr=&a;
      printf("The address of %d is %d",*ptr,ptr);
      getch();
      }
      
