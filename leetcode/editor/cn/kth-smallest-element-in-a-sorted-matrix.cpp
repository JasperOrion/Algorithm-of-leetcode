/*
 * @lc app=leetcode.cn id=378 lang=cpp
 * @lcpr version=30304
 *
 * [378] 有序矩阵中第 K 小的元素
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
    bool fun(vector<vector<int>> &matrix, int k, int midNum) {
        int i = matrix.size() - 1;
        int j = 0;
        int num = 0;
        while (i >= 0 && j < matrix.size()) {
            if (matrix[i][j] <= midNum) {
                num += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return num >= k;
    }
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int leftNum = matrix[0][0], rightNum = matrix[n - 1][n - 1];
        while (leftNum < rightNum) {
            int mid = leftNum + (rightNum - leftNum) / 2;
            // fun返回num <= k时，说明mid偏小，需要收缩左边界
            if (fun(matrix, k, mid)) {
                rightNum = mid;
            } else {
                leftNum = mid + 1;
            }
        }
        return leftNum;
    }
};
// @lc code=end

int main() {
    Solution solution;
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int num = solution.kthSmallest(matrix, 8);
    std::cout << num;
    // your test code here
}

/*
// @lcpr case=start
// [[1,5,9],[10,11,13],[12,13,15]]\n8\n
// @lcpr case=end

// @lcpr case=start
// [[-5]]\n1\n
// @lcpr case=end

 */
