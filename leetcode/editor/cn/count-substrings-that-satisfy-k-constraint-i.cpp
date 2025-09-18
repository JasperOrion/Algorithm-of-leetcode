/*
 * @lc app=leetcode.cn id=3258 lang=cpp
 * @lcpr version=30203
 *
 * [3258] 统计满足 K 约束的子字符串数量 I
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
    int countKConstraintSubstrings(string s, int k) {
        int arr[2]{}, left = 0;
        int count = 0;
        for (int right = 0; right < s.size(); right++) {
            arr[s[right] - '0']++;
            while (arr[0] > k && arr[1] > k) {
                arr[s[left] - '0']--;
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// "10101"\n1\n
// @lcpr case=end

// @lcpr case=start
// "1010101"\n2\n
// @lcpr case=end

// @lcpr case=start
// "11111"\n1\n
// @lcpr case=end

 */
