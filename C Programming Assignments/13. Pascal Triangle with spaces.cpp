#include<stdio.h>
#include<conio.h>
int comb(int,int);
int fact(int);
main()
{
      int n;
      printf("Enter the number of rows:");
      scanf("%d",&n);
      for(int i=0;i<n;i++)
      {
              for(int j=0;j<n-i-1;j++)
              {
                      printf("   ");
                      }
              for(int k=0;k<=i;k++)
              {
                      printf("%d    ",comb(i,k));
                      }
                      printf("\n");
                      }getch();
                      }
                      
      
      
      
int comb(int a,int b)
{
    int x,y,z;
    x=fact(a);
    y=fact(a-b);
    z=fact(b);
    return x/(y*z);
}
int fact(int a)
{
    int f=1;
    for(int i=1;i<=a;i++)
    {
            f=f*i;
            }
            return f;
            }
            
      
      
      
      
      
