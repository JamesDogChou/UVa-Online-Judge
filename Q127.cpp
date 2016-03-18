#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char garbage;
char piles[52][52][2];  // Cards 
int  pcount[52]={0};    // Count of each pile
int  pilet;             // Number of piles

int check();
void moveleft(int a);

int main(void)
{
    int i,j;
    while(scanf("%c",&piles[0][0][0])==1)
    {
        if(piles[0][0][0]=='#')
            break;
        pcount[0]=1;
        pilet=52;
        scanf("%c",&piles[0][0][1]);
        for(i=1;i<52;i++)
        {
            scanf("%c",&garbage);
            scanf("%c",&piles[i][0][0]);
            scanf("%c",&piles[i][0][1]);
            pcount[i]=1;            
        }
        scanf("%c",&garbage);        
        
        while(check()==0) ;
        
        if(pilet==1)
            printf("1 pile remaining:");
        else
            printf("%d piles remaining:",pilet);
        for(i=0;i<pilet;i++)
            printf(" %d",pcount[i]);
        putchar('\n');
    }
    return 0;
}

int check()
{
    int ck=0; // ck=0 means there is no one to match
    int i,j,k;
    for(i=0;i<pilet;i++)
    {
        if(i>2)
        {
            if(piles[i][pcount[i]-1][0]==piles[i-3][pcount[i-3]-1][0] || piles[i][pcount[i]-1][1]==piles[i-3][pcount[i-3]-1][1])
            {
                piles[i-3][pcount[i-3]][0]=piles[i][pcount[i]-1][0];
                piles[i-3][pcount[i-3]][1]=piles[i][pcount[i]-1][1];
                pcount[i-3]++;
                pcount[i]--;
                if(pcount[i]==0)
                    moveleft(i);
                return 0;
            }
            if(piles[i][pcount[i]-1][0]==piles[i-1][pcount[i-1]-1][0] || piles[i][pcount[i]-1][1]==piles[i-1][pcount[i-1]-1][1])
            {
                piles[i-1][pcount[i-1]][0]=piles[i][pcount[i]-1][0];
                piles[i-1][pcount[i-1]][1]=piles[i][pcount[i]-1][1];
                pcount[i-1]++;
                pcount[i]--;
                if(pcount[i]==0)
                    moveleft(i);
                return 0;
            }
        }
        else
        {
            if(piles[i][pcount[i]-1][0]==piles[i-1][pcount[i-1]-1][0] || piles[i][pcount[i]-1][1]==piles[i-1][pcount[i-1]-1][1])
            {
                piles[i-1][pcount[i-1]][0]=piles[i][pcount[i]-1][0];
                piles[i-1][pcount[i-1]][1]=piles[i][pcount[i]-1][1];
                pcount[i-1]++;
                pcount[i]--;
                if(pcount[i]==0)
                    moveleft(i);
                return 0;
            }
        }
    }
    return 1;  
}

void moveleft(int a)
{
    int i,j;
    for(i=a;i<(pilet-1);i++)
    {
        for(j=0;j<pcount[i+1];j++)
        {
            piles[i][j][0]=piles[i+1][j][0];
            piles[i][j][1]=piles[i+1][j][1]; 
        }
        pcount[i]=pcount[i+1];           
    }
    pilet--;
}
