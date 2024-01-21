#include <math.h>
#include <string.h>

int longestValidParentheses(char* s) {
    int max = 0;
    int len = strlen(s);
    int str[len + 1];
    int top = -1;
    
    str[++top] = -1;

    for(int i = 0; i < len; i++)
    {
        if(s[i] == '(')
        {
            str[++top] = i;
        }
        else
        {
            --top;
            if(top == -1)
            {
                str[++top] = i;
            }
            else
            {
                max = fmax(max, i - str[top]); 
            }
        }
    }

    return max;
}
