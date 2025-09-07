/*
 * @lc app=leetcode.cn id=35 lang=cpp
 * @lcpr version=30202
 *
 * [35] 搜索插入位置
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
    int searchInsert(vector<int> &nums, int target) {
        int high = nums.size();
        int low = -1;
        int mid;
        while (low + 1 != high) {
            mid = low + (high - low) / 2;
            if (target > nums[mid]) {
                low = mid;
            } else if (target < nums[mid]) {
                high = mid;
            } else {
                return mid;
            }
        }
        return low + 1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

 */
