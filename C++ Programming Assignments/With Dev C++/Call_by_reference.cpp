#include<stdio.h>
#include<conio.h>
//Complex way of calling by reference
int larger(int& a,int& b);
//-----------------------------------------
main() 
{
     int x,y;
     int c;
     printf("Enter two numbers : ");
     scanf("%d %d",&x,&y);
     c=larger(x,y);
     printf("The larger number is %d\n",c);
     getch();
}

//------------------------------------------     
int larger(int& a,int& b)
{
    if(a>b)
    return a;
    else
    return b;
}
