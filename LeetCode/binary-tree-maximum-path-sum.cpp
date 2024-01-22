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

int ans = INT_MIN;

int getMx(TreeNode* root) {
    if (!root) {return 0;}
    int l = getMx(root->left), r = getMx(root->right);
    int ret = max(0, max(l, r))+root->val;
    ans = max(ans, max(ret, l+root->val+r));

    return ret;
}

int maxPathSum(TreeNode* root) {
    getMx(root);

    return ans;
}

int main() {

    return 0;
}