#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
main()
{
      int n,i,j;
      printf("Enter the number of students :");
      scanf("%d",&n);
      struct student
      {
            int rno,marks[5];
            char name[20];
            }a[100];
      for(i=0;i<n;i++)
      {
                       printf("\nEnter details of student %d:",i+1);
                       printf("\nEnter name:");
                       scanf("%s",&a[i].name);
                       printf("\nEnter roll number:");
                       scanf("%d",&a[i].rno);
                       printf("\nEnter marks in five subjects:");
                       for(j=0;j<5;j++)
                       scanf("%d",&a[i].marks[j]);
                       }
        printf("\n\n\t\t*************Marksheet**************\n\n");
        printf("Sno\t\tName\t\tRoll No\t\tMarks\t\t\n");
        for(i=0;i<n;i++)
        {
                 printf("\n%d\t\t%s\t\t%d\t\t",i+1,a[i].name,a[i].rno);
                 for(j=0;j<5;j++)
                 printf("%d, ",a[i].marks[j]);  
                 }
                 getch();
                 }      
                         
