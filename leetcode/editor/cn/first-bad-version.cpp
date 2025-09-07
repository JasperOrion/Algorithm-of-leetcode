/*
 * @lc app=leetcode.cn id=278 lang=cpp
 * @lcpr version=30202
 *
 * [278] 第一个错误的版本
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l != r) {
            int m = l + (r - l) / 2;
            if (isBadVersion(m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 5\n4\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */
