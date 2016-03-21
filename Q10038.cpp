#include<stdio.h>
#define MAX_NUM 3001
int abs(int a,int b);
int main(void)
{
    int i, n, t, a, b, YorN;
    int x[MAX_NUM];
    while(scanf("%d", &n)==1)
    {
        for(i=0;i<=n;i++)
            x[i] = 0;
        scanf("%d", &b);
        
        YorN = 1;
        for(i=1;i<n;i++)
        {
            scanf("%d", &a);
            t = abs(a, b);
            if(t>=n)
                YorN = 0;
            else if(x[t]==1)
                YorN = 0;
            else
                x[t] = 1;
            b = a;
        }
        if(YorN==1)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
int abs(int a,int b)
{
    if(a>b)
        return a-b;
    else
        return b-a;
}
