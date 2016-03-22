#include<stdio.h>
#define MAX_STRING_LEN 300
#define TIME_LINE_LEN 480 // 8 hours = 480 minutes
int main(void)
{
    int i, j, d, t = 0;
    char start[6], end[6], ch[300];
    int st, en;
    while(scanf("%d", &d)==1)
    {
        bool sch[TIME_LINE_LEN] = {0};
        for(i=0;i<d;i++)
        {
            scanf("%s",&start);
            scanf("%s",&end);
            gets(ch);
            // ASCII of '0' = 48
            st = int(start[1]) - 48;
            st *= 60;
            st += (int(start[3]) - 48) * 10 + int(start[4]) - 48;
            en = int(end[1]) - 48; 
            en *= 60;
            en += (int(end[3]) - 48) * 10 + int(end[4]) - 48;
            for(j=st;j<en;j++)
                sch[j] = 1;      
        }
        int longest = 0, longStart = 0, currentStart = 0, currentLong = 0;   
        for(i=0;i<480;i++)
        {
            if(sch[i]==0)
            {
                if(currentLong==0)
                    currentStart = i;
                currentLong++;
            }
            else
            {
                if(currentLong > longest)
                {
                    longest = currentLong;
                    longStart = currentStart;
                    currentLong = 0;
                }
                else
                    currentLong = 0;
            }
        }
        if(currentLong > longest)
        {
            longest = currentLong;
            longStart = currentStart;
        }
        if(longStart==0 && longest==0)
            printf("Day #%d: the longest nap starts at 18:00 and will last for 1 minutes.\n", ++t);
        else
        {
            int ansMin, ansHour;
            ansMin = longStart % 60;
            printf("Day #%d: the longest nap starts at %d:%02d and will last for ", ++t, (longStart / 60) + 10, ansMin);
            ansHour = longest / 60;
            ansMin = longest % 60;
            if(ansHour==0)
                printf("%d minutes.\n", ansMin);
            else
                printf("%d hours and %d minutes.\n", ansHour, ansMin);
        }    
    }
    return 0;
}
