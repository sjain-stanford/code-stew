#include<iostream.h>
#include<conio.h>

class sam
{
      private:
              static int i;
      public:
             static void init(int x)
             {
                    i=x;
             }
             void show()
             {
                  cout<<"The value is: "<<i<<endl;
             }
};
int sam::i;
int main()
{
    int x;
    cout<<"Enter the value to be in initialized to the static variable: ";
    cin>>x;
    sam::init(x);
    sam a,b;
    cout<<"Calling through object a:"<<endl;
    a.show();
    cout<<"Calling through object b:"<<endl;
    b.show();
    getch();
    return 0;
}             
