/*
 * @lc app=leetcode.cn id=1523 lang=cpp
 * @lcpr version=30203
 *
 * [1523] 在区间范围内统计奇数数目
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int countOdds(int low, int high) {
        bool S = high % 2 == 0;
        bool T = low % 2 == 0;
        if (S && T)
            return (high - low) / 2;

        else
            return (high - low) / 2 + 1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 8\n10\n
// @lcpr case=end

 */
