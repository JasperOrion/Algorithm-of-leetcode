/*
 * @lc app=leetcode.cn id=88 lang=cpp
 * @lcpr version=30202
 *
 * [88] 合并两个有序数组
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
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (n == 0)
            return;
        if (m == 0)
            nums1 = nums2;
        int count = m + n - 1;
        m--;
        n--;
        while (m >= 0 && n >= 0) {
            if (nums2[n] >= nums1[m]) {
                nums1[count] = nums2[n];
                count--;
                n--;
            } else {
                nums1[count] = nums1[m];
                count--;
                m--;
            }
        }
        if (m < 0) {
            for (int i = 0; i <= n; i++) {
                nums1[i] = nums2[i];
            }
        }
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,3,0,0,0]\n3\n[2,5,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n[]\n0\n
// @lcpr case=end

// @lcpr case=start
// [0]\n0\n[1]\n1\n
// @lcpr case=end

 */
