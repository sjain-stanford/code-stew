#include<stdio.h>
#include<conio.h>
main()
{
      for(int i=0;i<=2;i++)
      {
              for(int j=2-i;j>=1;j--)
              printf(" ");
              for(int k=1;k<=2*i+1;k++)
              printf("*");
              printf("\n");
              }
      for(int i=0;i<=1;i++)
      {
              for(int j=1;j<=i+1;j++)
              printf(" ");
              for(int k=1;k<=3-2*i;k++)
              printf("*");
              printf("\n");
              }
getch();
}
                      
