/*
 * @lc app=leetcode.cn id=1337 lang=cpp
 * @lcpr version=30202
 *
 * [1337] 矩阵中战斗力最弱的 K 行
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        vector<pair<int, int>> ans;
        for (int i = 0; i < mat.size(); ++i) {
            int sum = std::accumulate(mat[i].begin(), mat[i].end(), 0);
            ans.push_back({i, sum});
        }
        sort(ans.begin(), ans.end(), [](pair<int, int> &a, pair<int, int> &b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });

        // 统计k个索引
        vector<int> cnt;
        for (int i = 0; i < k; i++) {
            cnt.push_back(ans[i].first);
        }
        return cnt;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// \n[[1,1,0,0,0],\n[1,1,1,1,0],\n[1,0,0,0,0],\n[1,1,0,0,0],\n[1,1,1,1,1]]\n3\n
// @lcpr case=end

// @lcpr case=start
// \n[[1,0,0,0],\n[1,1,1,1],\n[1,0,0,0],\n[1,0,0,0]]\n2\n
// @lcpr case=end

 */
