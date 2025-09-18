/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30203
 *
 * [209] 长度最小的子数组
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
    int minSubArrayLen(int target, vector<int> &nums) {
        int left = 0, min_len = nums.size() + 1, sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                min_len = std::min(min_len, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return min_len == nums.size() + 1 ? 0 : min_len;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */
