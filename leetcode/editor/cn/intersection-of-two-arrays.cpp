/*
 * @lc app=leetcode.cn id=349 lang=cpp
 * @lcpr version=30202
 *
 * [349] 两个数组的交集
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // 排序，然后两个指针进行遍历，
    // nums1[p1]==nums2[p2]相同且新数组中不存在，加入到新数组中,同时移动指针;
    // 若不等,移动小的那个指针,直至相等
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> v;
        int length1 = nums1.size();
        int length2 = nums2.size();
        int p1 = 0, p2 = 0;
        int num1, num2;
        while (p1 < length1 && p2 < length2) {
            num1 = nums1[p1];
            num2 = nums2[p2];
            if (num1 == num2) {
                if (!v.size() || num1 != v.back())
                    v.push_back(num1);
                ++p1;
                ++p2;
            } else if (num1 < num2)
                ++p1;
            else
                ++p2;
        }
        return v;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> v;
    v = solution.intersection(nums1, nums2);
    for (auto i : v)
        cout << i << " ";
    return 0;
}

/*
// @lcpr case=start
// [1,2,2,1]\n[2,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,5]\n[9,4,9,8,4]\n
// @lcpr case=end

 */
