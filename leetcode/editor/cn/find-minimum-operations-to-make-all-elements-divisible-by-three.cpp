/*
 * @lc app=leetcode.cn id=3190 lang=cpp
 * @lcpr version=30304
 *
 * [3190] 使所有元素都可以被 3 整除的最少操作数
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
    int minimumOperations(vector<int> &nums) {
        int count = 0;
        for (int num : nums) {
            if (num % 3 != 0)
                count++;
        }
        return count;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    solution.minimumOperations(nums);
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,6,9]\n
// @lcpr case=end

 */
