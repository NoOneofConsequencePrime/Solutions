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

vector<int> getLeafSeq(TreeNode* root) {
    vector<int> ret;
    stack<TreeNode*> stk; stk.push(root);
    while (!stk.empty()) {
        TreeNode* cur = stk.top(); stk.pop();
        if (!cur->left && !cur->right) {ret.push_back(cur->val);}
        if (cur->left) {stk.push(cur->left);}
        if (cur->right) {stk.push(cur->right);}
    }

    return ret;
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    vector<int> a = getLeafSeq(root1), b = getLeafSeq(root2);
    
    return a == b;
}

int main() {

    return 0;
}