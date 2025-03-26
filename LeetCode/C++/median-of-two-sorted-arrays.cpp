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
    int i = 0, j = 0;
    while (true) {
        if (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                v.push_back(nums1[i]);
                i++;
            } else {
                v.push_back(nums2[j]);
                j++;
            }
        } else if (i < nums1.size()) {
            while (i < nums1.size()) {
                v.push_back(nums1[i]);
                i++;
            }
            break;
        } else if (j < nums2.size()) {
            while (j < nums2.size()) {
                v.push_back(nums2[j]);
                j++;
            }
            break;
        } else break;
    }
    int n = v.size();

    return (double)(v[n/2]+v[(n-1)/2])/2;
}

int main() {
    vector<int> a = {1, 2}, b = {3, 4};
    cout << findMedianSortedArrays(a, b);

    return 0;
}