/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 * @lcpr version=30202
 *
 * [1423] 可获得的最大点数
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
    int maxScore(vector<int> &cardPoints, int k) {
        int n = cardPoints.size() - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + n, 0);
        int minSum = sum;
        for (int i = n; i < cardPoints.size(); i++) {
            sum += cardPoints[i] - cardPoints[i - n];
            minSum = std::min(sum, minSum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
        }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,4,5,6,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [9,7,7,9,7,7,9]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,1000,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,79,80,1,1,1,200,1]\n3\n
// @lcpr case=end

 */
