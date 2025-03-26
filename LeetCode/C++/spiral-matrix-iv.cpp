#include <bits/stdc++.h>
using namespace std;

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> ret(m, vector<int>(n));
    int x = 0, y = 0;
    int mx = 0, my = 1;
    pii bx = {1, m-1}, by = {0, n-1};
    ret[0][0] = head->val;
    for (int i = 0; i < n*m; i++) {
        int tmpV = head? head->val : -1;
        ret[x][y] = tmpV;
        if (x >= bx.s && mx == 1) {
            mx = 0; my = -1; bx.s--;
        } else if (x <= bx.f && mx == -1) {
            mx = 0; my = 1; bx.f++;
        } else if (y >= by.s && my == 1) {
            my = 0; mx = 1; by.s--;
        } else if (y <= by.f && my == -1) {
            my = 0; mx = -1; by.f++;
        }
        x += mx; y += my;
        
        if (head) head = head->next;
    }

    return ret;
}

int main() {

    return 0;
}