/*
 * @lc app=leetcode.cn id=1502 lang=cpp
 * @lcpr version=30203
 *
 * [1502] 判断能否形成等差数列
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
    bool canMakeArithmeticProgression(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != d)
                return false;
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [3,5,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4]\n
// @lcpr case=end

 */
