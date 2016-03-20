#include <stdio.h>

int main(void)
{
    long long n, m;
    while(scanf("%lld", &n)==1)
    {
        m = ((n*n + 2*n - 5) / 2) * 3;
        printf("%lld\n", m);
    }
    return 0;
}
