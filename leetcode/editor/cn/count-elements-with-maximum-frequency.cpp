/*
 * @lc app=leetcode.cn id=3005 lang=cpp
 * @lcpr version=30203
 *
 * [3005] 最大频率元素计数
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
    int maxFrequencyElements(vector<int> &nums) {
        vector<int> arr(1100);
        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]]++;
        }
        sort(arr.begin(), arr.end(), greater<int>());
        int sum = 0;
        int max = arr[0];
        int i = 0;
        while (arr[i] == max) {
            sum += arr[i];
            i++;
        }
        return sum;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<int> nums1{81, 81, 81, 81, 81, 81, 81, 17, 28,  81, 81, 56,
                      81, 54, 81, 81, 81, 81, 81, 60, 81,  28, 81, 81,
                      81, 81, 81, 54, 81, 81, 81, 81, 100, 28};
    cout << solution.maxFrequencyElements(nums1);
    return 0;
    // your test code here
}

/*
// @lcpr case=start
// [1,2,2,3,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */
