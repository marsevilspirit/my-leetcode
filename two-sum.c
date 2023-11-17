/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int * array = (int *)malloc(sizeof(int)*2); 
    * returnSize = 2;
    for(int i = 0; i < numsSize; i++)
    {
        for(int 
            if(nums[i] + nums[j] == target)
            {j = i +1; j < numsSize; j++)
        {
                array[0] = i;
                array[1] = j;
            }
        }
    }
    return array;
}
