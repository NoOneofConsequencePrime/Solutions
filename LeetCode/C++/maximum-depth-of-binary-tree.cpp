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

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    queue<pair<TreeNode*, int>> q; q.push({root, 1});
    int ret = INT_MIN;
    while (!q.empty()) {
        auto [curNode, val] = q.front(); q.pop();
        ret = max(ret, val);
        if (curNode->left) {q.push({curNode->left, val+1});}
        if (curNode->right) {q.push({curNode->right, val+1});}
    }

    return ret;
}

int main() {

    return 0;
}