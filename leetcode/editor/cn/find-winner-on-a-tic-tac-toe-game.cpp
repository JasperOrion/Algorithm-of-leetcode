/*
 * @lc app=leetcode.cn id=1275 lang=cpp
 * @lcpr version=30203
 *
 * [1275] 找出井字棋的获胜者
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
    string tictactoe(vector<vector<int>> &moves) {
        char grid[3][3]{'Z'};
        int len = moves.size();
        for (int i = 0; i < len; i++) {
            if (i % 2 == 0) {
                grid[moves[i][0]][moves[i][1]] = 'X';
            } else {
                grid[moves[i][0]][moves[i][1]] = 'O';
            }
        }
        // 检查行和列
        for (int i = 0; i < 3; ++i) {
            if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
                if (grid[i][0] == 'X')
                    return "A";
                else if (grid[i][0] == 'O')
                    return "B";
            }
            if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
                if (grid[0][i] == 'X')
                    return "A";
                else if (grid[0][i] == 'O')
                    return "B";
            }
        }

        // 检查两条对角线
        if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
            if (grid[1][1] == 'X')
                return "A";
            else if (grid[1][1] == 'O')
                return "B";
        }

        if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
            if (grid[1][1] == 'X')
                return "A";
            else if (grid[1][1] == 'O')
                return "B";
        }

        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[0,0],[2,0],[1,1],[2,1],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]\n
// @lcpr case=end

 */
