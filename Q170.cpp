#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char top[2] ,test[13][4] ,card[13][4][2] ,ch;
	while(scanf("%c", &ch)==1)
    {
		int num=1, i, j, k;
		if(ch=='#') break;
		for(i=0;i<4;i++)
			for(j=12;j>=0;j--)
				for(k=0;k<2;k++)
                {
					if(!(ch==' ' || ch=='\n'))
                        card[j][i][k] = ch;
					else 
                        k--;
					scanf("%c",&ch);
				}
		for(i=0;i<13;i++)
			for(j=0;j<4;j++)
               test[i][j] = 0;
		top[0] = card[12][0][0];
		top[1] = card[12][0][1];
		test[12][0] = 1;
		while(1)
        {
			int point ,yes=0;
			switch (top[0])
            {
				case 'A': point = 0; break;
				case 'T': point = 9; break;
				case 'J': point = 10; break;
				case 'Q': point = 11; break;
				case 'K': point = 12; break;
				default : point = top[0]-49; break;
			}
			for(i=0;i<4;i++)
    			if(test[point][i]==0)
                {
    				test[point][i] = 1;
    				num++;
    				top[0] = card[point][i][0];
    				top[1] = card[point][i][1];
    				yes = 1;
    				break;
    			}
			if(yes==0) break;
		}
		printf("%02d,%c%c\n", num, top[0], top[1]);
	}
	return 0;
}
