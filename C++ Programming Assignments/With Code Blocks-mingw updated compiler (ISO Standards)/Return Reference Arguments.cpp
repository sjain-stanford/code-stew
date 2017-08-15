#include<iostream>
#include<conio.h>
using namespace std;
int& findlarge(int& a)  //return type is a reference variable of type int
{
    int& max=a;
    for(int i=0;i<10;i++)
    {
        if(*(&a+i)>max)
        {
            max=*(&a+i);
        }
    }
    return max;         //max is a reference variable
}
int main()
{
    int ar[10];
    cout<<"enter ten integers:\n";
    for(int i=0;i<10;i++)
    cin>>ar[i];
    int l=findlarge(*ar);
    cout<<"\nlargest element: "<<l;
    getch();
    return 0;
}
