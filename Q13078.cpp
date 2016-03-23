#include<stdio.h>
#define MAX_MAP_SIZE 52
int map[MAX_MAP_SIZE][MAX_MAP_SIZE];

int main(void)
{
    int testCases, iterTestCase;
    int r, c, n;
    int v, h, direction, steps, moves; // direction: N=0, E=1, S=2, W=3
    int i, j, k, l, t;
    bool endDay;
    char tempDirection[2];
    
    scanf("%d", &testCases);
    for(iterTestCase=0;iterTestCase<testCases;iterTestCase++)
    {
        scanf("%d %d %d", &r, &c, &n);
        for(i=0;i<=r;i++)
            for(j=0;j<=c;j++)
                map[i][j] = 0;
        
        for(i=0;i<n;i++)
        {
            scanf("%d %d %s %d", &v, &h, &tempDirection, &steps);
            map[v][h]++;
            endDay = 0;
            switch(tempDirection[0])
            {
                case 'E': h++; direction = 2; break; // next direction is S
                case 'S': v++; direction = 3; break; // next direction is W
                case 'W': h--; direction = 0; break; // next direction is N
                case 'N': v--; direction = 1; break; // next direction is E
            }
            if(v>r || h>c || v<1 || h<1)
                endDay = 1;
            
            for(j=2;(steps>0 && !endDay);j+=2)
            {
                for(k=0;k<4;k++) // 4 directions
                {
                    if(k==0)
                    {
                        moves = j - 1;
                        map[v][h]++;
                        steps--;
                        if(steps==0)
                        {
                            endDay = 1;
                            break;
                        }
                    }
                    else
                        moves = j;
                        
                    switch(direction)
                    {
                        case 0: 
                            for(l=0;l<moves;l++)
                            {
                                v--;
                                if(v<1)
                                {
                                    endDay = 1;
                                    break;
                                }
                                else
                                    map[v][h]++;
                                steps--;
                                if(steps==0)
                                {
                                    endDay = 1;
                                    break;
                                }
                            }
                            break;
                        case 1:
                            for(l=0;l<moves;l++)
                            {
                                h++;
                                if(h>c)
                                {
                                    endDay = 1;
                                    break;
                                }
                                else
                                    map[v][h]++;
                                steps--;
                                if(steps==0)
                                {
                                    endDay = 1;
                                    break;
                                }
                            }
                            break;
                        case 2:
                            for(l=0;l<moves;l++)
                            {
                                v++;
                                if(v>r)
                                {
                                    endDay = 1;
                                    break;
                                }
                                else
                                    map[v][h]++;
                                steps--;
                                if(steps==0)
                                {
                                    endDay = 1;
                                    break;
                                }
                            }
                            break;
                        case 3: 
                            for(l=0;l<moves;l++)
                            {
                                h--;
                                if(h<1)
                                {
                                    endDay = 1;
                                    break;
                                }
                                else
                                    map[v][h]++;
                                steps--;
                                if(steps==0)
                                {
                                    endDay = 1;
                                    break;
                                }
                            }
                            break;
                    }
                    direction = (direction + 1) % 4; // next direction
                    if(endDay)
                        break;
                }
                
                t = (direction + 3) % 4; // last direction
                switch(t)
                {
                    case 1: h++; break;
                    case 2: v++; break;
                    case 3: h--; break;
                    case 0: v--; break;
                }
                if(v>r || h>c || v<1 || h<1)
                    endDay = 1;
                
            }
        }
        
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(j>1)
                    putchar(' ');
                printf("%d", map[i][j]);
            }
            putchar('\n');
        }
        printf("---\n");
    }
    return 0;
}
