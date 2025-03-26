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

bool cmp(int a, int b) {
    if (__builtin_popcount(a) == __builtin_popcount(b)) return a<b;
    return __builtin_popcount(a)<__builtin_popcount(b);
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