#include<stdio.h>
#include<stdlib.h>
int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}; //List of prime numbers up to 100
int ans[101][25]={0};

int main(void)
{
    int ii, i, j, inp;
    ans[2][0] = 1;
    for(i=3;i<101;i++)
    {
        for(j=0;j<25;j++)
        {
            if(ans[i-1][j]==0)
                break;
            ans[i][j] = ans[i-1][j];
        }
        ii = i;
        for(j=0;j<25;j++)
            while(ii%prime[j]==0 && ii>1)
            {
                ans[i][j]++;
                ii /= prime[j];
            }
    }
    while(scanf("%d", &inp)==1)
    {
        if(!inp)
            break;
        printf("%3d! =", inp);
        for(i=0;i<25;i++)
        {
            if(ans[inp][i]!=0)
            {
                if(i==15)
                    printf("\n      ");
                printf("%3d", ans[inp][i]);
            }
            else
                break;
        }
        putchar('\n');
    }       
    return 0;
}
