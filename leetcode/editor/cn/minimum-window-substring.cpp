/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30203
 *
 * [76] 最小覆盖子串
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    bool iscovered(int s[], int t[]) {
        for (int i = 'A'; i <= 'Z'; i++) {
            if (s[i] < t[i])
                return false;
        }
        for (int i = 'a'; i <= 'z'; i++) {
            if (s[i] < t[i])
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        int cnt[128];
        int cns[128];
        for (int i : t) {
            cnt[i]++;
        }
        int left = 0;
        int cur_left = -1, cur_right = s.size();
        for (int right = 0; right < s.size(); right++) {
            cns[s[right]]++;
            while (iscovered(cns, cnt)) {
                if (right - left < cur_right - cur_left) {
                    cur_left = left;
                    cur_right = right;
                }
                cns[s[left]]--;
                left++;
            }
        }
        return cur_left < 0 ? "" : s.substr(cur_left, cur_right - cur_left + 1);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */
