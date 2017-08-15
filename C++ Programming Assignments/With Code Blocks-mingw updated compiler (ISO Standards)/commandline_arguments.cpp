/*
Simple program that uses command-line arguments passed to it.
Step 1: Write the program code in any C++ IDE like CodeBlocks
Step 2: Compile and Run to create "commandline_arguments.exe"
Step 3: Place the .exe file in the desired location (e.g. "c:\myfolder\commandline_arguments.exe")
Step 4: Go to RUN (in Start Menu) and type cmd, press ENTER
Step 5: Type "cd c:\myfolder" (without quotes) This changes the current directory as specified
Step 6: Type "commandline_arguments.exe Sambhav is a good boy" (without quotes)
Step 7: Thats it!!
*/

#include<iostream>
using namespace std;
int main(int argc,char* argv[])
{
    cout<<"\nargc = "<<argc<<endl;    //number of arguments
    for(int i=0;i<argc;i++)
    cout<<"argument "<<i<<" = "<<argv[i]<<endl;
    return 0;
}
