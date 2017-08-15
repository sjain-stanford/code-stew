#include<stdio.h>
#include<conio.h>
#define MR 30
#define MC 30
main()
{
      int a[MR][MC],b[MR][MC],c[MR][MC],rows,cols,choice;
      void input(int z[MR][MC],int rows,int cols);
      void matadd(int a[MR][MC],int b[MR][MC],int c[MR][MC],int rows,int cols);
      void output(int c[MR][MC],int rows,int cols);
      void matmul(int a[MR][MC],int b[MR][MC],int c[MR][MC],int rows,int cols);
      
      printf("Enter the number of rows and columns:\n\n");
      scanf("%d %d",&rows,&cols);
      
      printf("Enter the elements of A: \n\n"); 
      input(a,rows,cols);
      printf("Enter the elements of B: \n\n");
      input(b,rows,cols);
      
      printf("Enter your choice: \n 1.Addition \n 2.Multiplication \n");
      scanf("%d",&choice);
      switch(choice)
      {
                    case 1:
                    matadd(a,b,c,rows,cols);
                    output(c,rows,cols);
                    break;
                    
                    case 2:
                    matmul(a,b,c,rows,cols);
                    output(c,rows,cols);
                    break;
                    
                    default:
                    printf("Enter a valid choice.");
                    break;
                    }     
      
      
      getch();
      }
      
      
          
void input(int z[MR][MC],int rows,int cols)
{
     for(int i=0;i<rows;i++)
     {
             printf("Enter the elements of Row %d :\n",i+1);
             for(int j=0;j<cols;j++)
             scanf("%d",&z[i][j]);
             }
             return;
             }
     
void matadd(int a[MR][MC],int b[MR][MC],int c[MR][MC],int rows,int cols)
{
     for(int i=0;i<rows;i++)
     for(int j=0;j<cols;j++)
     c[i][j]=a[i][j]+b[i][j];
     return;
     }
     
void matmul(int a[MR][MC],int b[MR][MC],int c[MR][MC],int rows,int cols)
{
      int sum=0;
      for(int i=0;i<rows;i++)
      {
              for(int j=0;j<cols;j++)
              {
                   for(int k=0;k<rows;k++)
                   {
                           sum=sum+(a[i][k]*b[k][j]);
                   }
                c[i][j]=sum;
                sum=0;
                }
      }   
      return;
      }        
                      






void output(int c[MR][MC],int rows,int cols)
{
     printf("The resultant matrice is :\n");
     for(int i=0;i<rows;i++)
     {
             for(int j=0;j<cols;j++)
             {
             printf("%d\t",c[i][j]);
             }
             printf("\n");
     }
     return;
     }
