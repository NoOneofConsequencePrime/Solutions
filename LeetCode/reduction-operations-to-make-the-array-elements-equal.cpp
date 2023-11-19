#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
#include <map>
using namespace std;

int reductionOperations(vector<int>& nums) {
    map<int, int, greater<int>> mp;
    for (int& x : nums) mp[x]++;
    
    int ret = 0, tmp = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        tmp += (*it).second;
        ret += tmp;
    }
    
    return ret-nums.size();
}

int main() {
    vector<int> v = {10,10,10,10,1,10,10,10,10,10};
    cout << reductionOperations(v);

    return 0;
}