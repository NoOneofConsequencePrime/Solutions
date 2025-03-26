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
    int cntNodes(ListNode *head) {
        int ret = 1;
        while (head) {
            ret++;
            head = head->next;
        }

        return ret;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int n = cntNodes(head);
        n = (n+1)/2-1;
        while (n > 0) {
            head = head->next;
            n--;
        }

        return head;
    }
};