#include <vector>
#include <algorithm>

class Solution {

public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        
        // 创建结果变量
        std::vector<std::vector<int>> result;

        // 排序
        std::sort(nums.begin(), nums.end());

        // 迭代a (最后剩下两个给B，C，且nums[itA]<=0)
        int itA = 0;
        while (itA <= nums.size() - 2 && nums[itA] <= 0) {

            int itB = itA + 1;
            int itC = nums.size() - 1;
            
            // 双指针迭代 B 和 C
            while( itB < itC )
            {

                // 如果满足要求，加入结果，否则调整 itB 和 itC
                if (nums[itA] + nums[itB] + nums[itC] < 0) itB++;
                else if (nums[itA] + nums[itB] + nums[itC] > 0) itC--;
                else if (nums[itA] + nums[itB] + nums[itC] == 0) {
                    result.push_back(std::vector<int>{nums[itA], nums[itB], nums[itC]});
                    itB++;
                    itC--;
                }


                // B，C 去重
                // 相同的数值，B只用除A以外最左边的，C只用最右边的 (itB+1/itC-1和itB++/itC--不要越界)
                while (itB > itA + 1 && itB < nums.size() - 1 && nums[itB - 1] == nums[itB]) itB++;
                while (itC >= 1 && itC < nums.size() - 1 && nums[itC + 1] == nums[itC]) itC--;
                
            }

            // A移动和去重
            // 相同的数值，A只用最左边的
            itA++;
            while (itA >= 1 && itA < nums.size() - 1 && nums[itA - 1] == nums[itA]) itA++;

        }

        // 返回结果变量
        return result;
    }
};
