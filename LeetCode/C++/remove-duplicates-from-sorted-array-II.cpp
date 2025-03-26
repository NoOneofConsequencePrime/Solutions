#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int cnt = 0, j = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (j < 0 || nums[i] != nums[j]) {
            cnt = 1;
            j++;
            nums[j] = nums[i];
        } else if (nums[i] == nums[j] && cnt < 2) {
            cnt++;
            j++;
            nums[j] = nums[i];
        }
    }

    return j+1;
}

int main() {
    vector<int> a = {0,0,1,1,1,1,2,3,3};
    cout << removeDuplicates(a) << '\n';
    for (auto& x : a) cout << x << " ";

    return 0;
}