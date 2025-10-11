/*
 * @lc app=leetcode.cn id=13 lang=cpp
 * @lcpr version=30203
 *
 * [13] 罗马数字转整数
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        unordered_map<char, int> pairs = {{'I', 1},   {'V', 5},   {'X', 10},
                                          {'L', 50},  {'C', 100}, {'D', 500},
                                          {'M', 1000}};
        int sum = 0;
        for (int i = 0; i < len - 1; i++) {
            if (pairs[s[i]] >= pairs[s[i + 1]])
                sum += pairs[s[i]];
            else
                sum -= pairs[s[i]];
        }
        sum += pairs[s[len - 1]];
        return sum;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "III"\n
// @lcpr case=end

// @lcpr case=start
// "IV"\n
// @lcpr case=end

// @lcpr case=start
// "IX"\n
// @lcpr case=end

// @lcpr case=start
// "LVIII"\n
// @lcpr case=end

// @lcpr case=start
// "MCMXCIV"\n
// @lcpr case=end

 */
