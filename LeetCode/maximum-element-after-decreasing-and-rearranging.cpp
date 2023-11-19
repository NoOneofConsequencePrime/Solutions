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

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    arr[0] = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i]-arr[i-1] > 1) arr[i] = arr[i-1]+1;
    }
    
    return arr[arr.size()-1];
}

int main() {
    vector<int> v = {2, 2, 1, 2, 1};
    cout << maximumElementAfterDecrementingAndRearranging(v);

    return 0;
}