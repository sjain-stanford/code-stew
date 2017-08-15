#include<iostream>
#include<conio.h>
using namespace std;
int fibo(int k)
{
    if(k==0||k==1)
    return 1;
    else
    return (fibo(k-1)+fibo(k-2));
}

int main()
{
    int n,c;
    cout<<"enter the no of terms: ";
    cin>>n;
    cout<<"0 1";
    for(int i=1;i<n-1;i++)
    {
        c=fibo(i);
        cout<<' '<<c;
    }
    getch();
    return 0;
}
