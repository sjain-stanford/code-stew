#include<stdio.h>
#include<conio.h>
main()
{
      int i,j,n,ch=0,wd=0,st=0;
      char a[500];
      printf("Enter the string :\n\n");
      for(i=0;(a[i]=getchar())!='\n';i++);
      a[i]='\0';      
      
      for(n=0;a[n]!='\0';n++);   // Stores the stringlength in n.
      
      for(j=0;j<n;j++)
      {
                      if(a[j]==' '||a[j]=='.')
                      wd++;
                      if(a[j]=='.'||a[j]=='?'||a[j]=='!')
                      st++;
                      if((a[j]>='A'&&a[j]<='Z')||(a[j]>='a'&&a[j]<='z'))
                      ch++;
                      }
                      printf("The number of \n\n * Characters = %d \n * Words = %d \n * Sentrences = %d",ch,wd,st);
                      getch();
                      }
                      
      
