#include <limits.h>

int myAtoi(char * s)
{
    int index=0,tag =0;
    while(s[index]==' ')
        index++;
    if(s[index]=='+'||s[index]=='-')
    {
        if(s[index]=='-')
            tag=1;
        index++;
    }
    double sum =0;
    while(s[index]>='0'&&s[index]<='9')
    {
        sum+=(s[index]-'0');
        if(sum>=INT_MAX&&tag==0)
            return INT_MAX;
        if((0-sum)<=INT_MIN)
            return INT_MIN;
        if(s[index+1]>='0'&&s[index+1]<='9')
            sum*=10;
        index++;
    }
    if(tag==1)
        return (int)(0-sum);
    return (int)sum;
}

