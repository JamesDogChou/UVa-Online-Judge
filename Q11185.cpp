#include<stdio.h>
int main(void)
{
    long i, j, inum, tflag;
    int tnum[25];
    while(scanf("%ld", &inum)==1)
    {
        if(inum<0)
            break;
        for(i=0;i<25;i++)
            tnum[i] = 0;
        tflag = 0;
        while(inum!=0)
        {
            tnum[tflag++] = inum % 3;
            inum /= 3;
        }
        for(i=24;i>=0;i--)
        {
            if(tnum[i]>0)
            {
                for(j=i;j>=0;j--)
                    printf("%d", tnum[j]);
                break;
            }
            else if(i==0)
            {
                printf("0");
            }
        }
        putchar('\n');
    }
    return 0;
}
