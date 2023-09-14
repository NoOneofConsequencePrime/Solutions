#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int cnt = 1;
    for (int i = 1, j = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i-1]) {
            cnt++;
            nums[j] = nums[i];
            j++;
        }
    }

    return cnt;
}

int main() {
    vector<int> a = {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(a) << '\n';
    for (auto& x : a) cout << x << " ";

    return 0;
}