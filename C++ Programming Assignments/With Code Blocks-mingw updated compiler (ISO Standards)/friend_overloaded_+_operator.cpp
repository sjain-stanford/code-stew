//float + distance
//e.g. 10.5 + d
//using friend overloaded + operator
#include<iostream>
#include<conio.h>
using namespace std;
class dist          //Distance
{
    private:
        int feet;
        float inches;
    public:
        dist():feet(0),inches(0){}      //0-arg constructor
        dist(float fltfeet)             //1-arg constructor
        {
            feet=int(fltfeet);
            inches=12*(fltfeet-feet);
        }
        dist(int ft,float in):feet(ft),inches(in){}     //2-arg constructor
        void showdist()
        {
            cout<<feet<<" feet & "<<inches<<" inches";
        }
        friend dist operator+(dist da,dist db);
};

dist operator+(dist da,dist db)
{
    int f=da.feet+db.feet;
    float i=da.inches+db.inches;
    if(i>=12)
    {
        f++;
        i-=12;
    }
    return dist(f,i);       //returning temporary nameless object
}
int main()
{
    dist d1=2.5;        //constructor converts float-feet to distance
    dist d2(1.25);      //same as above

    cout<<"\nd1 = ";
    d1.showdist();
    cout<<"\nd2 = ";
    d2.showdist();

    dist d3;
    d3=10.23+d1;           //friend overloaded + operator
    cout<<"\nd3 = ";
    d3.showdist();

    dist d4;
    d4=d2+12.56;           //friend overloaded + operator
    cout<<"\nd4 = ";
    d4.showdist();

    getch();
    return 0;
}
