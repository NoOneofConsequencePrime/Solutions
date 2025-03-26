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

vector<int> twoSum(vector<int>& numbers, int target) {
    for (int a = 0, b = numbers.size()-1; a < b;) {
        int sum = numbers[a]+numbers[b];
        if (sum == target) return {a+1, b+1};
        else if (sum > target) b--;
        else a++;
    }

    return {-1, -1};
}

int main() {
    vector<int> v = {2,7,11,15};
    vector<int> ans = twoSum(v, 9);
    for (auto x : ans) cout << x << " ";

    return 0;
}