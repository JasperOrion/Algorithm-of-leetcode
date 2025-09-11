/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 * @lcpr version=30203
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
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
    int longestSubarray(vector<int> &nums) {
        int s[2]{}, left = 0, maxlen = 0;
        for (int right = 0; right < nums.size(); right++) {
            s[nums[right]]++;
            while (s[0] > 1) {
                s[nums[left]]--;
                left++;
            }
            maxlen = std::max(maxlen, right - left);
        }
        return maxlen;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1,1,0,1,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

 */
