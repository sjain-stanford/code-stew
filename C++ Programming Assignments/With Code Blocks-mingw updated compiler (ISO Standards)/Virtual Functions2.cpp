#include<iostream>
#include<conio.h>
using namespace std;
class publication
{
    protected:
        char* title;
        float price;
    public:
        publication()
        {
            title=new char[80];
        }
        void getdata()
        {
            cin.ignore(80,'\n');
            cout<<"enter title: ";
            cin.get(title,79,'\n');
            cout<<"enter price: Rs. ";
            cin>>price;
        }
        void putdata()
        {
            cout<<"\nname: "<<title;
            cout<<"\nprice: Rs."<<price;
        }
        virtual void getinfo()=0;
        virtual void putinfo()=0;
        ~publication()
        {
            delete title;
        }
};
class book:public publication
{
    private:
        int pages;
    public:
        void getinfo()
        {
            cout<<"enter no. of pages: ";
            cin>>pages;
        }
        void putinfo()
        {
            cout<<"\npages: "<<pages<<endl;
        }
};
class tape:public publication
{
    private:
        int mins;
    public:
        void getinfo()
        {
            cout<<"enter duration (minutes): ";
            cin>>mins;
        }
        void putinfo()
        {
            cout<<"\nduration: "<<mins<<" minutes"<<endl;
        }
};
int main()
{
    publication* pub[20];
    int n=0;
    char ch;
    do
    {
        cout<<"\nenter book or tape (b/t): ";
        cin>>ch;
        if(ch=='b')
        {
            pub[n]=new book;
            pub[n]->getdata();
            pub[n]->getinfo();
            n++;
        }
        else
        {
            pub[n]=new tape;
            pub[n]->getdata();
            pub[n]->getinfo();
            n++;
        }
        cout<<"continue (y/n): ";
        cin>>ch;
    } while(ch=='y');
    for(int i=0;i<n;i++)
    {
        cout<<"\nitem "<<i+1<<":";
        pub[i]->putdata();
        pub[i]->putinfo();
    }
    delete[] pub;
    getch();
    return 0;
}
