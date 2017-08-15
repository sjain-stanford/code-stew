#include<stdio.h>
#include<conio.h>
main()
{
     int i;
     char a[50],b[100];
     printf("Enter the name: ");
     for(i=0;;i++)
     {
             scanf("%c",&a[i]);
             if(a[i]=='\n')
             break;
             }
             a[i]='\0';
     printf("Enter the address: ");
     for(i=0;;i++)
     {
             scanf("%c",&b[i]);
             if(b[i]=='\n')
             break;
             }
             b[i]='\0';
     printf("Name: %s\nAddress: %s",a,b);
     getch();
     }
     
