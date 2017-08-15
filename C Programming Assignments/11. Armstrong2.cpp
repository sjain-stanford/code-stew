#include<stdio.h>
#include<conio.h>
main()
{
      int power(int n,int count);
      int x,sum=0,n,y,count=0;
      printf("Enter a number: ");
      scanf("%d",&x);
      y=x;
      for(;y!=0;)
      {
              y=y/10;
              count++;
              }
      y=x;
      for(;y!=0;)
      {
              n=y%10;
              sum=sum+power(n,count);
              y=y/10;
              }
              if(sum==x)
              printf("Yes, %d is an Amstrong no.",x);
              else
              printf("No, %d is not an Amstrong no.",x);
              getch();
              }
      
      int power(int n,int count)
      {
          int s=1;
          for(int i=1;i<=count;i++)
          {
                  s=s*n;
          }
          return s;
          }
          
