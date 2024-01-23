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

bool cmp(ListNode* a, ListNode* b) {
    return a->val < b->val;
}

void listAdd(ListNode* node, vector<ListNode*> &v) {
    if (!node) {return;}
    v.push_back(node);
    listAdd(node->next, v);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<ListNode*> v;
    for (auto x : lists) {
        listAdd(x, v);
    }
    sort(v.begin(), v.end(), cmp);

    ListNode *tmpHead = new ListNode(), *cur = tmpHead;
    for (auto x : v) {
        cur->next = x;
        cur = cur->next;
    }
    cur->next = nullptr;

    cur = tmpHead->next;
    delete tmpHead;

    return cur;
}

int main() {

    return 0;
}