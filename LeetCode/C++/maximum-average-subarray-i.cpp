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

double findMaxAverage(vector<int>& nums, int k) {
    int mx = INT_MIN, sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (i >= k) sum -= nums[i-k];
        if (i >= k-1) mx = max(mx, sum);
    }
    
    return (double)mx/k;
}

int main() {
    vector<int> v = {1,12,-5,-6,50,3};
    cout << findMaxAverage(v, 4);

    return 0;
}