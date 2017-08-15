#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int n;
    int f1=0,f2=1,f3;
    cout<<"enter the no of terms: ";
    cin>>n;
    cout<<f1<<' '<<f2;
    for(int i=1;i<n-1;i++)
    {
        f3=f1+f2;
        cout<<' '<<f3;
        f1=f2;
        f2=f3;
    }
    getch();
    return 0;
}
