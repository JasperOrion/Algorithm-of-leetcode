/*
 * @lc app=leetcode.cn id=2302 lang=cpp
 * @lcpr version=30203
 *
 * [2302] 统计得分小于 K 的子数组数目
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
    long long countSubarrays(vector<int> &nums, long long k) {
        int score = 0, left = 0, sum = 0;
        int count = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            score += sum + nums[right] * (right - left);
            while (score >= k) {
                score -= (sum + nums[left] * (right - left));
                sum -= nums[left];
                left++;
            }
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
// [2,1,4,3,5]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n5\n
// @lcpr case=end

 */
