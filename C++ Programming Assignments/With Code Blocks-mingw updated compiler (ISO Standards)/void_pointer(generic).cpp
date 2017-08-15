#include<iostream>
#include<conio.h>
using namespace std;
void inc(void* data,int psize)
{
          if(psize==sizeof(char))
          {
           char* pchar;
           pchar=(char*)data;
           ++(*pchar);
          }
          else if(psize==sizeof(int))
          {
           int* pint;
           pint=(int*)data;
           ++(*pint);
          }
}
int main()
{
    char a='x';
    int b=1602;
    inc(&a,sizeof(a));
    inc(&b,sizeof(b));
    cout<<a<<','<<b<<endl;
    getch();
}
