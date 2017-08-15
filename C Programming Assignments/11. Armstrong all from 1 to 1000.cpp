#include<stdio.h>
#include<conio.h>
int power(int n,int count);
main()
{
      int y,z,count,n,sum;
      printf("The Armstrong numbers are :\n");
      for(z=1;z<=1000;z++)
      {
              sum=0;
              count=0;
              y=z;
              for(;y!=0;)
              {
                         y=y/10;
                         count++;
                         }
              y=z;
              for(;y!=0;)
              {
                         n=y%10;
                         sum=sum+power(n,count);
                         y=y/10;
                         }
              if(sum==z)
              printf("%d\n",z);
              }
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
              
