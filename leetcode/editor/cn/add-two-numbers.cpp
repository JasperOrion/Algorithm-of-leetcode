/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30304
 *
 * [2] 两数相加
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p1 = l1, *p2 = l2, *p = dummy;
        int carry = 0;
        while (p1 || p2 || carry > 0) {
            int val = 0;
            if (p1) {
                val += p1->val;
                p1 = p1->next;
            }
            if (p2) {
                val += p2->val;
                p2 = p2->next;
            }
            val += carry;
            carry = val / 10;
            val %= 10;
            p->next = new ListNode(val);
            p = p->next;
        }
        return dummy->next;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}

/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */
