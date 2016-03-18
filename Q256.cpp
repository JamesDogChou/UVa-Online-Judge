#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, digitNum, checkAns;
	int i, j;
	while(scanf("%d",&n)==1)
    {
        digitNum = 1;
        for(i=0;i<n/2;i++)
            digitNum *= 10;
		for(i=0;i<digitNum;i++)
			for(j=0;j<digitNum;j++)
			{
                checkAns = i*digitNum+j;
				if((i+j)*(i+j)==checkAns)
				{
                    switch(n)
                    {
                        case 2: printf("%02d\n", checkAns); break;
                        case 4: printf("%04d\n", checkAns); break;
                        case 6: printf("%06d\n", checkAns); break;
                        case 8: printf("%08d\n", checkAns); break;
                    }
                }
            }
	}
	return 0;
}
