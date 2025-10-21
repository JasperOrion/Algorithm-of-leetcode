/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=30203
 *
 * [121] 买卖股票的最佳时机
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
    int maxProfit(vector<int> &prices) {
        int Max = 0, Min = prices[0];
        for (int p : prices) {
            /**
             * 每天尝试卖出，若结果大于原最大值，更新最大值，否则不变；
             *另外，不断更新左端最小买入值，若右侧存在更大卖出值，则会
             *更新最大值，否则不变
             */
            Max = std::max(Max, p - Min);
            Min = std::min(Min, p);
        }
        return Max;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */
