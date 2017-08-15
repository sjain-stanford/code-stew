/*
Give a code that designs a single manipulator to provide the following output specification.
1.	10 columns width
2.	Right justified
3.	Two digits precision
4.	Unused spaces filled with ‘*’
5.	Trailing zeros shown
Also give the statement by which you invoke this manipulator
*/
#include<iostream>
#include<conio.h>
using namespace std;
ostream& usermanip(ostream& output)
{
     output.width(10);
     output.precision(2);
     output.fill('*');
     output.setf(ios::showpoint);
     output.setf(ios::right,ios::adjustfield);
     output.setf(ios::fixed,ios::floatfield);
     return output;
}
int main()
{
    float num;
    z:
    cout<<"\nenter the floating point number: ";
    cin>>num;
    cout<<usermanip<<num;
    goto z;
    getch();
    return 0;
}
