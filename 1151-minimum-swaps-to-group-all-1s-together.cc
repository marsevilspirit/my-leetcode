#include <queue>
#include <vector>
#include <gtest/gtest.h>

class Solution {
public:
    int minSwaps(std::vector<int>& data) {
        int count = 0;
        int max = 0;
        int current = 0;
        for (auto& num : data) {
            if(num == 1) {
                count++;
            }
        }

        std::queue<int> window;

        for(int i = 0; i < count; i++) {
            if(data[i] == 1) {
                current++;
            }
            window.push(data[i]);
        }

        max = current;

        for(int i = count; i <= data.size() - 1; i++) {
            window.pop();
            window.push(data[i]);

            if(data[i-count] == 1) {
                current--;
            }
            if(data[i] == 1) {
                current++;
            }
            if(current > max) {
                max = current;
            }
        } 

        return count - max;
    }
};

TEST(Example1, SimpleTest) {
    Solution solution;
    std::vector<int> data = {1,0,1,0,1};
    EXPECT_EQ(solution.minSwaps(data), 1);
}

TEST(Example2, SimpleTest) {
    Solution solution;
    std::vector<int> data = {0,0,0,1,0};
    EXPECT_EQ(solution.minSwaps(data), 0);
}

TEST(Example3, SimpleTest) {
    Solution solution;
    std::vector<int> data = {1,0,1,0,1,0,0,1,1,0,1};
    EXPECT_EQ(solution.minSwaps(data), 3);
}

TEST(Example4, SimpleTest) {
    Solution solution;
    std::vector<int> data = {1,0,1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1};
    EXPECT_EQ(solution.minSwaps(data), 8);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
