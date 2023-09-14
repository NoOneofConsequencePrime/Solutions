#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int cnt = 0;
    for (int i = 0, j = 0; i < nums.size(); i++) {
        if (nums[i] == val) cnt++;
        else {
            nums[j] = nums[i];
            j++;
        }
    }

    return nums.size()-cnt;
}

int main() {
    vector<int> a = {0,1,2,2,3,0,4,2};
    cout << removeElement(a, 2) << '\n';
    for (auto& x : a) cout << x << " ";

    return 0;
}