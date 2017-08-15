#include<string.h>
#include<conio.h>
#include<stdio.h>
    main()
    {
        char strp[] = "Never ever say no";
        char *chp, c='e';
clrscr();
        int i,j;
        chp = strrchr(strp, c);
        i = chp-strp;
        for(j=0;j<=i;j++)
                printf("%c",strp[j]);
}