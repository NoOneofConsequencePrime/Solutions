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

int sum = 0;

void dfs(TreeNode *node, int mask) {
    if (!node->left && !node->right) {
        sum += (__builtin_popcount(mask) <= 1);
        return;
    }
    
    if (node->left) {dfs(node->left, mask^(1<<node->left->val));}
    if (node->right) {dfs(node->right, mask^(1<<node->right->val));}
}

int pseudoPalindromicPaths (TreeNode* root) {
    dfs(root, 1<<root->val);
    
    return sum;
}

int main() {

    return 0;
}