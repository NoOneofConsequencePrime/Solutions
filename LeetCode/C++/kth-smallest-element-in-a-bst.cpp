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

void inOrder(TreeNode* root, vector<int> &v) {
    if (!root) {return;}
    
    inOrder(root->left, v);
    v.push_back(root->val);
    inOrder(root->right, v);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> v;
    inOrder(root, v);
    return v[k-1];
}

int main() {

    return 0;
}