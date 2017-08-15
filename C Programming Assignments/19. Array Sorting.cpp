#include<stdio.h>
#include<conio.h>
main()
{
      int n,a[50];
      printf("Enter the no. of terms:");
      scanf("%d",&n);
      printf("Enter the %d terms:",n);
      for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
      for(int j=0;j<n-1;j++)
      for(int k=j+1;k<=n-1;k++)
      {
              if(a[j]>a[k])
              {
                           int t;
                           t=a[j];
                           a[j]=a[k];
                           a[k]=t;
                           }
                           }
printf("The ascending order is:\n");
for(int m=0;m<n;m++)
printf("%d\n",a[m]);
getch();
}

                           
      
