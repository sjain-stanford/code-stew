#include<iostream.h>
#include<conio.h>
#include<math.h>
#define pi 3.141592654

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
      void show()
      {
           cout<<"\nRadius= "<<rad<<" units"<<"\nAngle= "<<ang<<" degrees";
      }
};
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
      polar rect2pol()
      {
            float t1,t2;
            t1=sqrt(xc*xc+yc*yc);
            t2=(atan(yc/xc))*(180.0/pi);
            if(xc<0 && yc>0)
            t2+=180.0;
            if(xc<0 && yc<0)
            t2-=180.0;
            return polar(t1,t2);
      }
};
int main()
{
     float u,v;
     cout<<"Enter the rectangular co-ordinates (x,y): ";
     cin>>u>>v;
     rec r(u,v);
     polar p=r.rect2pol();
     p.show();
     getch();
     return 0;
}
