/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 * @lcpr version=30203
 *
 * [1208] 尽可能使字符串相等
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxlen = 0, left = 0, cost = 0;
        for (int right = 0; right < s.size(); right++) {
            cost += abs(s[right] - t[right]);
            if (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }
            maxlen = std::max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};
// @lc code=end

int main() {
    Solution solution;
    std::string s = "abcd";
    std::string t = "bcdf";
    int maxCost = 3;
    int result = solution.equalSubstring(s, t, maxCost);
    cout << result;
    // your test code here
}

//* 如果正着很难维持窗口，不妨反过来
/**
 * 这里如果按找先前的方式，
 * 下面的if不执行时，maxCost可能>cost,这就会导致错误的维持窗口
 * if (cost < maxCost)
 *     continue;
 * maxlen = std::max(maxlen, right - left + 1);
 * cost -= abs(s[left] - t[left]);
 * left++;
 */

/*
// @lcpr case=start
// "abcd"\n"bcdf"\n3\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"cdef"\n3\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n"acde"\n0\n
// @lcpr case=end

 */
