/*
 * @lc app=leetcode.cn id=1768 lang=cpp
 * @lcpr version=30203
 *
 * [1768] 交替合并字符串
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
    string mergeAlternately(string word1, string word2) {
        int p = 0;
        string s = "";
        while (p < word1.size() && p < word2.size()) {
            s += word1[p];
            s += word2[p];
            p++;
        }
        if (p == word1.size())
            s += word2.substr(p, word2.size());
        else
            s += word1.substr(p, word1.size());
        return s;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "abc"\n"pqr"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"pqrs"\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"pq"\n
// @lcpr case=end

 */
