/*
 * @lc app=leetcode.cn id=1346 lang=cpp
 * @lcpr version=30202
 *
 * [1346] 检查整数及其两倍数是否存在
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
    bool checkIfExist(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int count = 0;
        for (auto cur : arr) {
            int l = -1, r = arr.size();
            while (l + 1 != r) {
                int mid = l + (r - l) / 2;
                if (arr[mid] * 2 == cur && mid != count)
                    return true;
                else if (arr[mid] * 2 < cur)
                    l = mid;
                else
                    r = mid;
            }
            count++;
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [10,2,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [7,1,14,11]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,7,11]\n
// @lcpr case=end

 */
