#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int length = strlen(s);
    int max = 0;
    int start = 0;
    int arr[256]; 
    for(int i = 0; i < 256; i++)
    {
        arr[i] = -1;
    }
    for (int i = 0; i < length; i++) {
        if (arr[s[i]] >= start) {
            start = arr[s[i]] + 1;
        }
        arr[s[i]] = i;
        int current = i - start + 1;
        if (current > max) {
            max = current;
        }
    }
    return max;
}

int main(void) {
    char s[200];
    scanf("%s", s);
    int num = lengthOfLongestSubstring(s);
    printf("%d\n", num);
}
