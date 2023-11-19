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

int reductionOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> freq; unordered_map<int, int> vi;
    for (int& x : nums) {
        if (vi.count(x) == 0) {
            vi[x] = freq.size();
            freq.push_back(1);
        } else freq[vi[x]]++;
    }
    
    int ret = 0;
    for (int i = freq.size()-1, tmp = 0; i >= 0; i--) {
        tmp += freq[i];
        ret += tmp;
    }
    
    return ret-nums.size();
}

int main() {
    vector<int> v = {10,10,10,10,1,10,10,10,10,10};
    cout << reductionOperations(v);

    return 0;
}