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

const int MM = 5e4+2;
int freq[MM];

int reductionOperations(vector<int>& nums) {
    for (int& x : nums) freq[x]++;
    
    int ret = 0;
    for (int i = MM-1, tmp = 0; i >= 1; i--) {
        if (freq[i] != 0) {
            tmp += freq[i];
            ret += tmp;
        }
    }
    
    return ret - nums.size();
}

int main() {
    vector<int> v = {1,1,2,2,3};
    cout << reductionOperations(v);

    return 0;
}