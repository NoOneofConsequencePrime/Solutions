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

int chkBalanced(TreeNode* root, bool &chk) {
    if (!root || !chk) {return -1;}

    int l = chkBalanced(root->left, chk), r = chkBalanced(root->right, chk);
    if (abs(l-r) > 1) {chk = false;}

    return max(l, r)+1;
}

bool isBalanced(TreeNode* root) {
    bool ret = true;
    chkBalanced(root, ret);

    return ret;
}

int main() {

    return 0;
}