#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_DIS 65535
int tr[101][101][101], longoftr[101][101];

int main(void)
{
    char nowchs[55], ch1[22], ch2[22], ch3[11];
    char Route[101][101][11], City[101][22];
    long dis[101][101], diss, newdis[101][101];
    int key, firstend=0, secondend=0, citya, cityb;
    int numofcity=0;
    int i, j, k, l, m;
    
    for(i=0;i<101;i++)
       for(j=0;j<101;j++)
           newdis[i][j] = dis[i][j] = MAX_DIS;
    while(1)
    {
        key = 0;
        while(1)
        {
            scanf("%c", &nowchs[key]);
            if(nowchs[key]=='\n')
            {
                firstend = 1;
                break;
            }
            if(nowchs[key]==',')
            {
                nowchs[key] = '\0';
                strcpy(ch1, nowchs);
                break;
            }
            else
                key++;
        }
        if(firstend==1)
            break;
        key=0;
        while(1)
        {
            scanf("%c", &nowchs[key]);
            if(nowchs[key]==',')
            {
                nowchs[key] = '\0';
                strcpy(ch2, nowchs);
                break;
            }
            else
                key++;
        }
        key = 0;
        while(1)
        {
            scanf("%c", &nowchs[key]);
            if(nowchs[key]==',')
            {
                nowchs[key] = '\0';
                strcpy(ch3, nowchs);
                break;
            }
            else
                key++;
        }
        scanf("%ld", &diss);
        scanf("%c", &nowchs[0]);
        citya=(-1);
        for(i=0;i<numofcity;i++)
            if(strcmp(ch1, City[i])==0)
            {
                citya = i;
                break;
            }
        if(citya==(-1))
        {
            strcpy(City[numofcity], ch1);
            citya = numofcity;
            numofcity++;
        }
        cityb = (-1);
        for(i=0;i<numofcity;i++)
            if(strcmp(ch2, City[i])==0)
            {
                cityb = i;
                break;
            }
        if(cityb==(-1))
        {
            strcpy(City[numofcity], ch2);
            cityb = numofcity;
            numofcity++;
        }
        
        if(dis[citya][cityb]==MAX_DIS || dis[citya][cityb]>diss)
        {
            dis[citya][cityb] = diss;
            dis[cityb][citya] = diss;
            newdis[citya][cityb] = diss;
            newdis[cityb][citya] = diss;
            strcpy(Route[citya][cityb], ch3);
            strcpy(Route[cityb][citya],ch3);
        }
                
    }
    
    for(i=0;i<numofcity;i++)
        for(j=0;j<numofcity;j++)
        {
            tr[i][j][0] = i;
            tr[i][j][1] = j;
            longoftr[i][j] = 2;
        }
    
    for(k=0;k<numofcity;k++)
        for(i=0;i<numofcity;i++)
            for(j=0;j<numofcity;j++)
                if(newdis[i][k]+newdis[k][j] < newdis[i][j])
                {
                    newdis[i][j] = newdis[i][k] + newdis[k][j];
                    for(l=0;l<longoftr[i][k];l++)
                        tr[i][j][l] = tr[i][k][l];
                    for(l=longoftr[i][k],m=1;m<longoftr[k][j];l++,m++)
                        tr[i][j][l] = tr[k][j][m];
                    longoftr[i][j] = longoftr[i][k] + longoftr[k][j] - 1;
                }
    
    secondend = 0;
    int iseof, keyofinputline=0;
    char inputline[100];
    while(fgets(inputline, 100, stdin))
    {
        keyofinputline=0;
        while(inputline[keyofinputline]!=',')
        {
            ch1[keyofinputline] = inputline[keyofinputline];
            keyofinputline++;
        }
        ch1[keyofinputline] = '\0';
        keyofinputline++;
        key = 0;
        while(inputline[keyofinputline]!='\n' && inputline[keyofinputline]!='\r')
        {
            ch2[key] = inputline[keyofinputline];
            keyofinputline++;
            key++;
        }
        ch2[key] = '\0';
        for(i=0;i<numofcity;i++)
            if(strcmp(ch1, City[i])==0)
            {
                citya = i;
                break;
            }
        for(i=0;i<numofcity;i++)
            if(strcmp(ch2, City[i])==0)
            {
                cityb = i;
                break;
            }
            
        printf("\n\n");
        printf("From                 To                   Route      Miles\n");
        printf("-------------------- -------------------- ---------- -----\n");
        for(i=0;i<longoftr[citya][cityb]-1;i++)
        {
            printf("%s", City[tr[citya][cityb][i]]);
            for(j=21-strlen(City[tr[citya][cityb][i]]);j>0;j--)
                putchar(' ');
            printf("%s", City[tr[citya][cityb][i+1]]);
            for(j=21-strlen(City[tr[citya][cityb][i+1]]);j>0;j--)
                putchar(' ');
            printf("%s", Route[tr[citya][cityb][i]][tr[citya][cityb][i+1]]);
            for(j=11-strlen(Route[tr[citya][cityb][i]][tr[citya][cityb][i+1]]);j>0;j--)
                putchar(' ');
            printf("%5d\n", dis[tr[citya][cityb][i]][tr[citya][cityb][i+1]]);
        }     
        printf("                                                     -----\n");
        printf("                                          Total      ");
        printf("%5d\n", newdis[citya][cityb]);
        
    }
    return 0;
}
