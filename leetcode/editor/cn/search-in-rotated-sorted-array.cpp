/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=30202
 *
 * [33] 搜索旋转排序数组
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
    int search(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[0] <= nums[mid])
                if (nums[0] <= target && target <= nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            else {
                if (nums[mid] < target && target <= nums[nums.size() - 1])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
