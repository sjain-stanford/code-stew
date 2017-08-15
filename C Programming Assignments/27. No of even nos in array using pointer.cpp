#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
main()
{
      int *a;
      int n,even=0;
      void sort(int *ptr,int n);
      printf("Enter the number of elements in the array : ");
      scanf("%d",&n);
      a=(int *)malloc(n*sizeof(int));
      printf("\nEnter the %d elements : ",n);
      for(int i=0;i<n;i++)
      scanf("%d",a+i);
      for(int i=0;i<n;i++)
      {
              if(*(a+i)%2==0)
              even++;
              }
      printf("The number of even elements is : %d",even);
      getch();
      }
