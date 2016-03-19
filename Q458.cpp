#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    char c[2000];
    int i, lc;
    while(scanf("%s",&c)!=EOF)
    {
        lc = strlen(c);
        for(i=0;i<lc;i++)
            printf("%c", char(int(c[i])-7));
        putchar('\n');
    }
    return 0;
}
