#include <string>
#include <iostream>

class Solution {
public:
    int countSubstrings(std::string s) {
        int result = 0;

        for (int i = 0; i <= s.size() - 1; i++) {
            for (int j = 0; i - j >= 0 && i + j <= s.size() - 1; j++) {
                if (s[i - j] == s[i + j]) {
                    result++;
                } else {
                    break; 
                }
            }

            for (int j = 0; i - j >= 0 && i + j + 1 <= s.size() - 1; j++) {
                if (s[i - j] == s[i + j + 1]) {
                    result++;
                } else {
                    break; 
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    std::string s = "pdpebie";
    int result = solution.countSubstrings(s);
    std::cout << result << std::endl;
    return 0;
}
