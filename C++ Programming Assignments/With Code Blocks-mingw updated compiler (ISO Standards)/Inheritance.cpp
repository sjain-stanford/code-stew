#include<iostream>
using namespace std;

class inst                              //Institute
{
      private:
              char name[30];
              char dept[30];
      public:
             void getdata()
             {
                  cout<<"\nEnter name of institute: ";
                  cin.get(name,29,'\n');
                  cin.ignore(30,'\n');
                  cout<<"\nEnter the department: ";
                  cin.get(dept,29);
                  cin.ignore(30,'\n');
             }
             void putdata()
             {
                  cout<<"\nInstitute: "<<name;
                  cout<<"\nDepartment: "<<dept;
             }
};

class stud : public inst                //Student
{
      private:
              int sem;
              int roll;
      public:
             void getdata()
             {
                  inst::getdata();
                  cout<<"\nEnter semester: ";
                  cin>>sem;
                  cout<<"\nEnter roll number: ";
                  cin>>roll;
             }
             void putdata()
             {
                  inst::putdata();
                  cout<<"\nSemester: "<<sem;
                  cout<<"\nRoll: "<<roll;
             }
};

class fac : public inst                 //Faculty
{
      private:
              char desig[10];
              int sal;
      public:
             void getdata()
             {
                  inst::getdata();
                  cout<<"\nEnter designation: ";
                  cin>>desig;
                  cout<<"\nEnter salary (in Rs.): ";
                  cin>>sal;
             }
             void putdata()
             {
                  inst::putdata();
                  cout<<"\nDesignation: "<<desig;
                  cout<<"\nSalary: Rs. "<<sal;
             }
};

class ts : public fac                   //Teaching Staff
{
      private:
              char qual[10];
      public:
             void getdata()
             {
                  fac::getdata();
                  cout<<"\nEnter qualification: ";
                  cin>>qual;
             }
             void putdata()
             {
                  fac::putdata();
                  cout<<"\nQualification: "<<qual;
             }
};

class nts : public fac                  //Non-teaching Staff
{
      public:
             void getdata()
             {
                  fac::getdata();
             }
             void putdata()
             {
                  fac::putdata();
             }
};

class tech : public nts                 //Technical Non-teaching Staff
{
      private:
              int yrs;
      public:
             void getdata()
             {
                  nts::getdata();
                  cout<<"\nEnter number of years of experience: ";
                  cin>>yrs;
             }
             void putdata()
             {
                  nts::putdata();
                  cout<<"\nYears of experience: "<<yrs;
             }
};

class ntech : public nts                //Non-technical Non-teaching Staff
{
      private:
              int ch;           //Regular or Temporary
      public:
             void getdata()
             {
                  nts::getdata();
                  cout<<"\nChoose \n1. Regular\n2. Temporary\n";
                  cin>>ch;
             }
             void putdata()
             {
                  nts::putdata();
                  if(ch==1)
                  cout<<"\nType: Regular";
                  else if(ch==2)
                  cout<<"\nType: Temporary";
             }
};


int main()
{
    stud s[10];
    ts ts[10];
    tech tnts[10];
    ntech ntnts[10];

    int i,n1,n2,n3,n4;

    cout<<"Enter the number of students: ";
    cin>>n1;
    cout<<"Enter the number of teaching staff: ";
    cin>>n2;
    cout<<"Enter the number of technical non-teaching staff: ";
    cin>>n3;
    cout<<"Enter the number of non-technical non-teaching staff: ";
    cin>>n4;

    for(i=0;i<n1;i++)
    {
        cin.ignore(30,'\n');
        cout<<"\nEnter details for student "<<i+1<<":\n";
        s[i].getdata();
    }

    for(i=0;i<n2;i++)
    {
        cin.ignore(30,'\n');
        cout<<"\nEnter details for teaching staff "<<i+1<<":\n";
        ts[i].getdata();
    }

    for(i=0;i<n3;i++)
    {
        cin.ignore(30,'\n');
        cout<<"\nEnter details for technical non-teaching staff "<<i+1<<":\n";
        tnts[i].getdata();
    }

    for(i=0;i<n4;i++)
    {
        cin.ignore(30,'\n');
        cout<<"\nEnter details for non-technical non-teaching staff "<<i+1<<":\n";
        ntnts[i].getdata();
    }

    for(i=0;i<n1;i++)
    {
        cout<<"\n\nDetails of student "<<i+1<<":\n";
        s[i].putdata();
    }

    for(i=0;i<n2;i++)
    {
        cout<<"\n\nDetails of teaching staff "<<i+1<<":\n";
        ts[i].putdata();
    }

    for(i=0;i<n3;i++)
    {
        cout<<"\n\nDetails of technical non-teaching staff "<<i+1<<":\n";
        tnts[i].putdata();
    }

    for(i=0;i<n4;i++)
    {
        cout<<"\n\nDetails of non-technical non-teaching staff "<<i+1<<":\n";
        ntnts[i].putdata();
    }

    return 0;
}







