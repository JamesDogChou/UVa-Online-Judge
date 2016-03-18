#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define MAX_BUILDING_NUM 100000

struct Building
{
    int west;
    int east;
}building[MAX_BUILDING_NUM];

bool compareBuilding(Building x, Building y)
{
     return (x.west < y.west);
}

int main(void)
{
    int N, i;
    int numPassageways, leftMostRightPos;
    while(scanf("%d", &N)==1)
    {
        if(!N) break;
        for(i=0;i<N;i++)
            scanf("%d %d", &building[i].west, &building[i].east);
        std::sort(building, building + N, compareBuilding); // Sort by buildings' left position
        
        numPassageways = 0;
        leftMostRightPos = 0;
        for(i=0;i<N;i++)
        {
            if(building[i].west >= leftMostRightPos)
            {
                numPassageways++;
                leftMostRightPos = building[i].east;
            }
            else
            {
                if(building[i].east < leftMostRightPos)
                    leftMostRightPos = building[i].east;
            }
        }
        printf("%d\n", numPassageways);
    }
    return 0;
}
