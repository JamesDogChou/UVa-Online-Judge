#include <stdio.h>
#include <stdlib.h>
long number, n, top;
int main(void)
{
	while(scanf("%ld",&n)==1)
	{
		printf("TERM %ld IS ",n);
		top = 1;
        number = n;
		while(number > 0)
		{
			number = number - top;
			top++;
		}
		top--;
		n = n - top * (top - 1) / 2;
		if(top%2 == 0)
            printf("%ld/%ld\n", n, top-n+1);
		else
            printf("%ld/%ld\n", top-n+1, n);
	}
	return 0;
}
