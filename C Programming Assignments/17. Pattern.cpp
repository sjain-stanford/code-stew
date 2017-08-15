#include<stdio.h>
#include<conio.h>
main()
{
      for(int i=1;i<=3;i++)
      {
              for(int j=3-i;j>=1;j--)
              printf(" ");
              for(int k=1;k<=2*i-1;k++)
              printf("*");
              printf("\n");
              }
      for(int i=2;i>=1;i--)
      {
              for(int j=3-i;j>=1;j--)
              printf(" ");
              for(int k=1;k<=2*i-1;k++)
              printf("*");
              printf("\n");
              }
getch();
}
