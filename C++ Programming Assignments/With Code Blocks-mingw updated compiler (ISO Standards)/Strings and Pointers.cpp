#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;
int main()
{
    int i,m,k,j=1,p,q;
    char* name;
    char* pos[40];
    name=new char[80];
    cout<<"enter the words seperated by spaces: ";
    cin.get(name,80,'\n');
    pos[0]=name;
    int n=strlen(name);
    for(i=0;i<n;i++)
    {
        if(*(name+i)==' ')
        {
            pos[j]=(name+i+1);
            j++;
        }
    }
    int no=j;
    cout<<"\nentered words:\n";
    for(m=0;m<no;m++)
    {
        for(k=0;(*(pos[m]+k)!=' ')&&(*(pos[m]+k)!='\0');k++)
        {
            cout<<*(pos[m]+k);
        }
        cout<<"\n";
    }
    cout<<"\nsorted words:\n";
    for(p=0;p<no-1;p++)
    for(q=0;q<no-p-1;q++)
    {
        if(strcmp(pos[q],pos[q+1])>0)
        {
            char* temp;
            temp=pos[q];
            pos[q]=pos[q+1];
            pos[q+1]=temp;
        }
    }
    for(m=0;m<no;m++)
    {
        for(k=0;(*(pos[m]+k)!=' ')&&(*(pos[m]+k)!='\0');k++)
        {
            cout<<*(pos[m]+k);
        }
        cout<<"\n";
    }
    getch();
    return 0;
}
