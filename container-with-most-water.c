#include <stdlib.h>

int maxArea(int* height, int heightSize) {
    int max = -1;
    
    for(int i = 0; i < heightSize; i++)
    {
        for(int j = i + 1; j < heightSize; j++)
        {
            int num = (height[i] > height[j]) ? height[j] : height[i];
            int S = num * (j - i); 
            if(max < S)
                max = S;
        }
    }

    return max;
}
