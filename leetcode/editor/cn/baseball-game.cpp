/*
 * @lc app=leetcode.cn id=682 lang=cpp
 * @lcpr version=30203
 *
 * [682] 棒球比赛
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int calPoints(vector<string> &operations) {
        std::vector<int> v;
        for (auto x : operations) {
            int n = v.size();
            if (x == "+") {
                v.push_back(v[n - 1] + v[n - 2]);
            } else if (x == "D") {
                v.push_back(v[n - 1] * 2);
            } else if (x == "C") {
                v.pop_back();
            } else {
                v.push_back(stoi(x));
            }
        }
        return reduce(v.begin(), v.end());
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// ["5","2","C","D","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["5","-2","4","C","D","9","+","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["1"]\n
// @lcpr case=end

 */
