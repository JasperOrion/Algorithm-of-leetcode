/*
 * @lc app=leetcode.cn id=81 lang=cpp
 * @lcpr version=30202
 *
 * [81] 搜索旋转排序数组 II
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool search(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                return true;
            }
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
// [2,5,6,0,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,5,6,0,0,1,2]\n3\n
// @lcpr case=end

 */
