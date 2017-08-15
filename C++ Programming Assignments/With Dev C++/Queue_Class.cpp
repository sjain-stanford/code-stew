/*
Define a class ‘queue’ with required data members. Consider the queue as an array of elements
with two pointers ‘front’ and ‘rear’ by which the elements of the queue can be accessed.
Use constructors to initialize the size of the queue by default as 20, when not provided by the user.
Include member functions to
	(i) Insert an element into the queue
	(ii) Delete an element from the queue
	(iii) Check for queue overflow and underflow.
Write a menu driven program to simulate these queue operations.
*/
#include<iostream.h>
#include<conio.h>

class queue
{
      private:
              int front;
              int rear;
              int n;
              int a[50];

      public:
             queue()
             {
             }
             queue(int size)
             {
                       front=-1;
                       rear=-1;
                       n=size;
                       cout<<"\nSize of queue is chosen as: "<<n<<"\n";
             }
             int ins(int el)
             {
                 if(rear==n-1)
                 return -1;
                 if(rear==-1)
                 {
                             front=0;
                             rear=0;
                             a[rear]=el;
                 }
                 else
                 {
                             rear++;
                             a[rear]=el;
                             cout<<a[rear];
                 }
                 return 0;
             }
             int del()
             {
                 int ret;
                 if(front==-1)
                 return -1;
                 else
                 {
                     ret=a[front];
                     if(front==rear)
                     {
                                    front=-1;
                                    rear=-1;
                     }
                     else
                     front++;
                 }
                 return ret;
             }
             void disp()
             {
                  if(front==-1)
                  return;
                  int i;
                  for(i=front;i<=rear;i++)
                  cout<<"\t"<<a[i];
                  cout<<"\n";
             }
};

main()
{
     int ch1,ch2,elm,chk,size;
     cout<<"Choose one of the following:\n1. Default size (20 elements)\n2. User defined size\n";
     cin>>ch1;
     switch(ch1)
     {
                case 1:
                     size=20;
                     break;
                case 2:
                     cout<<"Enter the desired size of the queue: ";
                     cin>>size;
                     break;
     }
     queue q1(size);
     z:
     cout<<"\nChoose one of the following:\n1. Insert element\n2. Delete element\n3. Exit\n";
     cin>>ch2;
     switch(ch2)
     {
               case 1:
                    cout<<"\nEnter the element to be inserted: ";
                    cin>>elm;
                    chk=q1.ins(elm);
                    if(chk==-1)
                    {
                               cout<<"\nOVERFLOW!! Delete an element before entering a new one\n";
                               getch();
                               goto z;
                    }
                    cout<<"\n\nThe queue is: ";
                    q1.disp();
                    goto z;

               case 2:
                    chk=q1.del();
                    if(chk==-1)
                    {
                               cout<<"\nUNDERFLOW!! There's no element to be deleted\n";
                               getch();
                               goto z;
                    }
                    cout<<"\nThe deleted element is: "<<chk;
                    cout<<"\n\nThe queue is: ";
                    q1.disp();
                    goto z;

               case 3:
                    goto y;

               default:
                    cout<<"Enter a valid choice!";
                    getch();
                    goto z;
     }
getch();
y:
return 0;
}










