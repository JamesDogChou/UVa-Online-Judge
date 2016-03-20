#include<stdio.h>
int main(void)
{
    int i, n, num[55], sum, ans, x = 1;
    while(scanf("%d",&n)==1)
    {
        if(!n)
            break;
        sum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d", &num[i]);
            sum += num[i];
        }
        sum /= n;
        ans = 0;
        for(i=0;i<n;i++)
        {
            if(num[i] > sum)
                ans += num[i] - sum;
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", x++, ans);
    }
    return 0;
}
