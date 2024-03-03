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
    int getCnt(ListNode *head) {
        int ret = 1;
        while (head) {
            head = head->next;
            ret++;
        }

        return ret;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) {
            delete head;
            
            return nullptr;
        }
        int m = getCnt(head);
        n = m-n;
        if (n == 1) {
            ListNode *ret = head->next;
            delete head;

            return ret;
        } else {
            ListNode *ret = head, *cur = head;
            for (int i = 2; i < n; i++) {
                cur = cur->next;
            }
            ListNode *tmp = cur->next;
            if (!tmp) {
                delete tmp;
            } else {
                cur->next = tmp->next;
                delete tmp;
            }

            return ret;
        }
    }
};

int main() {

    return 0;
}