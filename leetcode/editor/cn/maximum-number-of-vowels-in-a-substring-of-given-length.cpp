/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 * @lcpr version=30202
 *
 * [1456] 定长子串中元音的最大数目
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
    int maxVowels(string s, int k) {
        int result = 0, temp = 0;
        int length = s.size();
        for (int i = 0; i < length; ++i) {
            if (f(s[i]))
                ++temp;
            if (i < k - 1)
                continue;
            result = max(result, temp);
            if (result == k)
                break;
            if (f(s[i - k + 1]))
                temp--;
        }
        return result;
    }
    bool f(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "abciiidef"\n3\n
// @lcpr case=end

// @lcpr case=start
// "aeiou"\n2\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n3\n
// @lcpr case=end

// @lcpr case=start
// "rhythms"\n4\n
// @lcpr case=end

// @lcpr case=start
// "tryhard"\n4\n
// @lcpr case=end

 */
