#include<stdio.h>
#include<conio.h>
main()
{
      int n,count;
      printf("The prime nos are :\n");
      for(n=2;n<=100;n++)
      {
      count=0;
              for(int i=2;i<=n-1;i++)
              {
              if(n%i==0)
              count++;
              }
      if(count==0)
      printf("%d\n",n);
      }
      getch();
      }
      
