#include<stdio.h>
#include<conio.h>
main()
{
      int k=0,s=1,n;
      printf("Enter upto n terms:");
      scanf("%d",&n);
      printf("%d\n",s);
      for(int i=1;i<=n-1;i++)
      {
              s=s+k;
              k=s-k;
              printf("%d\n",s);
              }
      getch();
      }
       
