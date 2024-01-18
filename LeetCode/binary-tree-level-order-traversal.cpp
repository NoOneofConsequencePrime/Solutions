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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (!root) {return ret;}

    queue<pair<TreeNode*, int>> q; q.push({root->left, 1}); q.push({root->right, 1});
    vector<int> tmpV = {root->val};
    int curDep = 0;
    while (!q.empty()) {
        auto [cur, dep] = q.front(); q.pop();
        if (!cur) {continue;}
        if (dep != curDep) {
            curDep++;
            ret.push_back(tmpV);
            tmpV.clear();
        }
        tmpV.push_back(cur->val);

        q.push({cur->left, dep+1}); q.push({cur->right, dep+1});
    }
    ret.push_back(tmpV);

    return ret;
}

int main() {

    return 0;
}