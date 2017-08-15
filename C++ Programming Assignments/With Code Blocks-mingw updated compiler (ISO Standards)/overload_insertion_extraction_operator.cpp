#include<iostream>
#include<conio.h>
using namespace std;

class dist
{
    private:
        float feet,inches;
    public:
        friend istream& operator>>(istream& in,dist& temp);
        friend ostream& operator<<(ostream& out,dist& temp);
};

istream& operator>>(istream& in,dist& temp)
{
    cout<<"\nenter feet: ";
    in>>temp.feet;
    cout<<"\nenter inches: ";
    in>>temp.inches;
    return in;
}

ostream& operator<<(ostream& out,dist& temp)
{
    cout<<"\nfeet = ";
    out<<temp.feet;
    cout<<"\ninches = ";
    out<<temp.inches;
    return out;
}

int main()
{
    dist d1,d2;
    cin>>d1>>d2;
    cout<<d1<<d2;
    getch();
    return 0;
}
