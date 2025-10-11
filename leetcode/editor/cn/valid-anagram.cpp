/*
 * @lc app=leetcode.cn id=242 lang=cpp
 * @lcpr version=30203
 *
 * [242] 有效的字母异位词
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
    bool isAnagram(string s, string t) {
        int m = s.size(), n = t.size();
        if (m != n)
            return false;
        int arr['z' + 1];
        for (int i = 0; i < m; i++) {
            arr[s[i]]++;
            arr[t[i]]--;
        }
        for (int cur = 'a'; cur <= 'z'; cur++) {
            if (arr[cur] != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "anagram"\n"nagaram"\n
// @lcpr case=end

// @lcpr case=start
// "rat"\n"car"\n
// @lcpr case=end

 */
