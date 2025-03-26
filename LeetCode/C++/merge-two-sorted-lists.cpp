#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
#include <map>
using namespace std;

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *tmpHead = new ListNode(), *curNode = tmpHead;
    while (list1 || list2) {
        int mi = INT_MAX;
        if (list1 && list2) {
            mi = min(list1->val, list2->val);
            if (list1->val < list2->val) {list1 = list1->next;}
            else {list2 = list2->next;}
        } else if (list1) {
            mi = list1->val;
            list1 = list1->next;
        } else if (list2) {
            mi = list2->val;
            list2 = list2->next;
        }

        ListNode *newNode = new ListNode(mi);
        curNode->next = newNode;
        curNode = newNode;
    }

    ListNode *ret = tmpHead->next;
    delete tmpHead;

    return ret;
}

int main() {

    return 0;
}