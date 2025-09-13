/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 * @lcpr version=30203
 *
 * [1004] 最大连续1的个数 III
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
    int longestOnes(vector<int> &nums, int k) {
        int num[2]{}, left = 0, maxlen = 0;
        for (int right = 0; right < nums.size(); right++) {
            num[nums[right]]++;
            while (num[0] > k) {
                num[nums[left]]--;
                left++;
            }
            maxlen = std::max(maxlen, right - left + 1);
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
// [1,1,1,0,0,0,1,1,1,1,0]\n2\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]\n3\n
// @lcpr case=end

 */
