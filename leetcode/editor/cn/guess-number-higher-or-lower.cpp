/*
 * @lc app=leetcode.cn id=374 lang=cpp
 * @lcpr version=30202
 *
 * [374] 猜数字大小
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        int index;
        while (l <= n) {
            int m = l + (r - l) / 2;
            if (guess(m) == -1)
                r = m - 1;
            else if (guess(m) == 1)
                l = m + 1;
            else if (guess(m) == 0)
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
// 10\n6\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

// @lcpr case=start
// 2\n1\n
// @lcpr case=end

 */
