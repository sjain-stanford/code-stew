#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
      float a,b,c,x,y,d,D;
      printf("Enter the a,b,c:");
      scanf("%f %f %f",&a,&b,&c);
      d=b*b-4*a*c;
      if(d>0 ||d==0)
      {
             D=pow(d,.5);
             }
             else
             {
                 printf("Roots are imaginary.");
                 goto a;
                 }
       x=(-b+D)/(2*a);
       y=(-b-D)/(2*a);  
       printf("The roots are %f, %f ",x,y);
       
       a:
                   getch();
       }       
      
      
