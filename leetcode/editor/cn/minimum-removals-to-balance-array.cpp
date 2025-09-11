/*
 * @lc app=leetcode.cn id=3634 lang=cpp
 * @lcpr version=30203
 *
 * [3634] 使数组平衡的最少移除数目
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
    int minRemoval(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, maxlen = 0;
        for (int right = 0; right < nums.size(); right++) {
            while (nums[right] * 1.0 / k > nums[left])
                left++;
            maxlen = std::max(maxlen, right - left + 1);
        }
        return nums.size() - maxlen;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [2,1,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,6,2,9]\n3\n
// @lcpr case=end

// @lcpr case=start
// [4,6]\n2\n
// @lcpr case=end

 */
