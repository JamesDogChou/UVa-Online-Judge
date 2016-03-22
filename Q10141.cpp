#include<stdio.h>
#include<string.h>
#define MAX_N 1000
#define MAX_CHAR 100

int main(void)
{
    int i, j, m, n, x = 1, p[MAX_N], ans;
    char com[MAX_N][MAX_CHAR], garbage[MAX_CHAR];
    double money[MAX_N];
    while(scanf("%d%d",&m,&n)==2)
    {
        if(!m && !n)
            break;
        scanf("\n");
        for(i=0;i<m;i++)
            gets(garbage);
        for(i=0;i<n;i++)
        {
            gets(com[i]);
            scanf("%lf %d\n", &money[i], &p[i]);
            for(j=0;j<p[i];j++)
                gets(garbage);
        }
        ans = 0;
        for(i=1;i<n;i++)
            if(p[i]>p[ans] || (p[i]==p[ans] && money[i]<money[ans]))
                ans = i;
        if(x!=1)
            putchar('\n');
        printf("RFP #%d\n%s\n", x++, com[ans]);
    }
    return 0;
}
