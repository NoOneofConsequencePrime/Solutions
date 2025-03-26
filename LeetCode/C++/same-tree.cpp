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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p != !q) return false;
    if (!p && !q) return true;

    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {

    return 0;
}