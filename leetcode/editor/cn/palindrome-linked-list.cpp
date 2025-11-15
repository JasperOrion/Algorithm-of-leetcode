/*
 * @lc app=leetcode.cn id=234 lang=cpp
 * @lcpr version=30304
 *
 * [234] 回文链表
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
    // 把其当作二叉树的后序遍历，在回溯时进行比较时间和空间复杂度均为O(n)
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *fast = head->next, *slow = nullptr, *cur = head;
        while (fast) {
            cur->next = slow;
            slow = cur;
            cur = fast;
            fast = fast->next;
        }
        cur->next = slow;
        return cur;
    }
    bool isPalindrome(ListNode *head) {
        if (!head->next)
            return true;
        // 寻找中间结点
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast)
            slow = slow->next;
        // 反转后部分链表
        ListNode *pre = nullptr, *cur = slow, *next = slow->next;
        ListNode *right = reverseList(slow);
        if (!right) {
            return false;
        }
        // 进行遍历判断
        ListNode *left = head;
        while (right && left) {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};

// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

// class Solution {
// public:
//     // 把其当作二叉树的后序遍历，在回溯时进行比较时间和空间复杂度均为O(n)
//     ListNode *left, *right;
//     bool flag = true;
//     void fun(ListNode *right) {
//         if (!right)
//             return;
//         fun(right->next);
//         if (left->val != right->val)
//             flag = false;
//         left = left->next;
//     }
//     bool isPalindrome(ListNode *head) {
//         left = head;
//         fun(head);
//         return flag;
//     }
// };

/*
// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
