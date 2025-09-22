/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30203
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    int erfen(vector<int> &nums, int target) {
        int left = -1, right = nums.size();
        while (left + 1 != right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int left = erfen(nums, target);
        if (left == nums.size() || nums[left] != target) {
            return {-1, -1};
        }
        int right = erfen(nums, target + 1) - 1;
        return {left, right};
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
