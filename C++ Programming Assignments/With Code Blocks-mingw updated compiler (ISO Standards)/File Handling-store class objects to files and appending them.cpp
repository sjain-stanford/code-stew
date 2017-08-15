/*
Write a program that creates ‘n’ objects of class ‘directory’ which has fields
like name, phone no., and address. Write the objects onto a file “object.txt”.
Open the file and check if each object is valid or not. A valid entry means that
the name and phone no. should be a string and a numeric string respectively.
The valid objects alone are to be written onto another file “newobject.txt”.
Also provide options for appending objects to the existing file, after their validity check.
*/
#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstring>
using namespace std;
class directory
{
      private:
              char* name;
              char* phone;
              char* addrs;
      public:
             directory()
             {
                name=new char[50];
                phone=new char[20];
                addrs=new char[100];
             }
             void getdata()
             {
                  cout<<"enter name: ";
                  cin.getline(name,50,'\n');
                  cout<<"enter phone: ";
                  cin.getline(phone,20,'\n');
                  cout<<"enter address: ";
                  cin.getline(addrs,100,'\n');
             }
             void putdata()
             {
                  cout<<"\nname: "<<name<<'\n';
                  cout<<"phone: "<<phone<<'\n';
                  cout<<"address: "<<addrs<<'\n';
             }
             int validity()
             {
                 int flagn=0,flagp=0;
                 for(int i=0;i<strlen(name);i++)
                 {
                         if(((*(name+i)<='z')&&(*(name+i)>='a'))||((*(name+i)<='Z')&&(*(name+i)>='A'))||(*(name+i)==' '))
                         flagn=0;
                         else
                         {
                             flagn=1;
                             break;
                         }
                 }
                 for(int i=0;i<strlen(phone);i++)
                 {
                    if((*(phone+i)<='9')&&(*(phone+i)>='0'))
                    flagp=0;
                    else
                    {
                        flagp=1;
                        break;
                    }
                 }
                 if(flagp==0&&flagn==0)
                 return 1;
                 else
                 return 0;
             }
};

int main()
{
    int n,i;
    directory* obj;
    ifstream infile;
    ofstream outfile;
    cout<<"enter the number of entries (n): ";
    cin>>n;
    cin.ignore(50,'\n');
    outfile.open("object.txt");
    for(i=0;i<n;i++)
    {
        obj=new directory;
        cout<<"\nentry "<<i+1<<":\n";
        obj->getdata();
        outfile.write((char*)obj,sizeof(directory));
        delete obj;
    }
    outfile.close();
    int vald,no=0;
    infile.open("object.txt");
    outfile.open("newobject.txt");
    for(i=0;i<n;i++)
    {
        obj=new directory;
        infile.read((char*)obj,sizeof(directory));
        vald=obj->validity();
        if(vald==1)
        {
            outfile.write((char*)obj,sizeof(directory));
            no++;
        }
        delete obj;
    }
    infile.close();
    outfile.close();
    cout<<"\n**** valid entries are: ****\n";
    infile.open("newobject.txt");
    for(i=0;i<no;i++)
    {
            obj=new directory;
            infile.read((char*)obj,sizeof(directory));
            obj->putdata();
            delete obj;
    }
    infile.close();
    char ch;
    outfile.open("newobject.txt",ios::app);
    cout<<"\ndo you wish to append (y/n): ";
    cin>>ch;
    cin.ignore(50,'\n');
    while(ch=='y')
    {
            obj=new directory;
            obj->getdata();
            vald=obj->validity();
            if(vald==1)
            {
                outfile.write((char*)obj,sizeof(directory));
                no++;
            }
            delete obj;
            cout<<"\ndo you wish to append (y/n): ";
            cin>>ch;
            cin.ignore(50,'\n');
    }
    outfile.close();
    cout<<"\n**** final entries are: ****\n";
    infile.open("newobject.txt");
    for(i=0;i<no;i++)
    {
            obj=new directory;
            infile.read((char*)obj,sizeof(directory));
            obj->putdata();
            delete obj;
    }
    getch();
    return 0;
}


