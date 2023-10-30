#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
using namespace std;

int cntBits(int n) {
    if (n == 0) return 0;

    return cntBits(n>>1)+(n&1);
}

bool cmp(int a, int b) {
    if (cntBits(a) == cntBits(b)) return a<b;
    return cntBits(a)<cntBits(b);
}

vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), cmp);

    return arr;
}

int main() {
    vector<int> v = {1024,512,256,128,64,32,16,8,4,2,1};
    sortByBits(v);
    for (auto x : v) cout << x << " ";

    return 0;
}