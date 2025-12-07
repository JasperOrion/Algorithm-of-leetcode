/*
 * @lc app=leetcode.cn id=3643 lang=cpp
 * @lcpr version=30304
 *
 * [3643] 垂直翻转子矩阵
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
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x,
                                         int y, int k) {
        int top = y, low = y + k - 1;
        for (int left = y; left < y + k; left++) {
            for (int top = x, low = x + k - 1; top < low; top++, low--) {
                std::swap(grid[top][left], grid[low][left]);
            }
        }
        return grid;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]\n1\n0\n3\n
// @lcpr case=end

// @lcpr case=start
// [[3,4,2,3],[2,3,4,2]]\n0\n2\n2\n
// @lcpr case=end

 */
