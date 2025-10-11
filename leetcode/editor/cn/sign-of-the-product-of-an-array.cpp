/*
 * @lc app=leetcode.cn id=1822 lang=cpp
 * @lcpr version=30203
 *
 * [1822] 数组元素积的符号
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
    int arraySign(vector<int> &nums) {
        int tag = 1;
        for (int num : nums) {
            if (num > 0)
                tag *= 1;
            else if (num < 0)
                tag *= -1;
            else
                return 0;
        }
        return tag;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [-1,-2,-3,-4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,5,0,2,-3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,-1,1,-1]\n
// @lcpr case=end

 */
