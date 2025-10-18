/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 * @lcpr version=30203
 *
 * [1512] 好数对的数目
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
    int numIdenticalPairs(vector<int> &nums) {
        int arr[101]{0};
        for (int num : nums) {
            arr[num]++;
        }
        int sum = 0;
        int num = nums.size() - 1;
        for (int i = 1; i <= 100; i++) {
            int temp = arr[i];
            if (temp > 1)
                sum += temp * (temp - 1) / 2;
        }
        return sum;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,1,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
