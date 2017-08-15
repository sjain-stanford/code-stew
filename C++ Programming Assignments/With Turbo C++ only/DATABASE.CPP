#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

//This program accepts student details from the user, arranges it Department-wise, Semester-wise, Name-wise and displays it
struct student
{
       char name[20],dept[30];
       int roll,sem;
       float cgpa;
}a[10];

void enter(int x)
{
     cout<<"\n\nEnter the details of student "<<x+1<<":";
     cout<<"\nName:";
     gets(a[x].name);
     cout<<"\nDept:";
     gets(a[x].dept);
     cout<<"\nRoll No.:";
     cin>>a[x].roll;
     cout<<"\nSemester (in numerical) :";
     cin>>a[x].sem;
     cout<<"\nCGPA:";
     cin>>a[x].cgpa;
}

void sort(int n)
{
	int b,c;
	student temp;
	for(b=0;b<n-1;b++)
	{
		for(c=1;c<n-b;c++)
		{
			if(strcmp(a[c-1].dept,a[c].dept)>0)
			{
				temp=a[c-1];
				a[c-1]=a[c];
				a[c]=temp;
			}
			if(strcmp(a[c-1].dept,a[c].dept)==0)
			{
				if(a[c-1].sem>a[c].sem)
				{
					temp=a[c-1];
					a[c-1]=a[c];
					a[c]=temp;
				}
				if(a[c-1].sem==a[c].sem)
				{
					if(strcmp(a[c-1].name,a[c].name)>0)
					{
						temp=a[c-1];
						a[c-1]=a[c];
						a[c]=temp;
					}
				}
			}
		}
	}
}

void disp(int n)
{
	int i;
	cout<<"\n\nThe student details are:\n\n";
	cout<<"Department\tSemester\tName\tRoll No.\tCGPA\n";
	for(i=0;i<n;i++)
	cout<<a[i].dept<<"\t\t"<<a[i].sem<<"\t\t"<<a[i].name<<"\t"<<a[i].roll<<"\t\t"<<a[i].cgpa<<'\n';
}

main()
{
       clrscr();
       int n,i;
       cout<<"Enter the number of students with details to be entered: ";
       cin>>n;
       for(i=0;i<n;i++)
       enter(i);
       sort(n);
       disp(n);
       getch();
       return 0;
}
