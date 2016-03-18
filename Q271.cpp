#include<stdio.h>
#include<string.h>

int main(void)
{
    char s[260];
    int i, c;
    while(scanf("%s", &s)==1)
    {
        int ok = 0;
        for(i=strlen(s)-1,c=0;i>=0;i--)
        {
            switch(s[i])
            {
                case 'p' : 
    			case 'q' :
    			case 'r' : 
    			case 's' : 
    			case 't' : 
    			case 'u' :
    			case 'v' : 
    			case 'w' :
    			case 'x' : 
    			case 'y' : 
    			case 'z' : c++; break;
    			case 'N' : break;
    			case 'C' : 
    			case 'D' : 
    			case 'E' :
    			case 'I' : c--; break;
    			default : printf("NO\n"); ok = 1; break;
		    }
		    if(c<=0 && !ok)
		    {
		        printf("NO\n"); 
                ok = 1; 
                break;
            }
            if(ok==1)
                break;
        }
        if(!ok)
        {
            if(c==1)
                printf("YES\n"); 
            else
                printf("NO\n");
        }
    }
    return 0;
}
