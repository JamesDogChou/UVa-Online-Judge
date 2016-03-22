#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{
    long n, s, t, i;
    while(scanf("%ld", &n)==1)
    {
        if(n==(-1))
            break;
        n *= 2;
        s = long(sqrt(n));
        for(i=s;i>=1;i--)
            if(n%i==0)
            {
                t = n / i;
                if((t+i)%2)
                {
                    printf("%ld = %ld + ... + %ld\n", n / 2, (t - i + 1) / 2, (t + i - 1) / 2);
                    break;
                }
            }
    }
    return 0;
}
