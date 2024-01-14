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

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

unordered_set<int> st;
bool containsDuplicate(vector<int>& nums) {
    for (int x : nums) {
        if (st.count(x) != 0) {return true};
        st.insert(x);
    }

    return false;
}

int main() {

    return 0;
}