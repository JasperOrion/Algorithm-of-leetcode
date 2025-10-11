/*
 * @lc app=leetcode.cn id=389 lang=cpp
 * @lcpr version=30203
 *
 * [389] 找不同
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
    char findTheDifference(string s, string t) {
        int arr['z' + 1]{0};
        int size = s.size();
        char ch;
        for (int i = 0; i < size + 1; i++) {
            arr[s[i]]++;
            arr[t[i]]--;
        }
        for (int i = 'a'; i <= 'z'; i++) {
            if (arr[i] == -1) {
                ch = char(i);
            }
        }
        return ch;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "abcd"\n"abcde"\n
// @lcpr case=end

// @lcpr case=start
// ""\n"y"\n
// @lcpr case=end

 */
