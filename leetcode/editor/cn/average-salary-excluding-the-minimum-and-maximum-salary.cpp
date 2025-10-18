/*
 * @lc app=leetcode.cn id=1491 lang=cpp
 * @lcpr version=30203
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
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
    double average(vector<int> &salary) {
        sort(salary.begin(), salary.end());
        double sum = 0;
        int n = salary.size();
        for (int i = 1; i < n - 1; i++) {
            sum += salary[i];
        }
        return sum /= (n - 2);
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [4000,3000,1000,2000]\n
// @lcpr case=end

// @lcpr case=start
// [1000,2000,3000]\n
// @lcpr case=end

// @lcpr case=start
// [6000,5000,4000,3000,2000,1000]\n
// @lcpr case=end

// @lcpr case=start
// [8000,9000,2000,3000,6000,1000]\n
// @lcpr case=end

 */
