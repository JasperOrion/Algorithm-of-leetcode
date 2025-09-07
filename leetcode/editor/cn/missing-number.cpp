/*
 * @lc app=leetcode.cn id=268 lang=cpp
 * @lcpr version=30202
 *
 * [268] 丢失的数字
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
    int missingNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int left = -1;
        int right = nums.size();
        while (left + 1 != right) {
            int m = left + (right - left) / 2;
            if (isLeft(nums, m))
                left = m;
            else
                right = m;
        }
        return left + 1;
    }
    bool isLeft(vector<int> &nums, int m) {
        if (m == nums[m])
            return true;
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [3,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [9,6,4,2,3,5,7,0,1]\n
// @lcpr case=end

 */
