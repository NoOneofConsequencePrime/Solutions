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

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* ret = head;
    while (head) {
        while (head->next && head->val==head->next->val) {
            ListNode* tmp = head->next;
            head->next = tmp->next;
            delete tmp;
        }
        head = head->next;
    }

    return ret;
}

int main() {

    return 0;
}