#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
main()
{
      int *a;
      int n,min;
      printf("Enter the number of elements in the array : ");
      scanf("%d",&n);
      a=(int *)malloc(n*sizeof(int));
      printf("\nEnter the %d elements : ",n);
      for(int i=0;i<n;i++)
      scanf("%d",a+i);
      min=*a;
      for(int i=1;i<n;i++)
      {
              if(*(a+i)<min)
              min=*(a+i);
              }
      printf("\n\nThe minimum of the entered values is : %d",min);
      getch();
      }
      
              
              
