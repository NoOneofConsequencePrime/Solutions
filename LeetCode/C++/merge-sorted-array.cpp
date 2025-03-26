#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> tmp = nums1;
    for (int i = 0, j = 0; i < m || j < n;) {
        if (i < m && j < n) {
            if (tmp[i] < nums2[j]) {
                nums1[i+j] = tmp[i];
                i++;
            } else {
                nums1[i+j] = nums2[j];
                j++;
            }
        } else if (i < m) {
            for (; i < m; i++) nums1[i+j] = tmp[i];
        } else if (j < n) {
            for (; j < n; j++) nums1[i+j] = nums2[j];
        }
    }
}

int main() {
    vector<int> a = {1, 2, 3, 0, 0, 0}, b = {2, 5, 6};
    merge(a, 3, b, 3);
    for (auto& x : a) cout << x << " ";

    return 0;
}