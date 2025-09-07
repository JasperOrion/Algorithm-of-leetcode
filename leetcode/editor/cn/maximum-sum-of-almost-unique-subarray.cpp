/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 * @lcpr version=30202
 *
 * [2841] 几乎唯一子数组的最大和
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
    long long maxSum(vector<int> &nums, int m, int k) {
        long long result = 0, sum = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            // 添加进窗口
            sum += nums[i];
            cnt[nums[i]]++;
            int left = i - k + 1;
            if (left < 0)
                continue;
            // 更新答案
            if (cnt.size() >= m)
                result = max(result, sum);
            // 左侧元素离开窗口
            int out = nums[left];
            sum -= out;
            if (--cnt[out] == 0)
                cnt.erase(out);
        }
        return result;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [2,6,7,3,1,7]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [5,9,9,2,4,5,4]\n1\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1,2,1]\n3\n3\n
// @lcpr case=end

 */
