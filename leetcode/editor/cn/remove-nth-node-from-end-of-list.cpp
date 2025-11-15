/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30304
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast = head;
        while (n-- > 0 && fast) {
            fast = fast->next;
        }
        ListNode *slow = head;
        if (!fast)
            return slow->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *p = slow->next;
        slow->next = p->next;
        delete p;
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
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */
