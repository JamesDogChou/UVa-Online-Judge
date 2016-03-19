#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int N, a, t, yorn = 0;
    int i, j, k, l;
    scanf("%d", &N);
    for(i=0;i<N;i++)
    {
        scanf("%d%d", &a, &t);
        for(j=0;j<t;j++)
        {
            if(yorn==1)
                putchar('\n');
            yorn = 1;
            for(k=1;k<=a;k++)
            {
                for(l=0;l<k;l++)
                    printf("%d", k);
                putchar('\n');
            }
            for(k=a-1;k>0;k--)
            {
                for(l=0;l<k;l++)
                    printf("%d", k);
                putchar('\n');                  
            }
        }
    }
    return 0;
}
