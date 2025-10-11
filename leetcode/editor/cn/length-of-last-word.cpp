/*
 * @lc app=leetcode.cn id=58 lang=cpp
 * @lcpr version=30203
 *
 * [58] 最后一个单词的长度
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
    int lengthOfLastWord(string s) {
        int len = s.size();
        bool flag = false;
        int sum = 0;
        for (int i = len - 1; i >= 0; i--) {
            if ('a' <= s[i] && 'z' >= s[i] || 'A' <= s[i] && 'Z' >= s[i]) {
                sum++;
                flag = true;
            }
            if (flag && s[i] == ' ')
                break;
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
// "Hello World"\n
// @lcpr case=end

// @lcpr case=start
// "   fly me   to   the moon  "\n
// @lcpr case=end

// @lcpr case=start
// "luffy is still joyboy"\n
// @lcpr case=end

 */
