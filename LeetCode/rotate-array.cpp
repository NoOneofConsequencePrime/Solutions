#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    int arr[nums.size()*2];
    for (int i = 0; i < nums.size(); i++) {
        arr[i] = nums[i]; arr[i+nums.size()] = nums[i];
    }
    for (int i = nums.size()-k; i < nums.size()*2-k; i++) nums[i-nums.size()+k] = arr[i];
}

int main() {
    vector<int> v = {1,2,3,4,5,6,7};
    rotate(v, 3);
    for (auto& x : v) cout << x << " ";

    return 0;
}