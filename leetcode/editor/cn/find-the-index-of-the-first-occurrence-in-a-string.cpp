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
    int strStr(string main, string pattern) {
        int n = main.size(), m = pattern.size();
        if (m == 0)
            return 0;
        if (n < m)
            return -1;
        // 构造 pi（前缀函数）
        vector<int> pi(m, 0);
        for (int i = 1, len = 0; i < m; ++i) {
            while (len > 0 && pattern[i] != pattern[len])
                len = pi[len - 1];
            if (pattern[i] == pattern[len])
                pi[i] = ++len;
        }
        // 在主串中匹配
        // len,已匹配的 pattern 长度
        for (int i = 0, len = 0; i < n; ++i) {
            while (len > 0 && main[i] != pattern[len])
                len = pi[len - 1];
            if (main[i] == pattern[len])
                ++len;
            if (len == m)
                return i - m + 1;
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
