#include<iostream.h>
#include<conio.h>
#include<math.h>

#define pi 3.141592654

struct rect
{
       float x,y;
}r[10];

struct pol
{
       float r,th;
}p[10];      

void creater(int i)
{
     cout<<"Enter the x"<<i+1<<": ";
     cin>>r[i].x;
     cout<<"Enter the y"<<i+1<<": ";
     cin>>r[i].y;
}

void createp(int i)
{
     cout<<"Enter the magnitude r"<<i+1<<": ";
     cin>>p[i].r;
     cout<<"Enter the angle theta(radian)"<<i+1<<": ";
     cin>>p[i].th;
}
     
void dispr(rect a)
{
     
     cout<<"\n"<<a.x<<"+j"<<a.y;
}

void dispp(pol a)
{
     cout<<"\n"<<a.r<<"(cos"<<a.th<<"+ jsin"<<a.th<<")";
}
     
void addrr(rect a,rect b)
{
     float m,n;
     m=a.x+b.x;
     n=a.y+b.y;
     cout<<"\nResult: "<<m<<"+ j"<<n;
     cout<<"\nPress Enter key!\n";
     getch();
}
     
void addpp(pol a,pol b)
{
     float m,n,p,q;
     m=((a.r)*cos(a.th)+(b.r)*cos(b.th));
     n=((a.r)*sin(a.th)+(b.r)*sin(b.th));
     p=sqrt((m*m)+(n*n));
     if(m>0&&n>0)
     q=atan(n/m);
     else if(m<0&&n>0)
     q=pi+atan(n/m);
     else if(m<0&&n<0)
     q=atan(n/m)-pi;
     else
     q=atan(n/m);
     cout<<"\nResult: "<<p<<"(cos"<<q<<"+ jsin"<<q<<")";
     cout<<"\nPress Enter key!\n";
     getch();
}
     
void addrp(rect a,pol b)
{
     float m,n,p,q;
     m=(b.r)*cos(b.th);
     n=(b.r)*sin(b.th);
     p=a.x+m;
     q=a.y+n;
     cout<<"\nResult: "<<p<<"+ j"<<q;
     cout<<"\nPress Enter key!\n";
     getch();
}

main()
{
      int ch,nr,np,i,j,k;
      cout<<"Enter the number of rectangular quantities: ";
      cin>>nr;
      cout<<"Enter the number of polar quantities: ";
      cin>>np;
      for(i=0;i<nr;i++)
      creater(i);
      for(i=0;i<np;i++)
      createp(i);
      for(i=0;i<nr;i++)
      dispr(r[i]);
      for(i=0;i<np;i++)
      dispp(p[i]);
      start:
      cout<<"\n\nChoose one of these: \n1. Rect + Rect\n2. Pol + Pol\n3. Rect + Pol\n";
      cin>>ch;
      switch(ch)
      {
                case 1:
                     cout<<"Enter which two Rectangular quantities you wish to add: ";
                     cin>>j>>k;
                     addrr(r[j-1],r[k-1]);
                     goto start;
                case 2:
                     cout<<"Enter which two Polar quantities you wish to add: ";
                     cin>>j>>k;
                     addpp(p[j-1],p[k-1]);
                     goto start;
                case 3:
                     cout<<"Enter which Rectangular quantity and which Polar quantity you wish to add: ";
                     cin>>j>>k;
                     addrp(r[j-1],p[k-1]);
                     goto start;
                default:
                     cout<<"Invalid choice!";
                     goto start;
      }
      getch();
}              
                         
