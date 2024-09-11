#include <iostream>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    int i = 0;
    for (int num : nums) {
      if (i < 2 || num > nums[i - 2]) {
        nums[i++] = num;
      }
    }

    return i;
  }
};

int main() {
  Solution solution;
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};
  int result = solution.removeDuplicates(nums);

  std::cout << "Result: " << result << std::endl;
  for (int i = 0; i < result; i++) {
    std::cout << nums[i] << " ";
  }

  return 0;
}
