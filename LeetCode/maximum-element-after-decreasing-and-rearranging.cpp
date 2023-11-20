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
    int n = arr.size(), freq[n+1]; memset(freq, 0, sizeof(freq));
    for (int x : arr) freq[min(x, n)]++;

    int ret = 0;
    for (int i = n; i >= 1; i--) {
        if (freq[i] >= 1) {
            freq[i-1] += freq[i]-1;
            ret++;
        }
    }

    return ret;
}

int main() {
    vector<int> v = {2, 2, 1, 2, 1};
    cout << maximumElementAfterDecrementingAndRearranging(v);

    return 0;
}