/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 * @lcpr version=30203
 *
 * [1234] 替换子串得到平衡字符串
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
    int balancedString(string s) {
        int cnt['X']{};
        for (char str : s)
            cnt[str]++;
        int n = s.size(), m = n / 4;
        int left = 0, min_len = n;
        if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m)
            return 0;
        for (int right = 0; right < s.size(); right++) {
            cnt[s[right]]--;
            while (cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m &&
                   cnt['R'] <= m) {
                min_len = std::min(min_len, right - left + 1);
                cnt[s[left]]++;
                left++;
            }
        }
        return min_len;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "QWER"\n
// @lcpr case=end

// @lcpr case=start
// "QQWE"\n
// @lcpr case=end

// @lcpr case=start
// "QQQW"\n
// @lcpr case=end

// @lcpr case=start
// "QQQQ"\n
// @lcpr case=end

 */
