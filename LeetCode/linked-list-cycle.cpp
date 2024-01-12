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

unordered_set<ListNode*> st;

bool hasCycle(ListNode *head) {
    while (head) {
        if (st.count(head) != 0) return true;
        st.insert(head);
        head = head->next;
    }

    return false;
}

int main() {

    return 0;
}