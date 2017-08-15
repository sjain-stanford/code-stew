#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter the no of lines: ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=n-i;j>0;j--)
        cout<<' ';
        for(int k=1;k<=i;k++)
        cout<<'*'<<' ';
        cout<<'\n';
    }
    getch();
    return 0;
}
