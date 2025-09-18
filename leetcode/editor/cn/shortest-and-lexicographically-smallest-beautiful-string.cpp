/*
 * @lc app=leetcode.cn id=2904 lang=cpp
 * @lcpr version=30203
 *
 * [2904] 最短且字典序最小的美丽子字符串
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
    string shortestBeautifulSubstring(string s, int k) {
        int count = 0, left = 0, min_len = s.size() + 1;
        std::string result = "";
        for (int right = 0; right < s.size(); right++) {
            count += s[right] - '0';
            while (count > k || s[left] == '0') {
                count -= s[left] - '0';
                left++;
            }
            if (count == k) {
                int cur_len = right - left + 1;
                std::string cur = s.substr(left, cur_len);
                // 这里需要保证其字典序最小
                if (cur_len < min_len || (cur_len == min_len && cur < result)) {
                    min_len = cur_len;
                    result = cur;
                }
            }
        }
        return result;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "100011001"\n3\n
// @lcpr case=end

// @lcpr case=start
// "1011"\n2\n
// @lcpr case=end

// @lcpr case=start
// "000"\n1\n
// @lcpr case=end

 */
