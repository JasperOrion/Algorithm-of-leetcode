/*
 * @lc app=leetcode.cn id=896 lang=cpp
 * @lcpr version=30203
 *
 * [896] 单调数列
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
    bool isMonotonic(vector<int> &nums) {
        int len = nums.size();
        if (len < 2)
            return true;
        int d = nums[len - 1] - nums[0];
        // 标记flag d<0 递减 为false;反之递增 为true;
        bool flag = d >= 0 ? true : false;
        if (flag) {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] - nums[i - 1] < 0)
                    return false;
            }
            return true;
        } else {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] - nums[i - 1] > 0)
                    return false;
            }
            return true;
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [6,5,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2]\n
// @lcpr case=end

 */
