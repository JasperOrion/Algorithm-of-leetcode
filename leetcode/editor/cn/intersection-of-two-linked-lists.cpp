/*
 * @lc app=leetcode.cn id=160 lang=cpp
 * @lcpr version=30301
 *
 * [160] 相交链表
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return nullptr;
        ListNode *pointerA = headA;
        ListNode *pointerB = headB;
        // 将两个链表进行拼接,如果有交点指针指向相同,否则均指向nullptr;
        while (pointerA != pointerB) {
            // if (!pointerA)
            //     pointerA = headB;
            // else
            //     pointerA = pointerA->next;
            // if (!pointerB)
            //     pointerB = headA;
            // else
            //     pointerB = pointerB->next;
            pointerA = pointerA ? pointerA->next : headB;
            pointerB = pointerB ? pointerB->next : headA;
        }
        return pointerA;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,6,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */
