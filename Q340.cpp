#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1001
int main(void)
{
    int notEndGuess, gameCount = 1;
    int secretCode[MAX_LEN], guess[MAX_LEN];
    int guessBucket[10];  // Record each number's amount of guess code
    int bucket[10];       // Temporary count secret code's left number
    int A, B, N, i, t;
    while(scanf("%d", &N)==1)
    {
        if(!N)
            break;
        
        printf("Game %d:\n", gameCount);
        gameCount++;
        
        int secretBucket[10] = {0};  // Record each number's amount of screct code
        for(i=0;i<N;i++)
        {
            scanf("%d",&secretCode[i]);
            secretBucket[secretCode[i]]++;
        }
        
        while(1)
        {
            for(i=0;i<10;i++)
            {
                bucket[i] = secretBucket[i];
                guessBucket[i] = 0;
            }
            A=0;
            B=0;
            notEndGuess=0;
            for(i=0;i<N;i++)
                {
                    scanf("%d",&guess[i]);
                    if(guess[i]==secretCode[i])
                    {
                        A++;
                        bucket[guess[i]]--;
                    }
                    else
                    {
                        guessBucket[guess[i]]++;
                    }
                    if(guess[i]!=0)
                        notEndGuess=1;
                }       
            if(!notEndGuess)
                break;
            
            for(i=0;i<10;i++)
            {
                if(bucket[i] > guessBucket[i])
                    B += guessBucket[i];
                else
                    B += bucket[i];
            }
            printf("    (%d,%d)\n",A,B);
        }        
    }
    return 0;
}
