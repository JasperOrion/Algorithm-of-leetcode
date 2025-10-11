/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30203
 *
 * [28] 找出字符串中第一个匹配项的下标
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
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        //*byd越界
        for (int i = 0; i <= m - n; i++) {
            int p1 = i;
            int p2 = 0;
            while (haystack[p1] == needle[p2] && p2 < n) {
                p1++;
                p2++;
            }
            if (p2 == n)
                return i;
        }
        return -1;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */
