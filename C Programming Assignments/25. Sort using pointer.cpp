#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
main()
{
      int *a;
      int n;
      void sort(int *ptr,int n);
      printf("Enter the number of elements in the array : ");
      scanf("%d",&n);
      a=(int *)malloc(n*sizeof(int));
      printf("\nEnter the %d elements : ",n);
      for(int i=0;i<n;i++)
      scanf("%d",a+i);
      sort(a,n);
      printf("\n\nThe sorted values are :\n");
      for(int i=0;i<n;i++)
      printf("\n%d",*(a+i));
      getch();
      }
      
void sort(int *a,int n)
{
     for(int i=0;i<n-1;i++)
     {
             for(int j=i+1;j<=n-1;j++)
             {
                     if(*(a+i)>*(a+j))
                     {
                                      int t;
                                      t=*(a+i);
                                      *(a+i)=*(a+j);
                                      *(a+j)=t;
                                      }
                                      }
                                      }
                                      }

      
      
