#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KEY_NUM_MAX 100

int main(void)
{
    int keyPitch[7] = {0, 2, 4, 5, 7, 9, 11};
    char tempStr[6];
    int inputKeyNum, lenTempStr, octave, pitch, keyValue, currMin, currMax;
    int i;
    while(scanf("%d", &inputKeyNum) == 1)
    {
        int timePressed[KEY_NUM_MAX] = {0};
        currMin = KEY_NUM_MAX;
        currMax = 0;
        if(inputKeyNum == 0) break;
        for(i=0;i<inputKeyNum;i++)
        {
            scanf("%s", &tempStr);
            lenTempStr = strlen(tempStr);
            octave = int(tempStr[lenTempStr - 1]) - int('0');
            if(tempStr[lenTempStr - 2] == '#')
                pitch = 1;
            else if(tempStr[lenTempStr - 2] == 'b')
                pitch = (-1);
            else
                pitch = 0;
            switch(tempStr[0])
            {
                case 'D': keyValue = octave * 12 + 0 + pitch; break; // Do
                case 'R': keyValue = octave * 12 + 2 + pitch; break; // Re
                case 'M': keyValue = octave * 12 + 4 + pitch; break; // Mi
                case 'F': keyValue = octave * 12 + 5 + pitch; break; // Fa
                case 'L': keyValue = octave * 12 + 9 + pitch; break; // La
                case 'S': 
                     if(tempStr[1] == 'o')
                     {
                         keyValue = octave * 12 + 7 + pitch; break; // Sol
                     }
                     else
                     {
                         keyValue = octave * 12 + 11 + pitch; break; // Si
                     }
            }
            timePressed[keyValue]++;
            if(keyValue < currMin)
                currMin = keyValue;
            if(keyValue > currMax)
                currMax = keyValue;
        }
        for(i=currMin;i<=currMax;i++)
        {
            if(i==currMin)
                printf("%d", timePressed[i]);
            else
                printf(" %d", timePressed[i]);
        }
        putchar('\n');
    }
    return 0;
}
