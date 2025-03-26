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

int handshake(int n) {
    return (n-1)*n/2;
}

int numIdenticalPairs(vector<int>& nums) {
    int cnt[101]; memset(cnt, 0, sizeof(cnt));
    for (int& x : nums) cnt[x]++;

    int ret = 0;
    for (int i = 1; i <= 100; i++) ret += handshake(cnt[i]);
    
    return ret;
}

int main() {
    vector<int> v = {1,2,3,1,1,3};
    cout << numIdenticalPairs(v);

    return 0;
}