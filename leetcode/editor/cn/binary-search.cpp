/*
 * @lc app=leetcode.cn id=704 lang=cpp
 * @lcpr version=30202
 *
 * [704] 二分查找
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
    int search(vector<int> &nums, int target) {
        // (-1,nums.size())左开右开
        // int l = -1, r = nums.size();
        // while (l + 1 != r) {
        //     int m = l + (r - l) / 2;
        //     if (nums[m] < target)
        //         l = m;
        //     else if (nums[m] > target)
        //         r = m;
        //     else
        //         return m;
        // }
        // return -1;

        //[0,nums.size()) 左闭右开
        // int l = 0, r = nums.size();
        // while (l < r) {
        //     int m = l + (r - l) / 2;
        //     if (nums[m] < target)
        //         l = m + 1;
        //     else if (nums[m] > target)
        //         r = m;
        //     else
        //         return m;
        // }
        // return -1;

        //[0,nums.size()-1] 左闭右闭
        // int l = 0, r = nums.size() - 1;
        // while (l <= r) {
        //     int m = l + (r - l) / 2;
        //     if (nums[m] < target)
        //         l = m + 1;
        //     else if (nums[m] > target)
        //         r = m - 1;
        //     else
        //         return m;
        // }
        // return -1;
        // [0,nums.size()-1] 左闭右闭
        int l = 0, r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= target)
                l = m + 1;
            else
                r = m;
        }
        return (r == 0 || nums[r - 1] != target) ? -1 : r - 1;
        // int l = 0, r = nums.size() - 1;
        // while (l <= r) {
        //     int m = l + (r - l) / 2;
        //     if (nums[m] <= target)
        //         l = m + 1;
        //     else
        //         r = m - 1;
        // }
        // return (r == -1 || nums[r] != target) ? -1 : r;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [-1,0,3,5,9,12]\n9\n
// @lcpr case=end

// @lcpr case=start
// [-1,0,3,5,9,12]\n2\n
// @lcpr case=end

 */
