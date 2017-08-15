#include<iostream.h>
#include<stdio.h>

class inst                              //Institute
{
      private:
	      char name[30];
	      char dept[30];
      public:
	     void getdata()
	     {
		  cout<<"\nEnter name of Institute: ";
		  gets(name);
		  cout<<"\nEnter the Department: ";
		  gets(dept);
	     }
	     void putdata()
	     {
		  cout<<"\nName: "<<name;
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
		  cout<<"\nEnter Semester: ";
		  cin>>sem;
		  cout<<"\nEnter Roll No: ";
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
		  cout<<"\nEnter Designation: ";
		  cin>>desig;
		  cout<<"\nEnter Salary (in Rs.): ";
		  cin>>sal;
	     }
	     void putdata()
	     {
		  inst::putdata();
		  cout<<"\nDesignation: "<<desig;
		  cout<<"\nSalary: Rs."<<sal;
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
		  cout<<"\nEnter Qualification: ";
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
		  cout<<"\nEnter no. of years of experience: ";
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
    stud s;
    ts f;
    tech t;
    ntech nt;

    cout<<"\nEnter details for Student 1:\n";
    s.getdata();

    cout<<"\nEnter details for Teaching Staff 1:\n";
    f.getdata();

    cout<<"\nEnter details for Technical Non-teaching Staff 1:\n";
    t.getdata();

    cout<<"\nEnter details for Non-technical Non-teaching Staff 1:\n";
    nt.getdata();

    cout<<"\n\nDetails of Student 1:\n";
    s.putdata();

    cout<<"\n\nDetails of Teaching Staff 1:\n";
    f.putdata();

    cout<<"\n\nDetails of Technical Non-teaching Staff 1:\n";
    t.putdata();

    cout<<"\n\nDetails of Non-technical Non-teaching Staff 1:\n";
    nt.putdata();

    return 0;
}







