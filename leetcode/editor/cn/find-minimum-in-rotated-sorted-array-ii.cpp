/*
 * @lc app=leetcode.cn id=154 lang=cpp
 * @lcpr version=30202
 *
 * [154] 寻找旋转排序数组中的最小值 II
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
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else if (nums[mid] < nums[r])
                r = mid;
            else
                r--;
        }
        return nums[l];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,0,1]\n
// @lcpr case=end

 */
