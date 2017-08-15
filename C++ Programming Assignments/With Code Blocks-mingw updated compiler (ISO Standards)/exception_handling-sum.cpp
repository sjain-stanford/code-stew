//This is a program that finds the sum of two numbers using throw,catch and try blocks(exception handling)
//However it is not ethical to use exception handling for such purposes
#include<iostream>
#include<conio.h>
using namespace std;

void sum(int a,int b)
{
   throw a+b;
}
int main()
{
    int x,y;
    cout<<"enter two numbers: ";
    cin>>x>>y;
    try
    {
        sum(x,y);
    }
    catch(int sum)
    {
        cout<<"sum = "<<sum;
    }
    getch();
    return 0;
}
