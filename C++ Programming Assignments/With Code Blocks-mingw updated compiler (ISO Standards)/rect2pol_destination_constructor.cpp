#include<iostream>
#include<math.h>
#include<conio.h>
#define pi 3.141592654
using namespace std;

class rec
{
      float xc,yc;
      public:
      rec():xc(0),yc(0)
      {
      }
      rec(float c,float d):xc(c),yc(d)
      {
      }
      float getx()
      {
          return xc;
      }
      float gety()
      {
          return yc;
      }
};

class polar
{
      float rad,ang;
      public:
      polar():rad(0),ang(0)
      {
      }
      polar(float a,float b):rad(a),ang(b)
      {
      }
      polar(rec r)
      {
          rad=sqrt(r.getx()*r.getx()+r.gety()*r.gety());
          ang=(atan(r.gety()/r.getx()))*(180.0/pi);
          if(r.getx()<0 && r.gety()>0)
          ang+=180.0;
          if(r.getx()<0 && r.gety()<0)
          ang-=180.0;
      }
      void show()
      {
           cout<<"\nRadius= "<<rad<<" units"<<"\nAngle= "<<ang<<" degrees";
      }
};

int main()
{
     float u,v;
     cout<<"Enter the rectangular co-ordinates (x,y): ";
     cin>>u>>v;
     rec r(u,v);
     polar p=r;   //Can also be written as
                  //polar p(r);
     p.show();
     getch();
     return 0;
}
