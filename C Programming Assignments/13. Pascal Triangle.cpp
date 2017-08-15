#include<stdio.h>
#include<conio.h>
main()
{
      int n;
      int fact(int m);
      int comb(int a,int b);
      printf("Enter the number of rows:");
      scanf("%d",&n);
      for(int i=0;i<=n-1;i++)
      {
              for(int j=n-1-i;j>0;j--)
              printf(" ");
              for(int k=0;k<=i;k++)
              printf("%d ",comb(i,k));
              printf("\n");
              }
              getch();
              }
              
              
      
      
      
      
int fact(int m)
{
    int f=1;
    for(int i=1;i<=m;i++)
    f=f*i;
    return(f);
}
int comb(int a,int b)
{
    int x,y,z;
    x=fact(a);
    y=fact(a-b);
    z=fact(b);
    return(x/(y*z));
}
