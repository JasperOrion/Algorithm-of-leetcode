/*
 * @lc app=leetcode.cn id=2016 lang=cpp
 * @lcpr version=30203
 *
 * [2016] 增量元素之间的最大差值
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
    int maximumDifference(vector<int> &nums) {
        int Max = 0, Min = nums[0];
        for (int p : nums) {
            Max = std::max(Max, p - Min);
            Min = std::min(Min, p);
        }
        return Max == 0 ? -1 : Max;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [7,1,5,4]\n
// @lcpr case=end

// @lcpr case=start
// [9,4,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,5,2,10]\n
// @lcpr case=end

 */
