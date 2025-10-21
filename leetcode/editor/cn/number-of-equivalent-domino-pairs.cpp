/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 * @lcpr version=30203
 *
 * [1128] 等价多米诺骨牌对的数量
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
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        int arr[10][10];
        int cnt = 0;
        for (auto x : dominoes) {
            // int a, b;
            // if (x[0] <= x[1]) {
            //     a = x[0];
            //     b = x[1];
            // } else {
            //     a = x[1];
            //     b = x[0];
            // }
            auto [a, b] = std::minmax(x[0], x[1]);
            cnt += arr[a][b]++;
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
// [[1,2],[2,1],[3,4],[5,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[1,2],[1,1],[1,2],[2,2]]\n
// @lcpr case=end

 */
