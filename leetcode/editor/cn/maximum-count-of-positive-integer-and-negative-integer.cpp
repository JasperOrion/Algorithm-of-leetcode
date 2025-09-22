/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 * @lcpr version=30203
 *
 * [2529] 正整数和负整数的最大计数
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    int fu(vector<int> &nums, int target) {
        int left = -1, right = nums.size();
        while (left + 1 != right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }

public:
    int maximumCount(vector<int> &nums) {
        int start = fu(nums, 0) + 1;
        int end = nums.size() - fu(nums, 1) - 1;
        return start > end ? start : end;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [-2,-1,-1,1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-3,-2,-1,0,0,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,20,66,1314]\n
// @lcpr case=end

 */
