/*
 * @lc app=leetcode.cn id=3090 lang=cpp
 * @lcpr version=30203
 *
 * [3090] 每个字符最多出现两次的最长子字符串
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
    int maximumLengthSubstring(string s) {
        int count[26]{}, left = 0, max_len = 0;
        for (int right = 0; right < s.length(); right++) {

            count[s[right] - 'a']++;
            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }
            max_len = std::max(max_len, right - left + 1);
        }
        return max_len;
    }
};
// @lc code=end

int main() {
    Solution solution;
    std::string s = "bcbbbcba";
    int x = solution.maximumLengthSubstring(s);
    std::cout << x;
    return 0;
    // your test code here
}

/*
// @lcpr case=start
// "bcbbbcba"\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

 */
