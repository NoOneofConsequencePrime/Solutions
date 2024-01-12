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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *tmpHead = new ListNode(), *cur = tmpHead;

    int cry = 0;
    while (l1 || l2 || cry) {
        cry += (l1)? l1->val : 0;
        cry += (l2)? l2->val : 0;

        ListNode *newNode = new ListNode(cry%10); cry /= 10;
        cur->next = newNode; cur = newNode;

        l1 = (l1)? l1->next : nullptr;
        l2 = (l2)? l2->next : nullptr;
    }

    ListNode *ret = tmpHead->next;
    delete tmpHead;

    return ret;
}

int main() {

    return 0;
}