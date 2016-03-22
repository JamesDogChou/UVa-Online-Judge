#include<stdio.h>
#define MAX_LEN 1000
int main(void)
{
    int numOfInput, row, d[MAX_LEN], YorN, test = 0;
    int i, j, a, b;
    scanf("%d", &numOfInput);
    for(i=0;i<numOfInput;i++)
    {
        scanf("%d",&row);
        for(j=0;j<row;j++)
        {
            scanf("%d%d", &a, &b);
            d[j] = a - b;
        }
        YorN = 1;
        for(j=1;j<row;j++)
            if(d[j]!=d[0])
            {
                YorN = 0;
                break;
            }
        if(test!=0)
            putchar('\n');
        test = 1;
        if(YorN==1)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
