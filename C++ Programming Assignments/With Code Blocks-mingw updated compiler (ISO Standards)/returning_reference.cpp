#include<iostream>
#include<conio.h>
using namespace std;
int& larger(int&,int&);
int main()
{
    int a,b;
    cout<<"\nenter a: ";
    cin>>a;
    cout<<"\nenter b: ";
    cin>>b;
    larger(a,b)=0;
    cout<<"\nlarger munber is truncated to zero!\n";
    cout<<endl<<a<<' '<<b;
    getch();
    return 0;
}

int& larger(int& x,int& y)
{
    return (x>y)?x:y;
}
