/*
The "source.ass" should comply to the following specifications
1. Comments should follow after ';'
2. First line should be of the form "ORG 1000H" which would specify the starting address
3. MVI command should be as "MVI A , 08" with at least one space between every word
4. All EQU commands should be placed at the end of the file
5. Keywords should be separated from symbol names by at least one space
*/

#include<iostream>
#include<fstream>       //For file handling
#include<cstring>       //To use strcmp(a,b), strlen(a)
#include<math.h>        //To use pow(a,b)
using namespace std;
char* p;        //To store the assembler-specific keywords like LDA, STA, JZ etc.
int adrs=0;     //To calculate addresses of consecutive lines in the assembly file in hexadecimal
ifstream infile,intemp;     //Input stream objects
ofstream outfile;           //Output stream object
ostream& dispwidth(ostream& out)        //User-defined manipulator to set display width and left-justify the output
{
    out.width(15);
    out.setf(ios::left,ios::adjustfield);
    return out;
}
void conv()     //This function converts the given "source.ass" to "newsrc.txt" after removing comments and redundant spaces in the source file
{
    char* z=new char[50];
    while(!infile.eof())
    {
        infile.getline(z,50,'\n');
        for(int i=0;;i++)
        {
            if((z[i]==';')||(z[i]=='\0'))   //Comments start after ; (semi-colon)
            break;
            else
            {
                if(((z[i]==' ')||(z[i]=='\t'))&&((z[i+1]==' ')||(z[i+1]=='\0')||(z[i+1]==';')||(z[i+1]=='\t')))  //To remove redundant spaces and tabs from source file
                continue;
                outfile<<z[i];
            }
        }
        outfile<<'\n';
    }
    delete z;
}
void value()    //To retrieve the value/address stored in a symbol
{
    char* z=new char[30];
    int i=0,s=0,n=0,m=0;    //s - no of spaces
    while(!infile.eof())
    {
        s=0;
        infile.getline(z,30,'\n');
        for(n=0;n<strlen(z);n++)    //To count no of spaces
        {
            if(z[n]==' ')
            s++;
        }
        if(s==2)    //Only statements with 2 spaces assign value/address to symbols
        {
            n=0;
            outfile<<'\n';
            while(z[n]!=' ')    //Output the symbol name
            {
                outfile<<z[n];
                n++;
            }
            outfile<<' ';
            if((z[n+1]=='E')&&(z[n+2]=='Q')&&(z[n+3]=='U'))     //If EQU statement, output the value
            {
                for(m=n+5;m<strlen(z);m++)
                outfile<<z[m];
            }
            else        //Else output the line no. of the line in "object.txt" which is addressed by the symbol
            outfile<<"line"<<' '<<i;
        }
        i++;
    }
    delete z;
}
int tohex(char a)      //Returns an integer corresponding to each hexadecimal digit
{
    if(a>=48&&a<=57)        //If 'a' stores a digit (0-9)
    return (a-48);
    else if(a>=65&&a<=70)   //If 'a' stores an upper-case alphabet (A-F)
    return (a-55);
    else if(a>=97&&a<102)   //If 'a' stores a lower-case alphabet (a-f)
    return (a-87);
}
int hexadec(char ch[4])        //This converts the hexadecimal address into its decimal equivalent by multiplying with weighted powers of 16
{
    int sum=0,rem=0;
    for(int i=0;i<=3;i++)
    {
        rem=tohex(ch[i]);
        sum+=rem*pow(16,i);
    }
    return sum;
}
int hash(char* a)   //This returns a unique hash value for each particular keyword
{
    if((strcmp(a,"LDA")==0)||(strcmp(a,"STA")==0)||(strcmp(a,"JMP")==0)||(strcmp(a,"JZ")==0))
    return 3;
    else if(strcmp(a,"MVI")==0)
    return 2;
    else if((strcmp(a,"ADD")==0)||(strcmp(a,"INR")==0)||(strcmp(a,"SUB")==0)||(strcmp(a,"HLT")==0))
    return 1;
    else
    return 0;
}
int init()  //This completes the initialization process by assigning the starting address to statement in "newsrc.txt"
{
    char hexadrs[4];    //To store the 4-bit starting address
    p=new char[3];
    infile>>p;
    if(strcmp(p,"ORG")!=0)
    {
        cout<<"origin of the code not defined! TERMINATING!!";
        return 0;
    }
    else
    infile>>hexadrs[3]>>hexadrs[2]>>hexadrs[1]>>hexadrs[0];
    adrs=hexadec(hexadrs);
    outfile.setf(ios::hex,ios::basefield);
    outfile<<adrs<<' ';
    infile>>p;  //This is done to extract & discard the suffix 'H' representing hexadecimal nos. (eg. ORG 1000H)
    delete p;
    return 1;
}
int main()
{
    cout<<"\nreading source file....'source.ass'\n";
    infile.open("source.ass");
    outfile.open("newsrc.txt");
    cout<<"\ncreating new source file....'newsrc.txt'\n";
    conv();         //To remove comments and redundant spaces from the source file
    infile.close();
    outfile.close();
    cout<<"\nformulating object file....'object.txt'\n";
    infile.open("newsrc.txt");
    outfile.open("object.txt");
    if(!init())
    return 0;
    while(!infile.eof())
    {
       p=new char[10];
       infile>>p;       //Extracts the assembler-specific keywords like LDA, STA, JZ etc.
       int h=hash(p);   //Calls the hash table to return a unique hash value for each particular keyword
       delete p;
       char* z;         //To retrieve and store symbols
       switch(h)
       {
           case 3:
                adrs+=3;    //Since 3-byte instructions
                z=new char[10];
                infile>>z;
                outfile<<z<<endl;
                outfile<<adrs<<' ';
                delete z;
                break;
            case 2:
                adrs+=2;    //Since 2-byte instructions
                z=new char[10];
                infile>>z;
                outfile<<z<<endl;
                outfile<<adrs<<' ';
                infile>>z>>z;   //To discard the comma and value moved; i.e in "MVI A , #08" discard ", #08"
                delete z;
                break;
            case 1:
                adrs+=1;    //Since 1-byte instructions
                z=new char[10];
                infile>>z;
                outfile<<z<<endl;
                outfile<<adrs<<' ';
                delete z;
        }
    }
    outfile.unsetf(ios::hex);
    infile.close();
    outfile.close();
    cout<<"\nprocuring values of symbols....'values.txt'\n";
    infile.open("newsrc.txt");
    outfile.open("values.txt");
    value();        //To retrieve the value/address stored in a symbol
    infile.close();
    outfile.close();
    infile.open("object.txt");
    char* ad[20];   //To store line addresses
    char* symb[20]; //To store symbols referenced at corresponding addresses
    int i=0;
    while(!infile.eof())
    {
        ad[i]=new char;
        infile>>ad[i];
        symb[i]=new char;
        infile>>symb[i];
        i++;
    }
    infile.close();
    infile.open("values.txt");
    char* val[20];
    char* z=new char[10];
    while(!infile.eof())
    {
        infile>>z;
        for(int r=0;r<i-1;r++)
        {
            if(!strcmp(z,symb[r]))
            {
                val[r]=new char;
                infile>>val[r];
                if(!strcmp(val[r],"line"))
                {
                    int lnum;       //Line number
                    infile>>lnum;
                    intemp.open("object.txt");
                    for(int m=1;m<lnum;m++)
                    intemp>>val[r]>>val[r];
                    intemp>>val[r];
                    intemp.close();
                }
                break;
            }
        }
    }
    delete z;
    infile.close();
    cout<<"\nstoring symbol table....'symbol.txt'\n";
    outfile.open("symbol.txt");
    outfile<<dispwidth<<"SYMBOL"<<dispwidth<<"VALUE/ADDRESS"<<dispwidth<<"\tREFERENCED at"<<endl;
    int flag[100];
    for(int x=0;x<100;x++)
    flag[x]=0;
    for(int j=0;j<i-1;j++)
    {
        if(flag[j]!=1)
        {
            outfile<<'\n'<<dispwidth<<symb[j]<<dispwidth<<val[j]<<'\t'<<ad[j];
            flag[j]=1;
        }
        for(int k=j+1;k<i-1;k++)
        {
            if((strcmp(symb[j],symb[k])==0)&&(flag[k]!=1))
            {
                outfile<<','<<ad[k];
                flag[k]=1;
            }
        }
    }
    outfile.close();
    return 0;
}
