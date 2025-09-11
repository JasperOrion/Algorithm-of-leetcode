/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 * @lcpr version=30203
 *
 * [1052] 爱生气的书店老板
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
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
        int s[2]{}, max_sum1 = 0;
        int n = customers.size();
        for (int i = 0; i < n; ++i) {
            // 将0和1的数据项分开求和,充当扩展窗口的作用
            // 在扩展窗口时,0时直接加入s[0],1时直接加入s[1],不用多做处理
            s[grumpy[i]] += customers[i];
            // 窗口小于minutes时，扩展窗口
            if (i < minutes - 1)
                continue;
            // 此时窗口长度为minutes
            //  更新现在窗口s[1]中的最大值
            max_sum1 = std::max(max_sum1, s[1]);
            // 处理窗口左侧
            s[1] -= grumpy[i - minutes + 1] ? customers[i - minutes + 1] : 0;
        }
        return max_sum1 + s[0];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,0,1,2,1,1,7,5]\n[0,1,0,1,0,1,0,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[0]\n1\n
// @lcpr case=end

 */
