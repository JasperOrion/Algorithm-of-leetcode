/*
 * @lc app=leetcode.cn id=2958 lang=cpp
 * @lcpr version=30203
 *
 * [2958] 最多 K 个重复元素的最长子数组
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubarrayLength(vector<int> &nums, int k) {
        unordered_map<int, int> um;

        int left = 0, max_len = 0;
        for (int right = 0; right < nums.size(); right++) {
            um[nums[right]]++;
            while (um[nums[right]] > k) {
                um[nums[left]]--;
                left++;
            }
            max_len = std::max(max_len, right - left + 1);
        }
        return max_len;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,1,2,3,1,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1,2,1,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5,5,5,5]\n4\n
// @lcpr case=end

 */
