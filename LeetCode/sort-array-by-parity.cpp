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

bool cmp(int& a, int& b) {
    return a%2 < b%2;
}

vector<int> sortArrayByParity(vector<int>& nums) {
    sort(nums.begin(), nums.end(), cmp);

    return nums;
}

int main() {
    vector<int> v = {3,1,2,4};
    vector<int> ans = sortArrayByParity(v);
    for (int&x : ans) cout << x << " ";

    return 0;
}