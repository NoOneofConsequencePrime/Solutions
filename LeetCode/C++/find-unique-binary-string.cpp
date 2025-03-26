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

string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size(); string ret (n, ' ');
    for (int i = 0; i < n; i++) ret[i] = (nums[i][i] == '0')? '1':'0';
    
    return ret;
}

int main() {
    vector<string> v = {"111","011","001"};
    cout << findDifferentBinaryString(v);

    return 0;
}