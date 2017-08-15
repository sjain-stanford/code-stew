#include<stdio.h>
#include<conio.h>
#define MR 30
#define MC 30
main()
{
      start:
      int a[MR][MC],b[MR][MC],c[MR][MC],row1,col1,row2,col2,choice;
      void input(int z[MR][MC],int rows,int cols);
      void matadd(int a[MR][MC],int b[MR][MC],int c[MR][MC],int rows,int cols);
      void output(int c[MR][MC],int rows,int cols);
      void matmul(int a[MR][MC],int b[MR][MC],int c[MR][MC],int row1,int col2,int midval);
      
      printf("Enter the number of rows and columns of A:\n\n");
      scanf("%d %d",&row1,&col1);
      printf("Enter the number of rows and columns of B:\n\n");
      scanf("%d %d",&row2,&col2);
      
      printf("Enter the elements of A: \n\n"); 
      input(a,row1,col1);
      printf("Enter the elements of B: \n\n");
      input(b,row2,col2);
      
      printf("Enter your choice: \n 1.Addition \n 2.Multiplication \n");
      scanf("%d",&choice);
      switch(choice)
      {
                    case 1:
                    if((row1==row2)&&(col1==col2))
                    {
                                                  matadd(a,b,c,row1,col1);
                                                  output(c,row1,col1);
                                                  }
                    else
                    {
                        printf("Enter the two matrices of equal order.\n\n");
                        goto start;
                        }
                        
                    break;
                    
                    case 2:
                    if(col1==row2)
                    {
                                  matmul(a,b,c,row1,col2,col1);
                                  output(c,row1,col2);
                                  }
                    else
                    {
                        printf("Columns of A is not equal to Rows of B.\n\n");
                        goto start;
                        }
                        
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
     
void matmul(int a[MR][MC],int b[MR][MC],int c[MR][MC],int row1,int col2,int midval)
{
      int sum=0;
      for(int i=0;i<row1;i++)
      {
              for(int j=0;j<col2;j++)
              {
                   for(int k=0;k<midval;k++)
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
     printf("The resultant matrix is :\n");
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
