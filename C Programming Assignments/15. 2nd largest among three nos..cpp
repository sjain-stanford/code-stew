#include<stdio.h>
#include<conio.h>
main()
{
      int a,b,c;
      printf("Enter three numbers:");
      scanf("%d %d %d",&a,&b,&c);
      if((a>b && a<c)||(a<b && a>c))
      printf("%d is the 2nd largest.",a);
      if((b>a && b<c)||(b<a && b>c))
      printf("%d is the 2nd largest.",b);
      if((c>a && c<b)||(c<a && c>b))
      printf("%d is the 2nd largest.",c);
      getch();
      }
