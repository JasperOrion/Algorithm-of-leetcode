/*
 * @lc app=leetcode.cn id=69 lang=cpp
 * @lcpr version=30202
 *
 * [69] x 的平方根
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
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        int l = 0;
        int r = x / 2 + 1;
        int m;
        while (l + 1 != r) {
            m = l + (r - l) / 2;
            //*这里用除法能防止溢出
            if (m < x / m)
                l = m;
            else if (m > x / m)
                r = m;
            else
                return m;
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
// 4\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */
