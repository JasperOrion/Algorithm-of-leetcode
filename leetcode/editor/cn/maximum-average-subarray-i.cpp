/*
 * @lc app=leetcode.cn id=643 lang=cpp
 * @lcpr version=30202
 *
 * [643] 子数组最大平均数 I
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
    double findMaxAverage(vector<int> &nums, int k) {
        int l = 0, r = k - 1;
        double temp = 0, result = 0;
        for (int i = 0; i < k; i++) {
            temp += nums[i];
        }
        result = temp;
        while (r < nums.size() - 1) {
            temp = temp - nums[l++] + nums[++r];
            result = max(temp, result);
        }
        return result / k;
    };
};

// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,12,-5,-6,50,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n
// @lcpr case=end

 */
