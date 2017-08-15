#include<stdio.h>
#include<conio.h>
main()
{
      int i,j,k,n;
      struct player
      {
             int age,no,avg;
             char name[20];
             }a[20],tmp;
      printf("Enter the number of players:");
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
                       printf("\nEnter details of Cricketer %d",i+1);
                       printf("\nEnter name:");
                       scanf("%s",&a[i].name);
                       printf("\nEnter Age:");
                       scanf("%d",&a[i].age);
                       printf("\nEnter the number of test matches:");
                       scanf("%d",&a[i].no);
                       printf("\nEnter the average:");
                       scanf("%d",&a[i].avg);
                       }
      for(j=0;j<n-1;j++)
      {
      for(k=j+1;k<=n-1;k++)
      {
                         if(a[j].avg>a[k].avg)
                         {
                                              tmp=a[j];
                                              a[j]=a[k];
                                              a[k]=tmp;
                                              }
                                              }
                                              }
      printf("\nThe Arranged Records are -->\n");
      printf("\n\nSno\t\tName\t\tAge\t\tTests\t\tAverage");
      for(i=0;i<n;i++)
      {
                       printf("\n%d\t\t%s\t\t%d\t\t%d\t\t%d",i+1,a[i].name,a[i].age,a[i].no,a[i].avg);   
                       }
                       getch();
                       } 
                                              
                       
