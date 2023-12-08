int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0) 
        return numsSize;
    int fast = 1, slow = 1;
    while (fast < numsSize)
    {
        if(nums[fast] != nums[fast-1]) 
        {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}
