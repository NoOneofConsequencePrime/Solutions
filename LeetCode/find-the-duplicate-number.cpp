#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
using namespace std;

int findDuplicate(vector<int>& nums) {
    unordered_set<int> st;
    for (int& x : nums) {
        if (st.count(x) > 0) return x;
        else st.insert(x);
    }

    return -1;
}

int main() {
    vector<int> v = {3,1,3,4,2};
    cout << findDuplicate(v);

    return 0;
}