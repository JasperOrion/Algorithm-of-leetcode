/*
 * @lc app=leetcode.cn id=219 lang=cpp
 * @lcpr version=30203
 *
 * [219] 存在重复元素 II
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
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> LastIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (LastIndex.count(nums[i]) && i - LastIndex[nums[i]] <= k)
                return true;
            LastIndex[nums[i]] = i;
        }
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
// [1,2,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,2,3]\n2\n
// @lcpr case=end

 */
