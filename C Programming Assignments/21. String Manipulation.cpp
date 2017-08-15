#include<stdio.h>
#include<conio.h>
main()
{
      
      int choice,n,l,i,j,count=0,t=0;
      char a[50],b[50],c[50],d[50];
      reenter:
      printf("Enter the string: \n");
      gets(a);
      
      for(n=0;a[n]!='\0';n++);   //this will count the string length in n
      
      start:
            printf("\n\n\nEnter your choice: \n1.String Length \n2.Reverse the string \n3.Palindrome or not \n4.Concatenate the string \n5.Extract a substring \n6.Lower case to upper and vice versa \n\n");
            scanf("%d",&choice);
      
      switch(choice)
      {
                    case 1:
                         {
                                   for(n=0;a[n]!='\0';n++);
                                   printf("The string length is: %d",n);
                                   goto start;
                                   }
                    case 2:
                         {
                                   for(i=0;i<n;i++)
                                   c[i]=a[n-1-i];
                                   printf("The reverse of this string is: \n");
                                   for(j=0;j<n;j++)
                                   printf("%c",c[j]);
                                   goto start;
                                   }
                    case 3:
                         {
                                   for(i=0;i<n;i++)
                                   {
                                    if(a[i]==a[n-1-i])
                                    count++;
                                    }
                                   if(count==n)
                                   printf("The given string is a palindrome.");
                                   else
                                   printf("The given string is not a palindrome.");
                                   goto start;
                                   }
                    case 4:
                         {
                                  printf("\nEnter the string B: ");
                                  scanf("%s",b);
                                  
                                  for(n=0;a[n]!='\0';n++);   //this will count the string length of A in m
                                  for(l=0;b[l]!='\0';l++);   //this will count the string length of B in n
                                  
                                  for(i=0;i<n;i++)
                                  d[i]=a[i];
                                  for(i=n;i<n+l;i++)
                                  {
                                   d[i]=b[t];
                                   t++;
                                   }
                                  t=0;
                                  printf("\nThe concatenated string is:\n");
                                  for(j=0;j<n+l;j++)
                                  printf("%c",d[j]);
                                  goto start;
                                  }
                    case 5:
                         {
                                  int y,z;
                                  printf("\nEnter the start and stop position: ");
                                  scanf("%d %d",&y,&z);
                                  for(i=y-1;i<=z-1;i++)
                                  printf("%c",a[i]);
                                  goto start;
                                  }
                    case 6:
                         {
                                  for(i=0;i<n;i++)
                                  {
                                   if(a[i]>='A' && a[i]<='Z')
                                   a[i]=a[i]+32;
                                   else if(a[i]>='a' && a[i]<='z')
                                   a[i]=a[i]-32;
                                   }
                                  printf("The case is changed:\n");
                                  for(i=0;i<n;i++)
                                  printf("%c",a[i]);
                                  goto start;
                                  }
                    
                    default:
                            {
                                  printf("Enter a valid choice.");
                                  }     
      }
getch();
}
                            
                                  
                                  
                                   
                                   
                         
