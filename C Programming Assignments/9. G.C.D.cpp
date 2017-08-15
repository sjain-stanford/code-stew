#include<conio.h>
#include<stdio.h>
main()
{
      int gcd,a,b,min;
      printf("Enter two nos: ");
      scanf("%d %d",&a,&b);
      if(a<b)
      min=a;
      else
      min=b;
      for(int i=1;i<=min;i++)
      {
              if(a%i==0 && b%i==0)
              gcd=i;
              }
              printf("The G.C.D is : %d",gcd);
              getch();
              }
      
