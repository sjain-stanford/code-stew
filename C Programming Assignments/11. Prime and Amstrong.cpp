#include<stdio.h>
#include<conio.h>
main()
{
      int n,choice;
      printf("Enter a number:");
      scanf("%d",&n);
      printf("Enter your choice: \n1.Prime number \n2.Amstrong number\n");
      scanf("%d",&choice);
      switch(choice)
      {
                    case 1:
                         {
                            if(n==1)
                            {printf("%d is not a Prime number.",n);
                            break;}
                            int count=0;
                            for(int i=2;i<n;i++)
                            {
                                    if(n%i==0)
                                    count++;
                                    }
                                    if(count==0)
                                    printf("%d is a Prime number.",n);
                                    else
                                    printf("%d is not a Prime number.",n);
                                    }break;
                    case 2:
                         {
                                 int sum=0;
                                 for(int i=n;i>0;i=i/10)
                                 {
                                 sum=sum+(i%10)*(i%10)*(i%10);
                                 }
                                 if(sum==n)
                                 printf("%d is an Amstrong No.",n);
                                 else
                                 printf("%d is not an Amstrong No.",n);
                                 }break;
                    default:
                                 printf("Enter a valid choice.");
                                 break;
      }
            getch();
            }                                
