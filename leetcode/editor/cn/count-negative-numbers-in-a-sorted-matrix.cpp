/*
 * @lc app=leetcode.cn id=1351 lang=cpp
 * @lcpr version=30202
 *
 * [1351] 统计有序矩阵中的负数
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
    int countNegatives(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            int l = -1, r = n;
            while (l + 1 != r) {
                int mid = l + (r - l) / 2;
                if (grid[i][mid] >= 0)
                    l = mid;
                else
                    r = mid;
            }
            count += (n - r);
        }
        return count;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,2],[1,0]]\n
// @lcpr case=end

 */
