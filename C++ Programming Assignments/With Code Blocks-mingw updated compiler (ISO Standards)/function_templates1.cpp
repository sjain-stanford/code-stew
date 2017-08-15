#include<iostream>
#include<conio.h>
using namespace std;
template <class T1, class T2>
void display(T1 x,T2 y)
{
    cout<<x<<' '<<y<<endl;
}

int main()
{
    display(1.234,'a');
    display("SWEETU",200);
    getch();
    return 0;
}
