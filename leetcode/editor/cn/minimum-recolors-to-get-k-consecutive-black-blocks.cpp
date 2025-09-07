/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 * @lcpr version=30202
 *
 * [2379] 得到 K 个黑块的最少涂色次数
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
    int minimumRecolors(string blocks, int k) {
        int min = k;
        int temp = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W')
                temp++;
        }
        min = min < temp ? min : temp;
        for (int i = k; i < blocks.size(); i++) {
            if (min == 0)
                return 0;
            if (blocks[i] == 'W')
                temp++;
            if (blocks[i - k] == 'W')
                temp--;
            min = min < temp ? min : temp;
        }
        return min;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "WBBWWBBWBW"\n7\n
// @lcpr case=end

// @lcpr case=start
// "WBWBBBW"\n2\n
// @lcpr case=end

 */
