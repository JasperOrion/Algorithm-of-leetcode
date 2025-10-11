/*
 * @lc app=leetcode.cn id=657 lang=cpp
 * @lcpr version=30203
 *
 * [657] 机器人能否返回原点
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
    bool judgeCircle(string moves) {
        int arr['Z']{0};
        for (char ch : moves) {
            arr[ch]++;
        }
        if (arr['R'] == arr['L'] && arr['U'] == arr['D'])
            return true;
        else
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
// "UD"\n
// @lcpr case=end

// @lcpr case=start
// "LL"\n
// @lcpr case=end

 */
