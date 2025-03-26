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

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    int n = arr.size(), freq[n]; memset(freq, 0, sizeof(freq));
    for (int x : arr) freq[min(x, n)-1]++;

    int mx = n, cnt = 0;
    for (int i = 0; i < mx; i++) {
        cnt += freq[i];
        if (cnt > i+1) {
            mx -= cnt-(i+1);
            cnt = i+1;
        }
    }

    return mx;
}

int main() {
    vector<int> v = {2, 2, 1, 2, 1};
    cout << maximumElementAfterDecrementingAndRearranging(v);

    return 0;
}