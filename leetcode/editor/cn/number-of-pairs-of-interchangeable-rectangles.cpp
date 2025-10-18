/*
 * @lc app=leetcode.cn id=2001 lang=cpp
 * @lcpr version=30203
 *
 * [2001] 可互换矩形的组数
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>> &rectangles) {
        long long ans = 0;
        unordered_map<double, int> cnt;
        for (vector<int> x : rectangles) {
            ans += cnt[1.0 * x[0] / x[1]];
            cnt[1.0 * x[0] / x[1]]++;
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [[4,8],[3,6],[10,20],[15,30]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,5],[7,8]]\n
// @lcpr case=end

 */
