/*
 * @lc app=leetcode.cn id=1041 lang=cpp
 * @lcpr version=30203
 *
 * [1041] 困于环中的机器人
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
    bool isRobotBounded(string instructions) {
        int direction = 0;
        // 这是指方向 0 北方--0,东方--1，南方--2，西方--3
        // L:(direction + 3) % 4; L:(direction + 1) % 4;
        int len = instructions.size();
        int x = 0, y = 0;
        vector<vector<int>> arr = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (char ch : instructions) {
            if (ch == 'G') {
                x += arr[direction][0];
                y += arr[direction][1];
            } else if (ch == 'L')
                direction = (direction + 3) % 4;
            else
                direction = (direction + 1) % 4;
        }
        return x == 0 && y == 0 || direction != 0;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "GGLLGG"\n
// @lcpr case=end

// @lcpr case=start
// "GG"\n
// @lcpr case=end

// @lcpr case=start
// "GL"\n
// @lcpr case=end

 */
