/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 * @lcpr version=30203
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int target = reduce(nums.begin(), nums.end()) - x;
        //* 注意范围,避免不必要的查错和越界,
        if (target < 0)
            return -1;
        int left = 0, max_len = -1, sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum > target) {
                sum -= nums[left];
                left++;
            }
            if (sum == target)
                max_len = std::max(max_len, right - left + 1);
        }
        return max_len < 0 ? -1 : nums.size() - max_len;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,1,4,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5,6,7,8,9]\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,2,20,1,1,3]\n10\n
// @lcpr case=end

 */
