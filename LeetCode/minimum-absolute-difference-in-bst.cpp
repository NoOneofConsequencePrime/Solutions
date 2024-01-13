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

vector<int> vals;
void inOrder(TreeNode* root) {
    if (root->left) {inOrder(root->left);}
    vals.push_back(root->val);
    if (root->right) {inOrder(root->right);}
}

int getMinimumDifference(TreeNode* root) {
    inOrder(root);
    int ret = INT_MAX;
    for (int i = 1; i < vals.size(); i++) {ret = min(ret, vals[i]-vals[i-1]);}

    return ret;
}

int main() {

    return 0;
}