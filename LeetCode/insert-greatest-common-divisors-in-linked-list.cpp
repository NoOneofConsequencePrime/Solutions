#include <bits/stdc++.h>
using namespace std;

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

ll modPow(ll b, ll e, ll m) {
    ll ret = 1;
    while (e > 0) {
        if ((e&1ll) == 1) {ret = (ret*b)%m;}
        e >>= 1;
        b = (b*b)%m;
    }

    return ret;
}

ll gcd(ll a, ll b) {
    return b==0? a:gcd(b, a%b);
}

ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode *ret = new ListNode(), *cur = ret;
    cur->val = head->val;
    while (head->next) {
        cur->next = new ListNode(gcd(head->val, head->next->val));
        cur = cur->next;
        cur->next = new ListNode(head->next->val);
        cur = cur->next; head = head->next;
    }

    return ret;
}

int main() {
    cout << modPow(2, 5, 76);

    return 0;
}