/*
 * @lc app=leetcode.cn id=445 lang=cpp
 * @lcpr version=30304
 *
 * [445] 两数相加 II
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include <iostream>
#include <stack>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        std::stack<int> s1, s2;
        ListNode *p1 = l1, *p2 = l2;
        while (p1 || p2) {
            if (p1) {
                s1.push(p1->val);
                p1 = p1->next;
            }
            if (p2) {
                s2.push(p2->val);
                p2 = p2->next;
            }
        }
        int carry = 0;
        ListNode *head = nullptr;
        while (!s1.empty() || !s2.empty() || carry > 0) {
            int val = carry;
            if (!s1.empty()) {
                val += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                val += s2.top();
                s2.pop();
            }
            carry = val / 10;
            val %= 10;
            ListNode *p = new ListNode(val);
            p->next = head;
            head = p;
        }
        return head;
    }
};
// @lc code=end

int main() {
    Solution solution;

    // 创建测试链表 [7,2,4,3]
    ListNode *l1 =
        new ListNode(7, new ListNode(2, new ListNode(4, new ListNode(3))));
    // 创建测试链表 [5,6,4]
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    // 调用 addTwoNumbers
    ListNode *result = solution.addTwoNumbers(l1, l2);

    // 输出结果链表
    while (result) {
        cout << result->val;
        if (result->next)
            cout << " -> ";
        result = result->next;
    }
    cout << endl;

    // 释放内存
    while (l1) {
        ListNode *temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2) {
        ListNode *temp = l2;
        l2 = l2->next;
        delete temp;
    }
    return 0;
}
