/*
 * @lc app=leetcode.cn id=1385 lang=cpp
 * @lcpr version=30202
 *
 * [1385] 两个数组间的距离值
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
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
        int count = 0;
        sort(arr2.begin(), arr2.end());
        for (auto cur : arr1) {
            bool flag = false;
            int l = -1, r = arr2.size();
            while (l + 1 != r) {
                int mid = l + (r - l) / 2;
                if (arr2[mid] < cur - d)
                    l = mid;
                else if (arr2[mid] > cur + d)
                    r = mid;
                else {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                count++;
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
// [4,5,8]\n[10,9,1,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,2,3]\n[-4,-3,6,10,20,30]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1,100,3]\n[-5,-2,10,-3,7]\n6\n
// @lcpr case=end

 */
