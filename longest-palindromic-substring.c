#include <stdio.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int maxlen = 1, first = 0;
    int length = strlen(s);    

    for(int i = 0; i < length; i++)    
    {
        int sum = 1;
        int j = i, k = i;
        while(j >= 0 && k < length)
        {
            if(s[j] != s[k])
                break;
            if(j != k)
                sum += 2;
            j--;
            k++;
        }
        if(maxlen < sum)
        {
            maxlen = sum;
            first = j+1;
        }
    }

    for(int i = 0; i < length; i ++)
    {
        int sum = 0;
        int j = i, k = i+1;
        while(j >= 0 && k < length)
        {
            if(s[j] != s[k])
                break;
            sum += 2;
            j--;
            k++;
        }
        if(maxlen < sum)
        {
            maxlen = sum;
            first = j + 1;
        }
    }

    s[first+maxlen] = '\0';
    char * target = &s[first];

    printf("%s\n",target);

    return target;
}
