/*
Create a class string with required data members and member functions.
Use the concept of operator overloading to compare two strings using ‘>’,
concatenate two strings using ‘+’, extract the second string from the first,
if at all it is a substring of the first string (use ‘-‘ ).
*/
#include<iostream.h>
#include<conio.h>
#include<string.h>

class str
{
      private:
              char name[50];
      public:
             void enter()
             {
                  gets(name);
             }
             void disp()
             {
                  puts(name);
             }
             str operator+(str x)
             {
                  str temp;
                  strcpy(temp.name,name);
                  strcat(temp.name,x.name);
                  return temp;
             }
             int operator>(str x)
             {
                 int n=strcmp(name,x.name);
                 return n;
             }
             void operator-(str x)
             {
                 int flag=0,i,j,k;
                 for(i=0;i<strlen(name);i++)
                 {
                         if(name[i]==x.name[0])
                         {
                                                   flag=1;
                                                   for(j=0;j<strlen(x.name);j++)
                                                   {
                                                           if(name[i+j]!=x.name[j])
                                                           {
                                                                                    flag=0;
                                                                                    break;
                                                           }
                                                   }
                                                   if(flag==1)
                                                   break;
                         }
                 }
                 if(flag==1)
                 {
                            cout<<"\nThe substring is: ";
                            for(k=i;k<(i+strlen(x.name));k++)
                            cout<<name[k];
                            cout<<endl;
                 }
                 if(flag==0)
                 cout<<"\nString 2 is not a substring of String 1\n";
                 return;
             }
};

int main()
{
      str s1,s2,s3;
      int ch,n;
      cout<<"Enter String 1: ";
      s1.enter();
      cout<<"Enter String 2: ";
      s2.enter();
      a:
      cout<<"\nChoose:\n1. Compare\n2. Concatenate\n3. Extract a substring\n4. Exit\n";
      cin>>ch;
      switch(ch)
      {
                case 1:
                     n=s1>s2;
                     if(n>0)
                     cout<<"\nString 1 is superior\n";
                     else if(n==0)
                     cout<<"\nBoth strings are equal\n";
                     else
                     cout<<"\nString 2 is superior\n";
                     getch();
                     goto a;
                case 2:
                     s3=s1+s2;
                     cout<<"\nThe concatenated string is: ";
                     s3.disp();
                     getch();
                     goto a;
                case 3:
                     s1-s2;
                     getch();
                     goto a;
                case 4:
                     break;
                default:
                        cout<<"\nEnter a valid choice\n";
                        goto a;
      }
      return 0;
}

