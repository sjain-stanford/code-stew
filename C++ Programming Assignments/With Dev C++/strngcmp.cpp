#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>

int n;
void order(char x[][50])
{
     for(int i=0;i<n-1;i++)
     for(int j=0;j<(n-i-1);j++)
     {
             if(strcmp(x[j],x[j+1])>0)
             {
                                      char temp[50];
                                      strcpy(temp,x[j]);
                                      strcpy(x[j],x[j+1]);
                                      strcpy(x[j+1],temp);
             }
     }
     return;
}
 
int main()
{
    char junk[10];
    cout<<"Enter the number of names to be sorted: ";
    cin>>n;
    gets(junk);
    char a[n][50];
    for(int i=0;i<n;i++)
    {
            cout<<"String "<<i+1<<": ";
            gets(a[i]);
    }
    order(a);
    for(int i=0;i<n;i++)
    {
            cout<<endl<<a[i];
    }
    getch();
    return 0;
}
