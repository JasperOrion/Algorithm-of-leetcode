/*
 * @lc app=leetcode.cn id=888 lang=cpp
 * @lcpr version=30202
 *
 * [888] 公平的糖果交换
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
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes) {
        int sum1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sum2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int target = (sum1 - sum2) / 2;
        sort(bobSizes.begin(), bobSizes.end());
        for (auto a : aliceSizes) {
            int b = a - target;
            int l = 0, r = bobSizes.size();
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (bobSizes[mid] < b)
                    l = mid + 1;
                else if (bobSizes[mid] > b)
                    r = mid - 1;
                else
                    return {a, b};
            }
        }
        return {};
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,1]\n[2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2]\n[1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,5]\n[2,4]\n
// @lcpr case=end

 */
