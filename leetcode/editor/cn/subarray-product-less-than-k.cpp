/*
 * @lc app=leetcode.cn id=713 lang=cpp
 * @lcpr version=30203
 *
 * [713] 乘积小于 K 的子数组
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
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int count = 0, left = 0, temp;
        int ji = 1;
        if (k <= 1)
            return 0;
        for (int right = 0; right < nums.size(); right++) {
            ji *= nums[right];
            while (ji >= k) {
                ji /= nums[left];
                left++;
            }
            // 唯一真神
            // 直接找满足条件的最长子数组[left,right]，
            // 固定right,所有的子数组也均满足条件
            count += right - left + 1;
        }
        return count;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [10,5,2,6]\n100\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n0\n
// @lcpr case=end

 */
