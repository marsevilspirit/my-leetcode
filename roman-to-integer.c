#include <string.h>
int romanToInt(char* s) {
    int switchroman[26];
    switchroman['I' - 'A'] = 1;
    switchroman['V' - 'A'] = 5;
    switchroman['X' - 'A'] = 10;
    switchroman['L' - 'A'] = 50;
    switchroman['C' - 'A'] = 100;
    switchroman['D' - 'A'] = 500;
    switchroman['M' - 'A'] = 1000;
    int sum = 0; 
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        if(i < len - 1 && switchroman[s[i] - 'A'] < switchroman[s[i+1] - 'A'])
        {
            sum -= switchroman[s[i] - 'A'];
        }
        else 
        {
            sum += switchroman[s[i] - 'A'];
        }
    }
    return sum;
}
