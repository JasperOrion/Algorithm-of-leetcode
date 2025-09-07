/*
 * @lc app=leetcode.cn id=744 lang=cpp
 * @lcpr version=30202
 *
 * [744] 寻找比目标字母大的最小字母
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
    char nextGreatestLetter(vector<char> &letters, char target) {
        int l = 0, r = letters.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (letters[mid] <= target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l == letters.size() ? letters[0] : letters[l];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// ['c', 'f'\n'a'\n
// @lcpr case=end

// @lcpr case=start
// ['c','f','j']\n'c'\n
// @lcpr case=end

// @lcpr case=start
// ['x','x','y','y']\n'z'\n
// @lcpr case=end

 */
