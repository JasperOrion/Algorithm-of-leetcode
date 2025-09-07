/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 * @lcpr version=30202
 *
 * [2090] 半径为 k 的子数组平均值
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
    vector<int> getAverages(vector<int> &nums, int k) {
        vector<int> arr(nums.size(), -1);
        long long sum = 0;
        int n = 2 * k + 1;
        if (n > nums.size())
            return arr;
        for (int i = 0; i < k * 2 + 1; i++)
            sum += nums[i];
        arr[k] = sum / n;
        for (int i = k + 1; i < nums.size() - k; i++) {
            sum = sum + nums[i + k] - nums[i - k - 1];
            arr[i] = sum / n;
        }
        return arr;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [7,4,3,9,1,8,5,2,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [100000]\n0\n
// @lcpr case=end

// @lcpr case=start
// [8]\n100000\n
// @lcpr case=end

 */
