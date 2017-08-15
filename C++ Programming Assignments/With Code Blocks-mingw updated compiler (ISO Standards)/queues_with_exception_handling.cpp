#include<iostream>
#include<conio.h>
#define MAX 4
using namespace std;

class queue
{
    private:
        int arr[MAX];
        int front,rear;
    public:
        queue():front(-1),rear(-1){}
        class qfull     //exception class ; thrown when queue is full
        {
        };
        class qempty    //exception class ; thrown when queue is empty
        {
        };
        void addq(int item)
        {
            if(rear==MAX-1)
            throw qfull();  //queue full
            arr[++rear]=item;
            if(front==-1)
            front=0;
        }
        int delq()
        {
            if(front==-1)
            throw qempty(); //queue empty
            int data=arr[front];
            if(front==rear)
            front=rear=-1;
            else
            front++;
            return data;
        }
};

int main()
{
    queue q;
    char ch;
    try
    {
        do
        {
            int e;
            cout<<"enter element: ";
            cin>>e;
            q.addq(e);
            cout<<"enter more? (y/n): ";
            cin>>ch;
        }while(ch=='y');
    }
    catch(queue::qfull)     //catch block for a queue-full exception
    {
        cout<<"\nqueue full! overflow!\n";
    }
    try
    {
        cout<<"\nnow deleting elements....\n";
        do
        {
            int e;
            e=q.delq();
            cout<<"deleted element: "<<e;
            cout<<"\ndelete more? (y/n): ";
            cin>>ch;
        }while(ch=='y');
    }
    catch(queue::qempty)    //catch block for a queue-empty exception
    {
        cout<<"\nqueue empty! underflow!\n";
    }
    getch();
    return 0;
}
