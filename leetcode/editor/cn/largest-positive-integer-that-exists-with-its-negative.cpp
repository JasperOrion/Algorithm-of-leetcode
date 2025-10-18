/*
 * @lc app=leetcode.cn id=2441 lang=cpp
 * @lcpr version=30203
 *
 * [2441] 与对应负数同时存在的最大正整数
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
    int findMaxK(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] * (-1) == nums[right])
                return nums[right];
            else if (nums[left] * (-1) > nums[right])
                left++;
            else
                right--;
        }
        return -1;
    }
};
// @lc code=end

/*
int ans = -1;
unordered_set<int> s;
for (int x: nums) {
    if (s.count(-x))
        ans = max(ans, abs(x));
    s.insert(x);
}
return ans;


*/
int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [-1,2,-3,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,10,6,7,-7,1]\n
// @lcpr case=end

// @lcpr case=start
// [-10,8,6,7,-2,-3]\n
// @lcpr case=end

 */
