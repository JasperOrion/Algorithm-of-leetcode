/*
 * @lc app=leetcode.cn id=83 lang=cpp
 * @lcpr version=30304
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *left = head, *right = head->next;
        while (right) {
            if (right->val == left->val) {
                right = right->next;
                continue;
            }
            while (left->next != right) {
                ListNode *temp = left->next;
                left->next = temp->next;
                delete temp;
            }
            left = right;
            right = right->next;
        }
        while (left->next != right) {
            ListNode *temp = left->next;
            left->next = temp->next;
            delete temp;
        }
        return head;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3,3]\n
// @lcpr case=end

 */
