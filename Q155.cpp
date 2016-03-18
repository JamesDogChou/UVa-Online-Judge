#include<stdio.h>
#include<stdlib.h>
int total, cox, coy;
void recursive(int k, int cenx, int ceny)
{
	if(!k)
        return ;
	else
    {
		if(cenx-k<=cox && cox<=cenx+k && ceny-k<=coy && coy<=ceny+k)
            total++;
		recursive(k/2, cenx-k, ceny-k);
		recursive(k/2, cenx-k, ceny+k);
		recursive(k/2, cenx+k, ceny-k);
		recursive(k/2, cenx+k, ceny+k);
	}
}
int main(void)
{
	int k, cenx, ceny;
	while(scanf("%d %d %d",&k,&cox,&coy) == 3)
    {
		if(!k && !cox && !coy) break;
		total = 0;
		cenx = ceny = 1024;
		if(cenx-k<=cox && cox<=cenx+k && ceny-k<=coy && coy<=ceny+k)
            total++;
		recursive(k/2, cenx-k, ceny-k);
		recursive(k/2, cenx-k, ceny+k);
		recursive(k/2, cenx+k, ceny-k);
		recursive(k/2, cenx+k, ceny+k);
		printf("%3d\n",total);
	}
	return 0;
}
