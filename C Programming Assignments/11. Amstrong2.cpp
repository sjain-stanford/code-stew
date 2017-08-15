#include<stdio.h>
#include<conio.h>
main()
{
      int cube(int);
      int x,sum=0,n,y;
      printf("Enter a number: ");
      scanf("%d",&x);
      y=x;
      for(;y!=0;)
      {
              n=y%10;
              sum=sum+cube(n);
              y=y/10;
              }
              if(sum==x)
              printf("Yes, %d is an Amstrong no.",x);
              else
              printf("No, %d is not an Amstrong no.",x);
              getch();
              }
      
      int cube(int n)
      {
          int s=1;
          for(int i=1;i<=3;i++)
          {
                  s=s*n;
          }
          return s;
          }
          
