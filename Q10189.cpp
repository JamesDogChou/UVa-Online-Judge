#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 220

char map[MAX_SIZE][MAX_SIZE];

int main(void)
{
    int m, n, i, j;
    int times = 0;
    char garbage;
    while(scanf("%d%d", &m, &n)==2)
    {
        if(!m&&!n)
            break;
        if(times>0)
            putchar('\n'); 
        printf("Field #%d:\n", ++times);
        int ans[MAX_SIZE][MAX_SIZE] = {0};        
        for(i=0;i<m;i++)
            scanf("%s", map[i]);
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)              //(i+1,j+1)
                if(map[i][j]=='*')
                {
                    if(ans[i][j]!=(-1))
                        ans[i][j]++;
                    if(ans[i][j+1]!=(-1))
                        ans[i][j+1]++;
                    if(ans[i][j+2]!=(-1))
                        ans[i][j+2]++;
                    if(ans[i+1][j]!=(-1))
                        ans[i+1][j]++;

                    if(ans[i+1][j+2]!=(-1))
                        ans[i+1][j+2]++;
                    if(ans[i+2][j]!=(-1))
                        ans[i+2][j]++;
                    if(ans[i+2][j+1]!=(-1))
                        ans[i+2][j+1]++;
                    if(ans[i+2][j+2]!=(-1))
                        ans[i+2][j+2]++;
                        
                    ans[i+1][j+1]=(-1);
                }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(ans[i][j]==(-1))
                    putchar('*');
                else
                    printf("%d", ans[i][j]);
            }
            putchar('\n');
        }      
    }
    return 0;
}
