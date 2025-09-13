/*
 * @lc app=leetcode.cn id=904 lang=cpp
 * @lcpr version=30203
 *
 * [904] 水果成篮
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int> &fruits) {
        //*求数字种数至多为2的最长子序列,
        int left = 0, len = 0, maxlen = 0;
        unordered_map<int, int> cnt;
        for (int right = 0; right < fruits.size(); right++) {
            cnt[fruits[right]]++;
            while (cnt.size() > 2) {
                // 别忘了在哈希表中删除fruits[left]对应的数,
                // 第一次大意了没有闪😭😭😭
                cnt[fruits[left]]--;
                if (cnt[fruits[left]] == 0)
                    cnt.erase(fruits[left]);

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
    // your test code here
}

/*
// @lcpr case=start
// [1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,1,2,1,1,2,3,3,4]\n
// @lcpr case=end

 */
