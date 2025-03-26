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
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

ListNode* simpleMerge(ListNode *a, ListNode *b) {
    ListNode *tmpHead = new ListNode(), *cur = tmpHead;
    while (a && b) {
        if (a->val < b->val) {
            cur->next = a;
            cur = cur->next;
            a = a->next;
        } else {
            cur->next = b;
            cur = cur->next;
            b = b->next;
        }
    }
    if (a) {cur->next = a;}
    else {cur->next = b;}
    
    ListNode *ret = tmpHead->next;
    delete tmpHead;
    return ret;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {return nullptr;}
    for (int i = 1; i < lists.size(); i++) {
        lists[0] = simpleMerge(lists[0], lists[i]);
    }

    return lists[0];
}

int main() {

    return 0;
}