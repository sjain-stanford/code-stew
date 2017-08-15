#include<conio.h>
#include<stdio.h>
main()
{
      int i,sum=0,n,choice;
      printf("Enter n:");
      scanf("%d",&n);
      printf("Enter your choice : \n1.For Loop \n2.Do..While Loop \n3.While Loop\n");
      scanf("%d",&choice);
      switch(choice)
      {
      case 1:
           for(i=1;i<=n;i++)
           {
                       sum=sum+i;
           }
           printf("Sum by for loop= %d\n",sum);
           break;
      
      case 2:
           i=1;
           sum=0;
           do
           {
                 sum=sum+i;
                 i++;
           }while(i<=n);
           printf("Sum by do while loop= %d\n",sum); 
           break;
       case 3:
           i=1;
           sum=0;
           while(i<=n)
           {
                  sum=sum+i;
                  i++;                 
           }
           printf("Sum by while loop= %d\n",sum);
           break;
       }     
getch();
}
