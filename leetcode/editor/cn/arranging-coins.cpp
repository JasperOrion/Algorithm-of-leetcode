/*
 * @lc app=leetcode.cn id=441 lang=cpp
 * @lcpr version=30202
 *
 * [441] 排列硬币
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
    int arrangeCoins(int n) {
        long long l = 1, r = n;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (mid * (mid + 1) / 2 <= n)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */
