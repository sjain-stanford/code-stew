#include<iostream>
#include<conio.h>
using namespace std;
class publication
{
    private:
        char* title;
        float price;
    public:
        publication()
        {
            title=new char[80];
        }
        void getdata()
        {
            cout<<"enter title: ";
            cin.get(title,79,'\n');
            cin.ignore(80,'\n');
            cout<<"enter price: Rs. ";
            cin>>price;
        }
        void putdata()
        {
            cout<<"\nname: "<<title;
            cout<<"\nprice: Rs."<<price;
        }
        ~publication()
        {
            delete title;
        }
};
class book:public publication
{
    private:
        int count;
    public:
        void getdata()
        {
            publication::getdata();
            cout<<"enter no. of pages: ";
            cin>>count;
            cin.ignore(80,'\n');
        }
        void putdata()
        {
            publication::putdata();
            cout<<"\npages: "<<count<<endl;
        }
};
class tape:public publication
{
    private:
        float mins;
    public:
        void getdata()
        {
            publication::getdata();
            cout<<"enter duration (minutes): ";
            cin>>mins;
            cin.ignore(80,'\n');
        }
        void putdata()
        {
            publication::putdata();
            cout<<"\nduration: "<<mins<<" minutes"<<endl;
        }
};
int main()
{
    int i=0,j=0;
    char ch='y';
    book* b[20];
    tape* t[20];
    while(ch=='y')
    {
        cout<<"enter the book info:\n";
        b[i]=new book;
        b[i]->getdata();
        cout<<"enter the tape info:\n";
        t[i]=new tape;
        t[i]->getdata();
        i++;
        cout<<"continue (y/n): ";
        cin>>ch;
        cin.ignore(80,'\n');
    }
    for(j=0;j<i;j++)
    {
        cout<<"\n** book "<<j+1<<" **";
        b[j]->putdata();
        cout<<"\n** tape "<<j+1<<" **";
        t[j]->putdata();
    }
    for(j=0;j<i;j++)
    {
        delete b[j];
        delete t[j];
    }
    getch();
    return 0;
}
