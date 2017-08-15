#include<iostream.h>
#include<conio.h>
#define MAX 10

template <class T>
class stack
{
    private:
        T stk[MAX];
        int top;
    public:
        stack():top(-1){}
        void push(T data)
        {
            if(top==MAX-1)
            cout<<endl<<"overflow! stack is full";
            else
            {
                top++;
                stk[top]=data;
            }
        }
        T pop()
        {
            if(top==-1)
            cout<<endl<<"underflow! stack if empty";
            else
            {
                T temp=stk[top];
                top--;
                return temp;
            }
        }
};

class dist
{
    private:
        float feet,inches;
    public:
        dist():feet(0),inches(0){}
        dist(float a,float b):feet(a),inches(b){}
        friend ostream& operator<<(ostream& out,dist& d);
};

ostream& operator<<(ostream& out,dist& d)
{
    out<<d.feet<<' '<<d.inches;
    return out;
}

int main()
{
    stack<int> s1;     //template used for built-in datatype
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout<<endl<<s1.pop();
    cout<<endl<<s1.pop();
    cout<<endl<<s1.pop();

    stack<float> s2;   //template used for built-in datatype
    s2.push(10.123);
    s2.push(20.456);
    s2.push(30.789);
    cout<<endl<<s2.pop();
    cout<<endl<<s2.pop();
    cout<<endl<<s2.pop();

    dist d1(1.5,2.5),d2(3.4,4.4),d3(5.7,6.7);
    stack<dist> s3;    //template used for user-defined datatype
    s3.push(d1);
    s3.push(d2);
    s3.push(d3);
    cout<<endl<<s3.pop();
    cout<<endl<<s3.pop();
    cout<<endl<<s3.pop();

    getch();
    return 0;
}
