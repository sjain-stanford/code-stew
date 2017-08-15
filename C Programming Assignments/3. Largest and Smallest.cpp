#include<stdio.h>
#include<conio.h>
main()
{
      int n1,n2,n3;
      printf("Enter three numbers:");
      scanf("%d %d %d",&n1,&n2,&n3);
      if(n1>n2 && n1>n3)
      {
      printf("%d is largest.\n",n1);
      if(n2>n3)
      {
      printf("%d is smallest.\n",n3);}
      else
      printf("%d is smallest.\n",n2);
      }
      if(n2>n3 && n2>n1)
      {
      printf("%d is largest.\n",n2);
      if(n1>n3)
      {
      printf("%d is smallest.\n",n3);}
      else
      printf("%d is smallest.\n",n1);
      }
      if(n3>n2 && n3>n1)
      {
      printf("%d is largest.\n",n3);
      if(n1>n2)
      {
      printf("%d is smallest.\n",n2);}
      else
      printf("%d is smallest.\n",n1);
      }
      getch();
      }
      
                        
                        
                        
