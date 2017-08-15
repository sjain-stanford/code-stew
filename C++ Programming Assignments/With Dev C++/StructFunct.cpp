#include<iostream.h>
#include<conio.h>
//------------------------------------------------------------------------------
struct distance
{
       float feet;
       float inches;
}d1,d2;
//------------------------------------------------------------------------------
distance convinch(distance a)  //Converts the feet:inches to inches 
{
      a.inches+=(a.feet)*12;
      return a;
}
//------------------------------------------------------------------------------
main()
{
      cout<<"Enter the first distance in the form FEET INCHES : ";
      cin>>d1.feet>>d1.inches;
      cout<<"Enter the second distance in the form FEET INCHES : ";
      cin>>d2.feet>>d2.inches;
      d1=convinch(d1);
      d2=convinch(d2);
      cout<<"First distance in INCHES is : "<<d1.inches<<endl;
      cout<<"Second distance in INCHES is : "<<d2.inches<<endl;
      getch();
}
      
      
            
      
