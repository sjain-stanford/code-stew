//The sum of proper divisors of a=b and sum of proper divisors of b=a
#include<stdio.h>
#include<conio.h>
main()
{
      int a,b,s1=0,s2=0;
      for(a=2;a<=500;a++)
      {
      for(b=2;b<=500;b++)
      {
            for(int n=1;n<a;n++)
            {
                    if(a%n==0)
                    {
                    s1=s1+n;
                    }
                    }
             for(int m=1;m<b;m++)
             {
                     if(b%m==0)
                     s2=s2+m;
                     }
                     if((a==s2)&&(b==s1))
                     printf("%d and %d are amicable numbers.\n",a,b);
                     s1=0;
                     s2=0;
      }
      }
                     getch();
      }
                     
                                   
