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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> v;
    for (int& x : nums1) v.push_back(x);
    for (int& x : nums2) v.push_back(x);
    sort(v.begin(), v.end());
    int n = v.size();

    return (double)(v[n/2]+v[(n-1)/2])/2;
}

int main() {
    vector<int> a = {1, 2}, b = {3, 4};
    cout << findMedianSortedArrays(a, b);

    return 0;
}