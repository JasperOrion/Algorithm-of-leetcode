/*
 * @lc app=leetcode.cn id=912 lang=cpp
 * @lcpr version=30202
 *
 * [912] 排序数组
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        int n = nums.size();
        for (int d = n / 2; d > 0; d /= 2) {
            for (int i = d; i < n; i++) {
                int temp = nums[i];
                int j = i;
                while (j >= d && nums[j - d] > temp) {
                    nums[j] = nums[j - d];
                    j -= d;
                }
                nums[j] = temp;
            }
        }
        return nums;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [5,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,1,2,0,0]\n
// @lcpr case=end

 */
