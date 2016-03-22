#include<stdio.h>
#include<algorithm>
#define MAX_ASCII 130
using namespace std;

void swap(int &a,int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

struct ASCII
{
    int ascNum;
    int times;
}ascii[MAX_ASCII];

bool compareAscii(ASCII a, ASCII b)
{
    if(a.times < b.times)
    {
        return true;
    }
    else if(a.times > b.times)
    {
        return false;
    }
    else
    {
        if(a.ascNum > b.ascNum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main(void)
{
    int numOfAscii = 0, hit;
    int i, j, firstTime = 1;
    char c;
    while(scanf("%c", &c)==1)
    {
        if(c=='\n'||c=='\r')
        {
            if(!firstTime)
                putchar('\n');
            else
                firstTime = 0;
            
            sort(ascii, ascii + numOfAscii, compareAscii);
            
            for(i=0;i<numOfAscii;i++)
            {
                printf("%d %d\n", ascii[i].ascNum, ascii[i].times);
            }
            numOfAscii = 0;
        }
        else
        {
            hit = 0;
            for(i=0;i<numOfAscii;i++)
                if(ascii[i].ascNum == int(c))
                {
                    ascii[i].times++;
                    hit=1;
                    break;
                }
            if(!hit)
            {
                ascii[numOfAscii].ascNum = c;
                ascii[numOfAscii].times = 1;
                numOfAscii++;
            }
        }
    }
    return 0;
}
