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

bool hasCycle(ListNode *head) {
    if (!head) return false;
    ListNode *a = head, *b = head->next;
    while (a && b) {
        if (a == b) return true;
        a = a->next;
        if (!b->next) break;
        b = b->next->next;
    }

    return false;
}

int main() {

    return 0;
}