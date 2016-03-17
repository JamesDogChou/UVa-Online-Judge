#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int x,y,mapx,mapy,map[55][55];
char direct;
char left(char c)
{
	switch (c)
    {
		case 'N' : return 'W' ;
		case 'S' : return 'E' ;
		case 'E' : return 'N' ;
		case 'W' : return 'S' ;
	}
}
char right(char c)
{
	switch ( c ){
		case 'N' : return 'E' ;
		case 'S' : return 'W' ;
		case 'E' : return 'S' ;
		case 'W' : return 'N' ;
	}
}
int forward(char c)
{
	int xbefore , ybefore ;
	xbefore = x ;
	ybefore = y ;
	switch (c)
    {
		case 'N' : y++ ;
					  break ;
		case 'S' : y-- ;
					  break ;
		case 'E' : x++ ;
					  break ;
		case 'W' : x-- ;
					  break ;
	}
	if( x>mapx || x<0 || y>mapy || y<0 )
    {
		x = xbefore ;
		y = ybefore ;
		if( !map[x][y] )
        {
			map[x][y] = 1 ;
			return 1 ;
		}
	}
	return 0 ;
}
int main(void)
{
	int i , j , lost ;
	char arr[110] ;
	for(i=0;i<55;i++)
		for( j=0 ; j<55 ; j++ )
            map[i][j]=0;
	scanf( "%d %d\n",&mapx,&mapy);
	while(scanf("%d %d %c\n",&x,&y,&direct)==3)
    {
		gets(arr);
		for(i=0,lost=0;i<strlen(arr)&&!lost;i++)
        {
			switch ( arr[i] )
            {
				case 'R': direct = right(direct);break;
				case 'L': direct = left(direct);break;
				case 'F': lost = forward(direct);break;
			}
		}
		printf("%d %d %c",x,y,direct);
		if(lost)
            puts(" LOST");
        else 
        putchar('\n');
	}
	//system("pause");
	return 0;
}
