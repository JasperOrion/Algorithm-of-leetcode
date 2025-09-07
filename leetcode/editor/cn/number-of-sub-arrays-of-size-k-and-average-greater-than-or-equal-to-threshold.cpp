/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 * @lcpr version=30202
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
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
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        int count = 0;
        int sum = 0;
        int y = threshold * k;
        for (int i = 0; i < k; i++)
            sum += arr[i];
        if (sum >= y)
            count++;
        for (int i = k; i < arr.size(); i++) {
            sum = sum + arr[i] - arr[i - k];
            if (sum >= y)
                count++;
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
// [2,2,2,2,5,5,5,8]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [11,13,17,23,29,31,7,5,2,3]\n3\n5\n
// @lcpr case=end

 */
