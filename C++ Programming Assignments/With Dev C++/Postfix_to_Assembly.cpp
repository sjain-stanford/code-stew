/*
Assume a machine has a single register and six instructions:
LDA  A		Places an operand A into the register
STA  A		Places the contents of the register into the variable A
ADD  A	    Adds the content of variable A to the register
SUB  A		Subtracts the contents of the variable A from the register
MUL  A	    Multiplies the contents of the register by the variable A
DIV  A		Divides the contents of the register by the variable A

Write a program that accepts a postfix expression as a pointer variable containing single letter operands and the operators +, -, *, / and prints the sequence of instructions to evaluate the expression and leave the result in the register. Use variables of the form TEMPn as temporary variables. For example using the postfix expression ABC*+DE-/ should print the following
LDA  B				LDA  D
MUL  C			    SUB  E
STA  TEMP1			STA  TEMP3
LDA  A				LDA  TEMP2
ADD  TEMP1			DIV  TEMP3
STA  TEMP2			STA  TEMP4
*/
#include<iostream.h>
#include<conio.h>

void mod(char post[1][15])
{
     char stck[15],a,b,x,count='0';
     int i=0,top=-1;

     while(post[0][i]!='\0')
     {
                             if((post[0][i]!='+')&&(post[0][i]!='-')&&(post[0][i]!='*')&&(post[0][i]!='/'))
                             {
                                  top++;
                                  stck[top]=post[0][i];
                                  goto next;
                             }
                             else
                             {
                                 x=post[0][i];
                                 b=stck[top];
                                 top--;
                                 a=stck[top];
                                 top--;
                             }
                             if(x=='+')
                             {
                                       count++;
                                       cout<<"LDA "<<a<<endl;
                                       cout<<"ADD "<<b<<endl;
                                       cout<<"STA "<<count<<endl;
                             }
                             else if(x=='-')
                             {
                                       count++;
                                       cout<<"LDA "<<a<<endl;
                                       cout<<"SUB "<<b<<endl;
                                       cout<<"STA "<<count<<endl;
                             }
                             else if(x=='*')
                             {
                                       count++;
                                       cout<<"LDA "<<a<<endl;
                                       cout<<"MUL "<<b<<endl;
                                       cout<<"STA "<<count<<endl;
                             }
                             else if(x=='/')
                             {
                                       count++;
                                       cout<<"LDA "<<a<<endl;
                                       cout<<"DIV "<<b<<endl;
                                       cout<<"STA "<<count<<endl;
                             }
                             top++;
                             stck[top]=count;
                             next:
                             i++;
     }
     return;
}

int main()
{
    char post[1][15];
    cout<<"Please enter the postfix expression (including +,-,* and / only): ";
    gets(post[0]);
    mod(post);
    getch();
    return 0;
}
