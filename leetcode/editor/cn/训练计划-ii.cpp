/*
 * @lc app=leetcode.cn id=LCR 140 lang=cpp
 * @lcpr version=30304
 *
 * [LCR 140] 训练计划 II
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *trainingPlan(ListNode *head, int cnt) {
        ListNode *fast = head;
        for (int i = 0; i < cnt && fast != nullptr; i++) {
            fast = fast->next;
        }
        ListNode *slow = head;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [2,4,7,8]\n1\n
// @lcpr case=end

 */
