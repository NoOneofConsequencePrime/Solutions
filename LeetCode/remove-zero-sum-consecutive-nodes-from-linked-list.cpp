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
private:
    ListNode* fun(ListNode*& head) {
        if (!head) {return head;}
        int cnt = 0;
        for (ListNode* i = head; i; i = i->next) {
            cnt += i->val;
            if (cnt == 0) {
                ListNode* j = head;
                head = i->next;
                while (j != i) {
                    ListNode* tmp = j->next;
                    j = tmp;
                }

                return fun(head);
            }
        }

        fun(head->next);

        return head;
    }
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        return fun(head);
    }
};