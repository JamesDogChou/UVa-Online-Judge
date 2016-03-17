#include<stdio.h>
int main(void)
{
    int i,j,k,l,yorn;
    int n;
    double start[21][21],now[21][21],newone[21][21];
    int tr[21][21][21],nowtr;
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(i!=j)
                    scanf("%lf",&start[i][j]);
                else
                    start[i][j]=1.0;
                now[i][j]=start[i][j];
            }
        yorn=0;
        for(i=1;i<n;i++)
        {
            for(j=1;j<=n;j++)
                for(k=1;k<=n;k++)
                {
                    newone[j][k]=now[j][1]*start[1][k];
                    nowtr=1;
                    for(l=2;l<=n;l++)
                        if(now[j][l]*start[l][k]>newone[j][k])
                        {
                            newone[j][k]=now[j][l]*start[l][k];
                            nowtr=l;
                        }
                    for(l=1;l<i;l++)
                        tr[l][j][k]=tr[l][j][nowtr];
                    tr[i][j][k]=nowtr;
                }
            for(j=1;j<=n;j++)
            {
                for(k=1;k<=n;k++)
                {
                    if(j==k&&newone[j][k]>1.01)
                    {
                        printf("%d",j);
                        for(l=1;l<=i;l++)
                            printf(" %d",tr[l][j][k]);
                        printf(" %d\n",k);
                        yorn=1;
                        break;
                    }
                    else
                        now[j][k]=newone[j][k];
                }
                if(yorn==1)
                    break;
            }
            if(yorn==1)
                break;
        }
        if(!yorn)
            printf("no arbitrage sequence exists\n");
    }
    return 0;
}
