/*
 * @lc app=leetcode.cn id=344 lang=cpp
 * @lcpr version=30304
 *
 * [344] 反转字符串
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
    void reverseString(vector<char> &s) {
        int size = s.size() - 1;
        int left = 0, right = size;
        while (left < right) {
            int temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// ["h","e","l","l","o"]\n
// @lcpr case=end

// @lcpr case=start
// ["H","a","n","n","a","h"]\n
// @lcpr case=end

 */
