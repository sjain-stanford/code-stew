#include<iostream>
#include<conio.h>
using namespace std;
class sample
{
    int c;
    public:sample():c(0)
    {
    }
    sample(int a):c(a)
    {
    }
    sample operator++()     //Pre-increment (++s1)
    {
        return sample(++c);
    }
    sample operator++(int)  //Post-increment (s3++)
    {
        return sample(c++);
    }
    void show()
    {
        cout<<c<<endl;
    }
};
int main()
{
    sample s1,s2,s3;
    ++s1;
    s1.show();
    s2=++s1;
    s1.show();
    s2.show();
    s3++;
    s2=s3++;
    s2.show();
    s3.show();
    getch();
    return 0;
}
