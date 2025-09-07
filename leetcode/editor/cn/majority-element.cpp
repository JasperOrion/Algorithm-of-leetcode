/*
 * @lc app=leetcode.cn id=169 lang=cpp
 * @lcpr version=30202
 *
 * [169] 多数元素
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
    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= pivot)
                right--;
            if (left < right)
                nums[left] = nums[right];
            while (left < right && nums[left] < pivot)
                left++;
            if (left < right)
                nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }

    void quickSort(vector<int> &nums, int left, int right) {
        if (left < right) {
            int pivot = partition(nums, left, right);
            quickSort(nums, left, pivot - 1);
            quickSort(nums, pivot + 1, right);
        }
    }

    vector<int> QuickSort(vector<int> &nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    int majorityElement(vector<int> &nums) {

        QuickSort(nums);
        return nums[nums.size() / 2];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,1,1,2,2]\n
// @lcpr case=end

 */
