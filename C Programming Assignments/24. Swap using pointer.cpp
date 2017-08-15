#include<stdio.h>
#include<conio.h>
main()
{
      int a,b;
      int *ptr1,*ptr2,*temp;
      printf("Enter the two values : ");
      scanf("%d %d",&a,&b);
      ptr1=&a;
      ptr2=&b;
      temp=ptr1;
      ptr1=ptr2;
      ptr2=temp;
      printf("After swapping the values are : %d %d",*ptr1,*ptr2);
      getch();
      }
      
