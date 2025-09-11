/*
 * @lc app=leetcode.cn id=3652 lang=cpp
 * @lcpr version=30203
 *
 * [3652] 按策略买卖股票的最佳时机
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
    long long maxProfit(vector<int> &prices, vector<int> &strategy, int k) {
        long long total = 0, max_sum = 0, sum = 0;
        for (int i = 0; i < prices.size(); i++) {
            int p = prices[i], s = strategy[i];
            // 原策略所获收益
            total += p * s;
            // 开始进入窗口
            // 这是将刚进入窗口的元素改成策略
            // 1,第一次的窗口还需处理前半部分将其改成 0
            // 1  -> 1 +(1-1)p
            // 0  -> 1 +(1-0)p
            // -1 -> 1 +(1-(-1))p
            sum += p * (1 - s);
            if (i < k - 1) {
                // 这里开始处理前半部分,
                if (i >= k / 2 - 1) {
                    // 1  -> 0  -p
                    // 0  -> 0  -0p
                    // -1 -> 0  -(-1)p
                    sum -= prices[i - k / 2 + 1];
                }
                continue;
            }
            max_sum = std::max(sum, max_sum);
            // 滑动窗口,改变状态的值有三处,其中一处为刚开始的入窗口,另外两个的位置在
            // 例如 0 1 2 3 4 5        i = 5
            // 左半部分的最左侧[i-k+1]     = 0
            // 右半部分的最左侧[i-k/2+1]   = 3
            // 0 ->  1    p     1 -> 0 -p
            // 0 ->  0  -0p
            // 0 -> -1  -1p
            sum -=
                prices[i - k / 2 + 1] - prices[i - k + 1] * strategy[i - k + 1];
        }
        return total + max_sum;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [4,2,8]\n[-1,0,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [5,4,3]\n[1,1,0]\n2\n
// @lcpr case=end

 */
