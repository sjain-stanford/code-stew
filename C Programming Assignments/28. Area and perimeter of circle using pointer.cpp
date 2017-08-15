#include<stdio.h>
#include<conio.h>
main()
{
      int r;
      float area(int *r);
      float perimeter(int *r);
      printf("Enter the radius of the circle :");
      scanf("%d",&r);
      printf("\n\nThe area is %f",area(&r));
      printf("\n\nThe perimeter is %f",perimeter(&r));
      getch();
      }
      
float area(int *r)
{
    float a;
    a=3.14*(*r)*(*r);
    return(a);
}

float perimeter(int *r)
{
      float p;
      p=2*3.14*(*r);
      return(p);
}

    
      
      
