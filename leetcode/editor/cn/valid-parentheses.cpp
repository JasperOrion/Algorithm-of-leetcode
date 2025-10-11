/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30203
 *
 * [20] 有效的括号
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1)
            return false;
        std::unordered_map<char, char> pairs{
            {')', '('}, {']', '['}, {'}', '{'}};
        std::stack<char> st;
        for (char ch : s) {
            if (pairs.count(ch)) {
                if (st.empty() || st.top() != pairs[ch])
                    return false;
                st.pop();
            } else
                st.push(ch);
        }
        return st.empty();
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

// @lcpr case=start
// "([)]"\n
// @lcpr case=end

 */
