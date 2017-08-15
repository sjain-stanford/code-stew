#include<stdio.h>
#include<conio.h>
main()
{
      int n,i,j,a[50];
      printf("Enter the number:");
      scanf("%d",&n);
      for(i=0;n!=0;i++)
      {
                      if(n==1)
                      {
                              a[i]=1;
                              break;
                              }
                      a[i]=n%2;
                      n=n/2;
                      }
      for(j=i;j>=0;j--)
      printf("%d",a[j]);
      getch();
      }
      
      
