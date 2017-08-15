#include<iostream>
#include<conio.h>
using namespace std;
template <class T>
T min(T& a,T& b)
{
    return ((a<b)?a:b);
}

int main()
{
    int i=10,j=20;
    cout<<"min = "<<min(i,j)<<endl;

    char c='A',d='Z';
    cout<<"min = "<<min(c,d)<<endl;

    float e=10.24,f=10.20;
    cout<<"min = "<<min(e,f)<<endl;

    double g=1.1,h=1.11;
    cout<<"min = "<<min(g,h)<<endl;

    getch();
    return 0;
}
