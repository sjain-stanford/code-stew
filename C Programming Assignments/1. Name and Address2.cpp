#include<stdio.h>
#include<conio.h>
main()
{
     int i;
     char a[50],b[100];
     printf("Enter the name: ");
     for(i=0;(a[i]=getchar())!='\n';i++);
             a[i]='\0';
     printf("Enter the address: ");
     for(i=0;(b[i]=getchar())!='\n';i++);
             b[i]='\0';
     printf("Name: %s\nAddress: %s",a,b);
     getch();
     }
     
