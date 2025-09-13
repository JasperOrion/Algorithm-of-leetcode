/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 * @lcpr version=30203
 *
 * [2024] 考试的最大困扰度
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
    int maxConsecutiveAnswers(string answerKey, int k) {
        int cnt[2]{}, left = 0, max_len = 0;
        for (int right = 0; right < answerKey.length(); right++) {
            cnt[answerKey[right] >> 1 & 1]++;
            // 这里的cnt[1] > k && cnt[0] > k
            // 统一处理了T和F的情况,只修改T或只修改F
            // 修改T -> F时,总的F>k,这时统计T修改几次即可,
            // 对  F -> T效果相同
            while (cnt[1] > k && cnt[0] > k) {
                cnt[answerKey[left] >> 1 & 1]--;
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
    // your test code here
}

/*
// @lcpr case=start
// "TTFF"\n2\n
// @lcpr case=end

// @lcpr case=start
// "TFFT"\n1\n
// @lcpr case=end

// @lcpr case=start
// "TTFTTFTT"\n1\n
// @lcpr case=end

 */
