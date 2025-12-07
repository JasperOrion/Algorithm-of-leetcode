/*
 * @lc app=leetcode.cn id=82 lang=cpp
 * @lcpr version=30304
 *
 * [82] 删除排序链表中的重复元素 II
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
        ListNode list1(0);
        ListNode list2(101);
        ListNode *p1 = &list1;
        ListNode *p2 = &list2;
        ListNode *p = head;
        while (p) {
            if ((p->next && p->val == p->next->val) || p->val == p2->val) {
                p2->next = p;
                p2 = p2->next;
            } else {
                p1->next = p;
                p1 = p1->next;
            }
            p = p->next;
            p1->next = nullptr;
            p2->next = nullptr;
        }
        return list1.next;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}
// ListNode list(-1);
// ListNode *p = &list;
// ListNode *q = head;
// while (q) {
//     if (q->next && q->val == q->next->val) {
//         // 跳过该重复元素
//         while (q->next && q->val == q->next->val)
//             q = q->next;
//         // 跳过最后一个重复元素
//         q = q->next;
//         if (!q)
//             p->next = q;
//     } else {
//         p->next = q;
//         q = q->next;
//         p = p->next;
//     }
// }
// return list.next;
/*
// @lcpr case=start
// [1,2,3,3,4,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n
// @lcpr case=end

 */
