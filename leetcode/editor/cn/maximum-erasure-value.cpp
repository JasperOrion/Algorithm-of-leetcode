/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 * @lcpr version=30203
 *
 * [1695] 删除子数组的最大得分
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumUniqueSubarray(vector<int> &nums) {
        unordered_set<int> us;
        int left = 0, sum = 0, max_sum = 0;
        for (int num : nums) {
            while (us.find(num) != us.end()) {
                us.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            us.insert(num);
            sum += num;
            max_sum = std::max(max_sum, sum);
        }
        return max_sum;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [4,2,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [5,2,1,2,5,2,1,2,5]\n
// @lcpr case=end

 */
