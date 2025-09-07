/*
 * @lc app=leetcode.cn id=367 lang=cpp
 * @lcpr version=30202
 *
 * [367] 有效的完全平方数
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
    bool isPerfectSquare(int num) {
        long long l = 1, r = num / 2 + 1;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            if (m * m < num)
                l = m + 1;
            else if (m * m > num)
                r = m - 1;
            else if (m * m == num)
                return true;
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 16\n
// @lcpr case=end

// @lcpr case=start
// 14\n
// @lcpr case=end

 */
